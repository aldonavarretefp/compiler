#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

char c;
int counter;

void rechaza(int count)
{
    printf("Error sintáctico en átomo número %i: %i\n",count, c);
}

void OtroArg()
{
    if (c == ',')
    {
        c = getchar(); counter++; counter++;
        V();
        OtroArg();
        return;
    }
    else if (c == ')')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Arg()
{
    if (c == ')')
    {
        return;
    }
    else if (c == 'i' || c == 'r' || c == 'n' || c == 's')
    {
        V();
        OtroArg();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Llama()
{
    if (c == '[')
    {
        c = getchar(); counter++; counter++;
        if (c == 'i')
        {
            c = getchar(); counter++; counter++;
            if (c == '(')
            {
                c = getchar(); counter++;
                Arg();
                if (c == ')')
                {
                    c = getchar(); counter++;
                    if (c == ']')
                    {
                        c = getchar(); counter++;
                        return;
                    }
                    else
                    {
                        rechaza(counter); 
                        return;
                    }
                }
                else
                {
                    rechaza(counter); 
                    return;
                }
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else
    {
        rechaza(counter); 
        return;
    }
};

void Valor()
{
    if (c == 'i' || c == 'r' || c == 'n' || c == 's')
    {
        V();
        return;
    }
    else if (c == ')')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Devuelve()
{
    if (c == 'z')
    {
        c = getchar(); counter++;
        if (c == '(')
        {
            c = getchar(); counter++;
            Valor();
            if (c == ')')
            {
                c = getchar(); counter++;
                if (c == ';')
                {
                    c = getchar(); counter++;
                    return;
                }
                else
                {
                    rechaza(counter); 
                    return;
                }
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void U()
{
    if(counter >55) printf("%c %i\n", c, counter);
    if (c == 'q')
    {
        c = getchar(); counter++;
        return;
    }
    else if (c == 'a' || c == '}' || c == 'o')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Z()
{
    if(counter >80) printf("Z %c %i\n", c, counter);
    if (c == 'i')
    {
        c = getchar(); counter++;
        if (c == '=')
        {
            c = getchar(); counter++;
            E();
            if (c == ')')
            {
                c = getchar(); counter++;
                return;
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else if(c==')')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void H()
{
    if (c == 'h')
    {
        c = getchar(); counter++;
        if (c == '(')
        {
            c = getchar(); counter++;
            if (c == 'i')
            {
                c = getchar(); counter++;
                if (c == ')')
                {
                    c = getchar(); counter++;
                    if (c == '{')
                    {
                        c = getchar(); counter++;
                        CP();
                        OP();
                        if (c == '}')
                        {
                            c = getchar(); counter++;
                            return;
                        }
                        else
                        {
                            rechaza(counter); 
                            return;
                        }
                    }
                    else
                    {
                        rechaza(counter); 
                        return;
                    }
                }
                else
                {
                    rechaza(counter); 
                    return;
                }
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void CP()
{
    if (c == 'a')
    {
        c = getchar(); counter++;
        if (c == 'n')
        {
            c = getchar(); counter++;
            if (c == ':')
            {
                c = getchar(); counter++;
                ListaP();
                U();
                CP();
                return;
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else if (c == '}' || c == 'o')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void OP()
{
    if (c == 'o')
    {
        c = getchar(); counter++;
        if (c == ':')
        {
            c = getchar(); counter++;
            ListaP();
            if(counter >55) printf("OP %c %i\n", c, counter);
            return;
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else if (c == '}')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void X()
{   
    if(counter >80) printf("X %c %i\n", c, counter);
    if (c == 'i' || c == 'n' || c == 'r' || c == 's')
    {
        R();
        if(c==';'){
            c = getchar(); counter++;
            return;
        }
        return;
    }
    else if (c == ';')
    {
        c = getchar(); counter++;
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Y()
{
    if(counter >55) printf("Y %c %i\n", c, counter);
    if (c == 'i')
    {
        c = getchar(); counter++;
        if (c == '=')
        {
            c = getchar(); counter++;
            E();
            if (c == ';')
            {
                c = getchar(); counter++;
                return;
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else if (c == ';')
    {
        c = getchar(); counter++;
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void J()
{
    if (c == 'j')
    {
        c = getchar(); counter++;
        if (c == '(')
        {
            c = getchar(); counter++;
            Y();
            X();
            Z();
            if (c == '{')
            {
                c = getchar(); counter++;
                ListaP();
                if (c == '}')
                {
                    c = getchar(); counter++;
                    return;
                }
                else
                {
                    rechaza(counter); 
                    return;
                }
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void IP()
{
    if (c == 't')
    {
        c = getchar(); counter++;
        ListaP();
        if(counter >55) printf("IP %c %i\n", c, counter);
        return;
    }
    else if (c == ':')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void I()
{
    if (c == 'f')
    {
        c = getchar(); counter++;
        if (c == '(')
        {
            c = getchar(); counter++;
            R();
            if (c == ')')
            {
                c = getchar(); counter++;
                ListaP();
                IP();
                if (c == ':')
                {
                    c = getchar(); counter++;
                    return;
                }
                else
                {
                    rechaza(counter); 
                    return;
                }
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void W()
{
    if (c == 'w')
    {
        c = getchar(); counter++;
        if (c == '(')
        {
            c = getchar(); counter++;
            R();
            if (c == ')')
            {
                c = getchar(); counter++;
                if (c == 'm')
                {
                    c = getchar(); counter++;
                    if (c == '{')
                    {
                        c = getchar(); counter++;
                        ListaP();
                        if (c == '}')
                        {
                            c = getchar(); counter++;
                            return;
                        }
                        else
                        {
                            rechaza(counter); 
                            return;
                        }
                    }
                    else
                    {
                        rechaza(counter); 
                        return;
                    }
                }
                else
                {
                    rechaza(counter); 
                    return;
                }
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void ListaP()
{
    if(counter >55) printf("LisP %c %i\n", c, counter);
    if (c == '}' || c == 't' || c == ':' || c == 'q' || c == 'a' || c == 'o')
    {
        return;
    }
    else if (c == 'i' || c == 'f' || c == 'h' || c == 'w' || c == 'j' || c == '[' || c == 'z' || c == 'c')
    {
        P();
        ListaP();
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void P()
{
    if (c == 'i')
    {
        A();
        return;
    }
    else if (c == 'f')
    {
        I();
        return;
    }
    else if (c == 'h')
    {
        H();
        return;
    }
    else if (c == 'w')
    {
        W();
        return;
    }
    else if (c == 'j')
    {
        J();
        return;
    }
    else if (c == '[')
    {
        Llama();
        return;
    }
    else if (c == 'z')
    {
        Devuelve();
        return;
    }
    else if (c == 'c')
    {
        c = getchar(); counter++;
        if (c == ';')
        {
            c = getchar(); counter++;
            return;
        }
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void VPPP()
{
    if (c == 's' || c == 'i')
    {
        c = getchar(); counter++;
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void VPP()
{
    if (c == 'r' || c == 'i')
    {
        c = getchar(); counter++;
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void VP()
{
    if (c == 'i' || c == 'n')
    {
        c = getchar(); counter++;
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void V()
{
    if(counter >80) printf("V %c %i\n", c, counter);
    if (c == 'i' || c == 'n' || c == 'r' || c == 's')
    {
        c = getchar(); counter++;
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void RP()
{
    if (c == '<' || c == '>' || c == 'l' || c == 'e' || c == 'd' || c == 'u')
    {
        c = getchar(); counter++;
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void R()
{
    if(counter >55) printf("R %c %i\n", c, counter);
    if (c == 'i')
    {
        c = getchar(); counter++;
        RP();
        V();
        return;
    }
    else if (c == 'n')
    {
        c = getchar(); counter++;
        RP();
        VP();
        return;
    }
    else if (c == 'r')
    {
        c = getchar(); counter++;
        RP();
        VPP();
        return;
    }
    else if (c == 's')
    {
        c = getchar(); counter++;
        RP();
        VPPP();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void F()
{
    if(counter >55) printf("F %c %i\n", c, counter);
    if (c == '(')
    {
        c = getchar(); counter++;
        E();
        if(counter >55) printf("F %c %i\n", c, counter);
        if (c == ')')
        {
            c = getchar(); counter++;
            return;
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else if (c == 'i' || c == 'n' || c == 'r')
    {
        c = getchar(); counter++;
        return;
    }
    else if (c == '[')
    {
        Llama();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void TP()
{
    if(counter >55) printf("TP %c %i\n", c, counter);
    if (c == '*' || c == '/' || c == '\\' || c == '%' || c == '^')
    {
        c = getchar(); counter++;
        F();
        TP();
    }
    else if (c == '+' || c == '-' || c == ';' || c==')')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void T()
{
    if(counter >55) printf("T %c %i\n", c, counter);
    if (c == '(' || c == 'i' || c == 'n' || c == 'r' || c == '[')
    {
        F();
        TP();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void EP()
{
    if(counter >55) printf("EP %c %i\n", c, counter);
    if (c == '+' || c == '-')
    {
        c = getchar(); counter++;
        T();
        EP();
        return;
    }
    else if (c == ')' || c == ';')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void E()
{
    if(counter >85) printf("E %c %i\n", c, counter);
    if (c == '(' || c == 'i' || c == 'n' || c == 'r' || c == '[')
    {
        T();
        EP();
        printf("E %c %i\n", c, counter);
        return;
    }else
    {
        rechaza(counter); 
        return;
    }
}

void AP()
{
    if(counter >55) printf("AP%c %i\n", c, counter);
    if (c == 's')
    {
        c = getchar(); counter++;
        return;
    }
    else if (c == '(' || c == 'i' || c == 'n' || c == 'r' || c == '[')
    {
        E();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void A()
{
    if (c == 'i')
    {
        c = getchar(); counter++;
        if (c == '=')
        {
            c = getchar(); counter++;
            AP();
            if (c == ';')
            {
                c = getchar(); counter++;
                return;
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void C()
{
    if (c == ';')
    {
        return;
    }
    else if (c == ',')
    {
        c = getchar(); counter++;
        K();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void N()
{
    if (c == 'n' || c == 'r' || c == 's')
    {
        c = getchar(); counter++;
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Q()
{
    if (c == ';')
    {
        return;
    }
    else if (c == '=')
    {
        c = getchar(); counter++;
        N();
        C();
        return;
    }
    else if (c == ',')
    {
        c = getchar(); counter++;
        K();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void K()
{
    if (c == 'i')
    {
        c = getchar(); counter++;
        Q();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Tipo()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        c = getchar(); counter++;
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void D()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        Tipo();
        K();
        if (c == ';')
        {
            c = getchar(); counter++;
            return;
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Decl()
{
    if (c == 'i' || c == 'f' || c == 'h' || c == 'w' || c == 'j' || c == '[' || c == 'z' || c == '}' || c == 'c')
    {
        return;
    }
    else if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        D();
        Decl();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Cuerpo()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x' || c == 'i' || c == 'f' || c == 'h' || c == 'w' || c == 'j' || c == '[' || c == 'z' || c == '}' || c == 'c')
    {
        Decl();
        ListaP();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Otroparam()
{
    if (c == ',')
    {
        c = getchar(); counter++;
        Tipo();
        if (c == 'i')
        {
            Otroparam();
            return;
        }
        else
        {
            rechaza(counter); 
            return;
        }
        return;
    }
    else if (c == ')')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Otrafunc()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        Func();
        Otrafunc();
        return;
    }
    else if (c == -1)
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Param()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        Tipo();
        if (c == 'i')
        {
            c = getchar(); counter++;
            Otroparam();
            return;
        }
    }
    else if (c == ')')
    {
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void Func()
{
    printf("Func %c %i\n", c, counter);
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        Tipo();
        if (c == 'i')
        {
            c = getchar(); counter++;
            if (c == '(')
            {
                c = getchar(); counter++;
                Param();
                if (c == ')')
                {
                    c = getchar(); counter++;
                    if (c == '{')

                    {
                        c = getchar(); counter++;
                        Cuerpo();
                        if (c == '}')
                        {
                            c = getchar(); counter++;
                            return;
                        }
                        else
                        {
                            rechaza(counter); 
                            return;
                        }
                    }
                    else
                    {
                        rechaza(counter); 
                        return;
                    }
                }
                else
                {
                    rechaza(counter); 
                    return;
                }
            }
            else
            {
                rechaza(counter); 
                return;
            }
        }
        else
        {
            rechaza(counter); 
            return;
        }
    }
    else
    {
        printf("Error en la linea %d: Se esperaba un tipo de dato\n", counter);
        rechaza(counter); 
        return;
    }
}

void Program()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        Func();
        Otrafunc();
        return;
    }
    else
    {
        rechaza(counter); 
        return;
    }
}

void parser()
{
    freopen("lex_an_cadena_atomos.out", "r", stdin);
    freopen("parser.out", "w", stdout);
    fseek(stdin, 0, 0);
    c = getchar(); counter++;
    printf("Program %c %i\n", c, counter); 
    Program();
    if (c == -1 )
    {
        printf("Aceptado!");
    }
    else
    {
        rechaza(counter); 
        return;
    }
    fclose(stdin);
    fclose(stdout);
}

int main(){
    parser();
    return 0;
}

