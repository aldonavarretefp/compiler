%{
#include <math.h>
#import "parserFolder/parser.h"
#include <string.h>
/* 
Programa que lee un programa y hace elreconocimiento de identificadores, 
palabras reservadas y enteros de un lenguaje x

Autor: Navarrete Zamora Aldo Yael
Materia: Compiladores
Escuela: UNAM - Universidad Nacional Autónoma de México
Plantel:  Facultad de Ingeniería
Semestre: Séptimo
Grupo:  3

Descripción:
Elaborar un analizador léxico en lex/flex que reconozca los componentes léxicos pertenecientes a las clases abajo descritas.
*/


/* Definición de estructura para los identificadores */
typedef struct {
        char * name;
        int type;
} ident;

/* Constantes */

const int LENGTHPALRES = 17, LENGTHOPREL = 6;

/* Apuntadores para archivo de salida y registros */
FILE *archSal, *archReg, *archCadenaAtomos;

/* Arreglos dinámico de tamaño inicial 100 para tabla de símbolos, tabla de literales y tabla de reales. */
ident *tablaSimbolos;
float *tablaReales;
char **tablaCadena;
char *tablaPalRes[] = {"alternative", "big", "evaluate", "instead", "large", "loop", "make", "number", "other", "real", "repeat", "select", "small", "step", "stop", "symbol", "throw"};
char tablaPalResAtomos[] = {'a', 'b', 'f', 't', 'g', 'w', 'm', '#', 'o', 'x', 'j', 'h', 'p', 'c', 'q', 'y', 'z'};
char *tablaOpRel[] = {"<",">","<=",">=","==","!="};
char tablaOpRelAtomo[] = {'<','>','l','u','e','d'};
int ptrTS = 0, ptrTL = 0, ptrTR = 0;
int lengthTS = 100, lengthTL = 10, lengthTR = 100;

/* Prototipos de funciones */
void addToChainTable(char* yytext);
void addToRealTable(float yytext);
int addToSymbolTableAndReturnIdx(char *yytext);
int convertOctalToDecimal(char * yytext);
int getIdxPalResfor(char * yytext);
int getIdxOpRel(char * yytext);
void printTablaCadena();
void printTablaReales();
void printTablaSimbolos();
void writeCharToken(int class, char *c);
void writeIntToken(int class, int i);
void writeLexicalError(char* yytext);


%}

saltodelinea    [\n]
espacio         [ ]
constecadena    (\"[^"'\n][^"'\n]+\")|('[^'\n]')|(\"'\")
caracter        [']({let}|{constentera}|{espacio})[']
ident           [\$]({let}|{constentera})+
constentera     [0-9][0-9]*
constreal       [0-9]*\.[0-9]+
palres          alternative|big|evaluate|instead|large|loop|make|number|other|real|repeat|select|small|step|stop|symbol|throw
let             [a-zA-Z]
octal           [Oo][0-7][0-7]*
operrel         <|>|<=|>=|==|!=
operasig        /=
operarit        \+|\-|\*|\/|\%|\\|\^
operadasignacion \=
simboloespecial \[|\]|\(|\)|\{|\}|\,|\:|\;
tabulador       [\t]
palabra         ({let}|{constentera})+

%%
{saltodelinea}          {}
{espacio}               {}
{palres}                {writeIntToken(0, getIdxPalResfor(yytext));}
{ident}                 { writeIntToken(1, addToSymbolTableAndReturnIdx(yytext));}
{constentera}           {writeIntToken(2,atoi(yytext));}
{octal}                 {writeIntToken(2, convertOctalToDecimal(yytext));}
{constreal}             {addToRealTable(atof(yytext)); writeIntToken(3,ptrTR-1);}
{caracter}              {addToChainTable(yytext); writeIntToken(4, ptrTL-1);}
{constecadena}          {addToChainTable(yytext); writeIntToken(4, ptrTL-1);}
{simboloespecial}       {writeCharToken(5, yytext);}
{operarit}              {writeCharToken(6,yytext);}
{operadasignacion}      {writeCharToken(8, yytext);}
{operrel}               {writeIntToken(7, getIdxOpRel(yytext));}
{tabulador}             {}   
{palabra}               {writeLexicalError(yytext);}



%%

void addToChainTable(char* yytext){
        char *c = (char*)malloc(sizeof(char) * (strlen(yytext) + 1));
        strcpy(c, yytext);
        if(ptrTL == lengthTL){
                lengthTL *= 2;
                tablaCadena = realloc(tablaCadena, sizeof(char*) * lengthTL);
        }
        tablaCadena[ptrTL] = c;
        ptrTL++;
}

int addToSymbolTableAndReturnIdx(char* yytext) {
        char *c = calloc(strlen(yytext), sizeof(char));
        for(int i = 0; i < strlen(yytext); i++){
                c[i] = yytext[i];
        }
        for(int i = 0; i < ptrTS; i++){
                char *name = tablaSimbolos[i].name;
                if(strcmp(name, c) == 0){
                        return i;
                }
        }
        if(ptrTS == lengthTS){
                lengthTS *= 2;
                tablaCadena = realloc(tablaCadena, sizeof(char*) * lengthTS);
        }
        tablaSimbolos[ptrTS].name = c;
        tablaSimbolos[ptrTS].type = -1;
        ptrTS++;
        return ptrTS - 1;
}

/* Función para agregar una constante real a la tabla de reales */
void addToRealTable(float yytext){
        if(ptrTR == lengthTR){
                lengthTR *= 2;
                tablaCadena = realloc(tablaCadena, sizeof(char*) * lengthTR);
        }
        tablaReales[ptrTR] = yytext;
        ptrTR++;
}

/* Función para convertir un número octal a decimal */
int convertOctalToDecimal(char * yytext) {
        char *c = malloc(sizeof(char) * (strlen(yytext) - 1));
        for(int i = 0; i < strlen(yytext)-1; i++){
                c[i] = yytext[i+1];
        }
        int n = atoi(c);
        int p = 0, decimal = 0, r;
        while(n>0){
            
            // retrieving the right-most digit of n
            r = n % 10;
            
            // dividing n by 10 to remove the
            // right-most digits since it is already
            // scanned in previous step
            n = n / 10;
            
            decimal = decimal + r * pow( 8 , p );    
            ++p;
            
        }
        
        return decimal;
}

/* Función para obtener el índice de una palabra reservada */
int getIdxPalResfor(char * yytext) {
        for(int i =0 ; i < LENGTHPALRES; i++){
                if(strcmp(yytext, tablaPalRes[i]) == 0){
                        return i;
                }
        }
        return -1;
}

/* Función para obtener el índice de un operador relacional */
int getIdxOpRel(char * yytext) {
        for(int i =0 ; i <= LENGTHOPREL; i++){
                if(strcmp(yytext, tablaOpRel[i]) == 0){
                        return i;
                }
        }
        return -1;
}

/* Función para imprimir la tabla de cadenas */
void printTablaCadena(){
        printf("*** Tabla de Cadenas ***\n-------------------------\n");
        for(int i = 0; i < ptrTL; i++){
                printf("%6d | %s\n",i, tablaCadena[i]);
        }
        printf("\n");
}

/* Función para imprimir la tabla de símbolos */
void printTablaSimbolos(){
        printf("*** Tabla de Simbolos ***\n-------------------------\n");
        for(int i = 0; i < ptrTS; i++){
                printf("%6d | %s\t| %6d\n",i, tablaSimbolos[i].name, tablaSimbolos[i].type);
        }
        printf("\n");
}


/* Función para imprimir la tabla de reales */
void printTablaReales(){
        //Titulo
        printf("*** Tabla de Reales ***\n-------------------------\n");
        for(int i = 0; i < ptrTR; i++){
                printf("%6d | %.2f\n",i, tablaReales[i]);
        }
        printf("\n");
}

/* Función para poner el error léxico en el archivo de registros*/
void writeLexicalError(char* yytext) {
        fprintf(archReg,"%s Es un error léxico\n", yytext);
}

/* Función para poner el token en el archivo de salida*/
void writeCharToken(int class, char* c) {
        fprintf(archCadenaAtomos,"%s",c);
        fprintf(archSal, "(%d,'%s')\n",class,c);
}

/* Función para poner el token en el archivo de salida*/
void writeIntToken(int class, int i) {
        switch(class){
                case 0:
                        fprintf(archCadenaAtomos,"%c", tablaPalResAtomos[i]);
                        break;
                case 1:
                        fprintf(archCadenaAtomos,"i");
                        break;
                case 2:
                        fprintf(archCadenaAtomos,"n");
                        break;
                case 3:
                        fprintf(archCadenaAtomos,"r");
                        break;
                case 4:
                        fprintf(archCadenaAtomos,"s");
                        break;  
                case 7:
                        fprintf(archCadenaAtomos,"%c", tablaOpRelAtomo[i]);
                        break;
                default:
                        break;
        }
        fprintf(archSal,"(%d,%d)\n",class,i);
}

int main(int argc, char *argv[]){

        if (argc == 1){
                printf("Por favor, introduce un archivo de entrada a leer.");
                return 0;
        }

        yyin = fopen(argv[1],"r");
        archSal = fopen("output/lex_an_output.txt","w");
        archReg = fopen("output/lex_an_reg.txt","w");
        archCadenaAtomos = fopen("output/lex_an_cadena_atomos.out","w");


        tablaSimbolos = (ident *)malloc(100*sizeof(ident));                      
        tablaReales   = (float *) malloc(lengthTR*sizeof(float));                
        tablaCadena   = (char **)malloc(lengthTL*sizeof(char *));

        yylex();

        printTablaCadena();
        printTablaSimbolos();
        printTablaReales();
        fclose(archCadenaAtomos);

        parser();

        free(tablaSimbolos);
        free(tablaReales);
        free(tablaCadena);
        fclose(yyin);
        fclose(archSal);
        fclose(archReg);
        fclose(archCadenaAtomos);
} 
