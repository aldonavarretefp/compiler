#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

char c;
int counter;

FILE * archAtomos;

void rechaza(int count)
{
    printf("SYNTAX ERROR: ATOMO -> %i CHAR -> %i\n", count, c);
}

void OtroArg()
{
    if (c == ',')
    {
        c = fgetc(archAtomos);
        counter++;
        counter++;
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
        printf("Se esperaba el caracter ',' o ')'\n");
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
        printf("Se esperaba el caracter ')' o 'i' o 'r' o 'n' o 's'\n");
        return;
    }
}

void Llama()
{
    if (c == '[')
    {
        c = fgetc(archAtomos);
        counter++;
        counter++;
        if (c == 'i')
        {
            c = fgetc(archAtomos);
            counter++;
            counter++;
            if (c == '(')
            {
                c = fgetc(archAtomos);
                counter++;
                Arg();
                if (c == ')')
                {
                    c = fgetc(archAtomos);
                    counter++;
                    if (c == ']')
                    {
                        c = fgetc(archAtomos);
                        counter++;
                        return;
                    }
                    else
                    {
                        rechaza(counter);
                        printf("Se esperaba el caracter ']'\n");
                        return;
                    }
                }
                else
                {
                    rechaza(counter);
                    printf("Se esperaba el caracter ')'\n");
                    return;
                }
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter '('\n");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter 'i'\n");
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter '['\n");
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
        printf("Se esperaba el caracter 'i' o 'r' o 'n' o 's' o ')'\n");
        return;
    }
}

void Devuelve()
{
    if (c == 'z')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == '(')
        {
            c = fgetc(archAtomos);
            counter++;
            Valor();
            if (c == ')')
            {
                c = fgetc(archAtomos);
                counter++;
                if (c == ';')
                {
                    c = fgetc(archAtomos);
                    counter++;
                    return;
                }
                else
                {
                    rechaza(counter);
                    printf("Se esperaba el caracter ';'\n");
                    return;
                }
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter ')'\n");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter '('\n");
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'z'\n");
        return;
    }
}

void U()
{
    if (c == 'q')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else if (c == 'a' || c == '}' || c == 'o')
    {
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'q' o 'a' o '}' o 'o'\n");
        return;
    }
}

void Z()
{
    if (c == 'i')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == '=')
        {
            c = fgetc(archAtomos);
            counter++;
            E();
            if (c == ')')
            {
                c = fgetc(archAtomos);
                counter++;
                return;
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter ')'");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter '='");
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
        printf("Se esperaba el caracter 'i' o ')'");
        return;
    }
}

void H()
{
    if (c == 'h')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == '(')
        {
            c = fgetc(archAtomos);
            counter++;
            if (c == 'i')
            {
                c = fgetc(archAtomos);
                counter++;
                if (c == ')')
                {
                    c = fgetc(archAtomos);
                    counter++;
                    if (c == '{')
                    {
                        c = fgetc(archAtomos);
                        counter++;
                        CP();
                        OP();
                        if (c == '}')
                        {
                            c = fgetc(archAtomos);
                            counter++;
                            return;
                        }
                        else
                        {
                            rechaza(counter);
                            printf("Se esperaba el caracter ");
                            return;
                        }
                    }
                    else
                    {
                        rechaza(counter);
                        printf("Se esperaba el caracter ");
                        return;
                    }
                }
                else
                {
                    rechaza(counter);
                    printf("Se esperaba el caracter ");
                    return;
                }
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter ");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter ");
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter ");
        return;
    }
}

void CP()
{
    if (c == 'a')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == 'n')
        {
            c = fgetc(archAtomos);
            counter++;
            if (c == ':')
            {
                c = fgetc(archAtomos);
                counter++;
                ListaP();
                U();
                CP();
                return;
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter ");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter ");
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
        printf("Se esperaba el caracter ");
        return;
    }
}

void OP()
{
    if (c == 'o')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == ':')
        {
            c = fgetc(archAtomos);
            counter++;
            ListaP();
            return;
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter ':'\n");
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
        printf("Se esperaba el caracter '}'\n");
        return;
    }
}

void X()
{
    if (c == 'i' || c == 'n' || c == 'r' || c == 's')
    {
        R();
        if (c == ';')
        {
            c = fgetc(archAtomos);
            counter++;
            return;
        }
        return;
    }
    else if (c == ';')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'i' o 'n' o 'r' o 's' o ';'\n");
        return;
    }
}

void Y()
{
    if (c == 'i')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == '=')
        {
            c = fgetc(archAtomos);
            counter++;
            E();
            if (c == ';')
            {
                c = fgetc(archAtomos);
                counter++;
                return;
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter ';'\n");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter '='\n");
            return;
        }
    }
    else if (c == ';')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'i' o ';'\n");
        return;
    }
}

void J()
{
    if (c == 'j')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == '(')
        {
            c = fgetc(archAtomos);
            counter++;
            Y();
            X();
            Z();
            if (c == '{')
            {
                c = fgetc(archAtomos);
                counter++;
                ListaP();
                if (c == '}')
                {
                    c = fgetc(archAtomos);
                    counter++;
                    return;
                }
                else
                {
                    rechaza(counter);
                    printf("Se esperaba el caracter '}'\n");
                    return;
                }
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter '{'\n");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter '('\n");
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'j'\n");
        return;
    }
}

void IP()
{
    if (c == 't')
    {
        c = fgetc(archAtomos);
        counter++;
        ListaP();
        return;
    }
    else if (c == ':')
    {
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 't' o ':'\n");
        return;
    }
}

void I()
{
    if (c == 'f')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == '(')
        {
            c = fgetc(archAtomos);
            counter++;
            R();
            if (c == ')')
            {
                c = fgetc(archAtomos);
                counter++;
                ListaP();
                IP();
                if (c == ':')
                {
                    c = fgetc(archAtomos);
                    counter++;
                    return;
                }
                else
                {
                    rechaza(counter);
                    printf("Se esperaba el caracter ':'\n");
                    return;
                }
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter ')'\n");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter '('\n");
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter ");
        return;
    }
}

void W()
{
    if (c == 'w')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == '(')
        {
            c = fgetc(archAtomos);
            counter++;
            R();
            if (c == ')')
            {
                c = fgetc(archAtomos);
                counter++;
                if (c == 'm')
                {
                    c = fgetc(archAtomos);
                    counter++;
                    if (c == '{')
                    {
                        c = fgetc(archAtomos);
                        counter++;
                        ListaP();
                        if (c == '}')
                        {
                            c = fgetc(archAtomos);
                            counter++;
                            return;
                        }
                        else
                        {
                            rechaza(counter);
                            printf("Se esperaba el caracter '}'\n");
                            return;
                        }
                    }
                    else
                    {
                        rechaza(counter);
                        printf("Se esperaba el caracter '{'\n");
                        return;
                    }
                }
                else
                {
                    rechaza(counter);
                    printf("Se esperaba el caracter 'm'\n");
                    return;
                }
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter ')'\n");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter '('\n");
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'w'\n");
        return;
    }
}

void ListaP()
{
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
        printf("Se esperaba el caracter 'i' o 'f' o 'h' o 'w' o 'j' o '[' o 'z' o 'c' o '}' o 't' o ':' o 'q' o 'a' o 'o'\n");
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
        c = fgetc(archAtomos);
        counter++;
        if (c == ';')
        {
            c = fgetc(archAtomos);
            counter++;
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'i' o 'f' o 'h' o 'w' o 'j' o '[' o 'z' o 'c'\n");
        return;
    }
}

void VPPP()
{
    if (c == 's' || c == 'i')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 's' o 'i' \n");
        return;
    }
}

void VPP()
{
    if (c == 'r' || c == 'i')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'r' o 'i' \n");
        return;
    }
}

void VP()
{
    if (c == 'i' || c == 'n')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'i' o 'n' \n");
        return;
    }
}

void V()
{
    if (c == 'i' || c == 'n' || c == 'r' || c == 's')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'i' o 'n' o 'r' 's' \n");
        return;
    }
}

void RP()
{
    if (c == '<' || c == '>' || c == 'l' || c == 'e' || c == 'd' || c == 'u')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter '<' o '>' o 'l' o 'e' o 'd' o 'u' \n");
        return;
    }
}

void R()
{
    if (c == 'i')
    {
        c = fgetc(archAtomos);
        counter++;
        RP();
        V();
        return;
    }
    else if (c == 'n')
    {
        c = fgetc(archAtomos);
        counter++;
        RP();
        VP();
        return;
    }
    else if (c == 'r')
    {
        c = fgetc(archAtomos);
        counter++;
        RP();
        VPP();
        return;
    }
    else if (c == 's')
    {
        c = fgetc(archAtomos);
        counter++;
        RP();
        VPPP();
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'i' o 'n' o 'r' o 's' \n");
        return;
    }
}

void F()
{
    if (c == '(')
    {
        c = fgetc(archAtomos);
        counter++;
        E();
        if (c == ')')
        {
            c = fgetc(archAtomos);
            counter++;
            return;
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter ')' \n");
            return;
        }
    }
    else if (c == 'i' || c == 'n' || c == 'r')
    {
        c = fgetc(archAtomos);
        counter++;
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
        printf("Se esperaba el caracter 'i' o 'n' o 'r' o '(' o '[' \n");
        return;
    }
}

void TP()
{
    if (c == '*' || c == '/' || c == '\\' || c == '%' || c == '^')
    {
        c = fgetc(archAtomos);
        counter++;
        F();
        TP();
    }
    else if (c == '+' || c == '-' || c == ';' || c == ')')
    {
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter '*' o '/' o '\\' o '%%' o '^' o '+' o '-' o ';' o ')' \n");
        return;
    }
}

void T()
{
    if (c == '(' || c == 'i' || c == 'n' || c == 'r' || c == '[')
    {
        F();
        TP();
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter '(' o 'i' o 'n' o 'r' o '[' \n");
        return;
    }
}

void EP()
{
    if (c == '+' || c == '-')
    {
        c = fgetc(archAtomos);
        counter++;
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
        printf("Se esperaba el caracter '+' o '-' o ')' o ';' \n");
        return;
    }
}

void E()
{
    if (c == '(' || c == 'i' || c == 'n' || c == 'r' || c == '[')
    {
        T();
        EP();
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter '(' o 'i' o 'n' o 'r' o '[' \n");
        return;
    }
}

void AP()
{
    if (c == 's')
    {
        c = fgetc(archAtomos);
        counter++;
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
        printf("Se esperaba el caracter 's' o '(' o 'i' o 'n' o 'r' o '[' \n");
        return;
    }
}

void A()
{
    if (c == 'i')
    {
        c = fgetc(archAtomos);
        counter++;
        if (c == '=')
        {
            c = fgetc(archAtomos);
            counter++;
            AP();
            if (c == ';')
            {
                c = fgetc(archAtomos);
                counter++;
                return;
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter ';' \n");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter '=' \n");
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'i' \n");
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
        c = fgetc(archAtomos);
        counter++;
        K();
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter ';' o ',' \n");
        return;
    }
}

void N()
{
    if (c == 'n' || c == 'r' || c == 's')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'n' o 'r' o 's' \n");
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
        c = fgetc(archAtomos);
        counter++;
        N();
        C();
        return;
    }
    else if (c == ',')
    {
        c = fgetc(archAtomos);
        counter++;
        K();
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter ';' o '=' o ',' \n");
        return;
    }
}

void K()
{
    if (c == 'i')
    {
        c = fgetc(archAtomos);
        counter++;
        Q();
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'i' \n");
        return;
    }
}

void Tipo()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        c = fgetc(archAtomos);
        counter++;
        return;
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'b' o 'g' o '#' o 'y' o 'x'\n");
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
            c = fgetc(archAtomos);
            counter++;
            return;
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter ';' \n");
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'b' o 'g' o '#' o 'y' o 'x'\n");
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
        printf("Se esperaba el caracter 'i' o 'f' o 'h' o 'w' o 'j' o '[' o 'z' o '}' o 'c' o 'b' o 'g' o '#' o 'y' o 'x' \n");
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
        printf("Se esperaba el caracter 'b' o 'g' o '#' o 'y' o 'x' o 'i' o 'f' o 'h' o 'w' o 'j' o '[' o 'z' o '}' o 'c' \n");
        return;
    }
}

void Otroparam()
{
    if (c == ',')
    {
        c = fgetc(archAtomos);
        counter++;
        Tipo();
        if (c == 'i')
        {
            Otroparam();
            return;
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter 'i' \n");
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
        printf("Se esperaba el caracter ',' o ')' \n");
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
        printf("Se esperaba el caracter 'b' o 'g' o '#' o 'y' o 'x'\n");
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
            c = fgetc(archAtomos);
            counter++;
            Otroparam();
            return;
        }else{
            rechaza(counter);
            printf("Se esperaba el caracter 'i'\n");
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
        printf("Se esperaba el caracter 'b' o 'g' o '#' o 'y' o 'x' o ')' \n");
        return;
    }
}

void Func()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        Tipo();
        if (c == 'i')
        {
            c = fgetc(archAtomos);
            counter++;
            if (c == '(')
            {
                c = fgetc(archAtomos);
                counter++;
                Param();
                if (c == ')')
                {
                    c = fgetc(archAtomos);
                    counter++;
                    if (c == '{')

                    {
                        c = fgetc(archAtomos);
                        counter++;
                        Cuerpo();
                        if (c == '}')
                        {
                            c = fgetc(archAtomos);
                            counter++;
                            return;
                        }
                        else
                        {
                            rechaza(counter);
                            printf("Se esperaba el caracter '}'\n");
                            return;
                        }
                    }
                    else
                    {
                        rechaza(counter);
                        printf("Se esperaba el caracter '{' \n");
                        return;
                    }
                }
                else
                {
                    rechaza(counter);
                    printf("Se esperaba el caracter ')'\n");
                    return;
                }
            }
            else
            {
                rechaza(counter);
                printf("Se esperaba el caracter '('\n");
                return;
            }
        }
        else
        {
            rechaza(counter);
            printf("Se esperaba el caracter 'i'\n");
            return;
        }
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el caracter 'b' o 'g' o '#' o 'y' o 'x'\n");
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
        printf("Se esperaba el caracter 'b' o 'g' o '#' o 'y' o 'x'\n");
        return;
    }
}

void parser(FILE *arch)
{
    //freopen("output/lex_an_cadena_atomos.out", "r", stdin);
    archAtomos = arch;
    freopen("output/parser.out", "w", stdout);
    c = fgetc(archAtomos);
    //set buffer at the beginning of the file
    fpos_t pos;
    printf("pos: %d\n",fgetpos(archAtomos, &pos));
    counter++;
    Program();
    if (c == -1)
    {
        printf("Programa sintácticamente correcto!");
        printf("counter: %d\n", counter);
    }
    else
    {
        rechaza(counter);
        printf("Se esperaba el fin de cadena \n");
        return;
    }
    fclose(stdin);
    fclose(stdout);
}

