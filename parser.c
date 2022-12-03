#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

char c;

void rechaza()
{
    printf("rechaza\n");
}

void OtroArg(){
    if(c==','){
        c = getchar();
        V();
        OtroArg();
        return;
    }else if(c==')'){
        return;
    }else{
        rechaza();
        return;
    }
}

void Arg(){
    if(c==')'){
        return;
    }else if(c=='i' || c=='r' || c=='n' || c=='s'){
        V();
        OtroArg();
        return;
    }else{
        rechaza();
        return;
    }
}

void Llama(){
    if(c=='['){
        c = getchar();
        if(c=='i'){
            c = getchar();
            if(c=='('){
                c = getchar();
                Arg();
                if(c==')'){
                    c = getchar();
                    if(c==']'){
                        c = getchar();
                        return;
                    }else{
                        rechaza();
                        return;
                    }
                }else{
                    rechaza();
                    return;
                }
            }else{
                rechaza();
                return;
            }
        }else{
            rechaza();
            return;
        }
    }else{
        rechaza();
        return;
    }
};

void Valor(){
    if( c =='i' || c=='r' || c=='n' || c=='s'){  
        V();
        return;
    }else if(c==')'){
        return;
    }else{
        rechaza();
        return;
    }
}

void Devuelve(){
    if(c=='z'){
        c = getchar();
        if(c=='('){
            c = getchar();
            Valor();
            if(c==')'){
                c = getchar();
                if(c==';'){
                    c = getchar();
                    return;
                }else{
                    rechaza();
                    return;
                }
            }else{
                rechaza();
                return;
            }
        }else{
            rechaza();
            return;
        }
    }else{
        rechaza();
        return;
    }
}

void U(){
    if(c=='q'){
        c = getchar();
        return;
    }else if(c == 'a' || c == '}' || c == 'o'){
        return;
    }else{
        rechaza();
        return;
    }
}

void Z(){
    if(c=='i'){
        c = getchar();
        if(c=='='){
            c = getchar();
            E();
            if(c==')'){
                return;
            }else{
                rechaza();
                return;
            }
        }else{
            rechaza();
            return;
        }
    }else{
        rechaza();
        return;
    }
}

void H(){
    if(c=='h'){
        c = getchar();
        if(c=='('){
            c = getchar();
            if(c=='i'){
                c = getchar();
                if (c==')'){
                    c = getchar();
                    if(c=='{'){
                        c = getchar();
                        CP();
                        OP();
                        if(c=='}'){
                            c = getchar();
                            return;
                        }else{
                            rechaza();
                            return;
                        }
                    }else{
                        rechaza();
                        return;
                    }
                }else{
                    rechaza();
                    return;
                }
            }else{
                rechaza();
                return;
            }
        }else{
            rechaza();
            return;
        }
    }else{
        rechaza();
        return;
    }
}

void CP(){
    if(c=='a'){
        c = getchar();
        if(c=='n'){
            c = getchar();
            if(c==':'){
                c = getchar();
                ListaP();
                U();
                CP();
                return;
            }else{
                rechaza();
                return;
            }
        }else{
            rechaza();
            return;
        }
    }else if(c=='}' || c=='o'){
        return;
    }else{
        rechaza();
        return;
    }
}

void OP(){
    if(c=='o'){
        c = getchar();
        if(c==':'){
            c = getchar();
            ListaP();
            return;
        }else{
            rechaza();
            return;
        }
    }
    else if(c=='}'){
        return;
    }else{
        rechaza();
        return;
    }
    
}

void X(){
    if(c == 'i' || c == 'n' || c == 'r' || c == 's'){
        R();
        return;
    }else if(c == ';'){
        c = getchar();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void Y(){
    if(c == 'i'){
        c = getchar();
        if(c == '='){
            c = getchar();
            E();
            if(c == ';'){
                c = getchar();
                return;
            }
            else{
                rechaza();
                return;
            }
        }
        else{
            rechaza();
            return;
        }
    }else if(c == ';'){
        c = getchar();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void J(){
    if(c == 'j'){
        c = getchar();
        if( c == '('){
            c = getchar();
            Y();
            X();
            Z();
            if( c == '{'){
                c = getchar();
                ListaP();
                if(c == '}'){
                    c = getchar();
                    return;
                }
                else{
                    rechaza();
                    return;
                }
            }
            else{
                rechaza();
                return;
            }
        }
        else{
            rechaza();
            return;
        }
    }
    else{
        rechaza();
        return;
    }
}

void IP(){
    if( c == 't'){
        c = getchar();
        ListaP();
        return;
    }
    else if(c == ':'){
        return;
    }
    else{
        rechaza();
        return;
    }
}

void I(){
    if(c == 'f'){
        c = getchar();
        if(c == '('){
            c = getchar();
            R();
            if(c == ')'){
                c = getchar();
                ListaP();
                IP();
                if(c == ':'){
                    c = getchar();
                    return;
                }
                else{
                    rechaza();
                    return;
                }
            }
            else{
                rechaza();
                return;
            }
        }
        else{
            rechaza();
            return;
        }
    }
    else{
        rechaza();
        return;
    }
}

void W(){
    if(c=='w'){
        c = getchar();
        if(c=='('){
            c = getchar();
            R();
            if(c==')'){
                c = getchar();
                if(c=='m'){
                    c = getchar();
                    if(c=='{'){
                        c = getchar();
                        ListaP();
                        if(c == '}'){
                            c = getchar();
                            return;
                        }else{
                            rechaza();
                            return;
                        }
                    }else{
                        rechaza();
                        return;
                    }
                }else{
                    rechaza();
                    return;
                }
            }else{
                rechaza();
                return;
            }
        }else{
            rechaza();
            return;
        }
    }else{
        rechaza();
        return;
    }
}

void ListaP(){
    if( c=='}'|| c=='t'|| c==':'|| c=='q'|| c=='a'|| c=='o'){
        return;
    }else if(c=='i' || c=='f' || c=='h' || c=='w' || c=='j' || c=='[' || c=='z' || c=='c'){
        P();
        ListaP();
    }else{
        rechaza();
        return;
    }
}

void P(){
    if(c=='i'){
        A();
        return;        
    }else if(c =='f'){
        I();
        return;        
    }else if(c =='h'){
        H();
        return;
    }else if(c=='w'){
        W();
        return;
    }else if(c=='j'){
        J();
        return;        
    }else if(c=='['){
        Llama();
        return;
    }else if(c=='z'){
        Devuelve();
        return;        
    }else if(c=='c'){
        c = getchar();
        if(c==';'){
            c = getchar();
            return;
        } 
    }else{
        rechaza();
        return;
    }
}

void VPPP(){
    if(c == 's' || c == 'i'){
        c = getchar();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void VPP(){
    if(c == 'r' || c == 'i'){
        c = getchar();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void VP(){
    if(c == 'i' || c == 'n'){
        c = getchar();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void V(){
    if(c == 'i' || c == 'n' || c == 'r' || c == 's'){
        c = getchar();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void RP(){
    if(c == '<' || c == '>' || c == 'l' || c == 'e' || c == 'd' || c == 'u'){
        c = getchar();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void R(){
    if(c == 'i'){
        c = getchar();
        RP();
        V();
        return;
    }
    else if(c == 'n'){
        c = getchar();
        RP();
        VP();
        return;
    }
    else if(c == 'r'){
        c = getchar();
        RP();
        VPP();
        return;
    }
    else if(c == 's'){
        c = getchar();
        RP();
        VPPP();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void F(){
    if(c == '('){
        c = getchar();
        E();
        if(c == ')'){
            c = getchar();
            return;
        }else{
            rechaza();
            return;
        }
    }else if(c == 'i' || c == 'n' || c == 'r'){
        c = getchar();
        return;
    }else if(c == '{'){
        Llama();
        return;
    }else{
        rechaza();
        return;
    }
}

void TP(){
    if(c == '*' || c == '/' || c == '\\' || c == '%'|| c == '^'){
        c = getchar();
        F();
        TP();
    }else if(c == '+'|| c == '-'|| c == ';'){
        return;
    }else{
        rechaza();
        return;
    }
}

void T(){
    if (c == '(' || c == 'i' || c == 'n' || c == 'r' || c == '['){
        F();
        TP();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void EP(){
    if(c == '+' || c == '-'){
        T();
        EP();
        return;
    }
    else if(c == ')' || c == ';'){
        return;
    }
    else{
        rechaza();
        return;
    }
}

void E(){
    if(c == '(' || c == 'i' || c == 'n' || c == 'r' || c == '['){
        T();
        EP();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void AP(){
    if(c == 's'){
        c = getchar();
        return;
    }
    else if(c == '(' || c == 'i' || c == 'n' || c == 'r' || c == '['){
        E();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void A(){
    if(c == 'i'){
        c = getchar();
        if(c == '='){
            c = getchar();
            A();
            if(c == ';'){
                c = getchar();
                return;
            }
            else{
                rechaza();
                return;
            }
        }
        else{
            rechaza();
            return;
        }
    }
    else{
        rechaza();
        return;
    }
}

void C(){
    if(c == ';'){
        return;
    }else if(c == ','){
        c = getchar();
        K();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void N(){
    if(c == 'n' || c == 'r' || c == 's'){
        c = getchar();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void Q(){
    if(c == ';'){
        return;
    }
    else if(c == '='){
        c = getchar();
        N();
        C();
        return;
    }else if(c == ','){
        K();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void K(){
    if(c == 'i'){
        c = getchar();
        Q();
        return;
    }else{
        rechaza();
        return;
    }
}

void Tipo(){
    if(c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x'){
        c = getchar();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void D(){
    if(c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x'){
        Tipo();
        K();
        if (c == ';'){
            c = getchar();
            return;
        }
        else{
            rechaza();
            return;
        }
    }else{
        rechaza();
        return;
    }
}

void Decl()
{
    if (c == 'i' || c == 'f' || c == 'h' || c == 'w' || c == 'j' || c == '[' || c == 'z' || c == '}' || c == 'c'){
        return;
    }else if(c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x'){
        D();
        Decl();
        return;
    }else{
        rechaza();
        return;
    }
}

void Cuerpo()
{
    if (c=='b' || c=='g' || c=='#' || c=='y' || c=='x' || c=='i' || c=='f' || c=='h' || c=='w' || c=='j' || c=='[' || c=='z' || c=='}' || c=='c')
    {
        Decl();
        ListaP();
        return;
    }
    else{
        rechaza();
        return;
    }
}

void Otroparam()
{
    if (c == ',')
    {
        c = getchar();
        Tipo();
        if (c == 'i')
        {
            Otroparam();
            return;
        }
        else
        {
            rechaza();
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
        rechaza();
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
    else if (c == 3)
    {
        return;
    }
    else
    {
        rechaza();
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
            c = getchar();
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
        rechaza();
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
            c = getchar();
            if (c == '(')
            {
                c = getchar();
                Param();
                if (c == ')')
                {
                    c = getchar();
                    if (c == '{')
                    
                    {
                        c = getchar();
                        Cuerpo();
                        if (c == '}')
                        {
                            c = getchar();
                            return;
                        }
                        else
                        {
                            rechaza();
                            return;
                        }
                    }
                    else
                    {
                        rechaza();
                        return;
                    }
                }
                else
                {
                    rechaza();
                    return;
                }
            }
            else
            {
                rechaza();
                return;
            }
        }
        else
        {
            rechaza();
            return;
        }
    }
    else
    {
        rechaza();
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
        rechaza();
        return;
    }
}

void parser()
{
    c = getchar();
    Program();
}
