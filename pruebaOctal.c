#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

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


int main(int argn, char* argv[]) {
    
    printf("Octal: %s Decimal: %d\n", argv[1], convertOctalToDecimal(argv[1]));
    return 0;
}