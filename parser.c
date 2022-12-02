
char c;

void rechaza()
{
    fprintf("rechaza\n");
}

void f(){
    if(c=='c')
}

void decl()
{
    if (c == 'i' || c == 'f' || c == 'h' || c == 'w' || c == 'j' || c == '[' || c == 'z' || c == '}' || c == 't' || c == ':'){
        return;
    }else if(c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x'){
        d();
        decl();
        return;
    }else{
        rechaza();
        return;
    }
}

void cuerpo()
{
    if (c == '}')
    {
        declare();
        listap();
        return;
    }
    else
    {
        rechaza();
        return;
    }
}

void otroparam()
{
    if (c == ',')
    {
        c = getchar();
        tipo();
        if (c == 'i')
        {
            otroparam();
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

void otrafunc()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        func();
        otrafunc();
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

void param()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        tipo();
        if (c == 'i')
        {
            c = getchar();
            otroParam();
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

void func()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        tipo();
        if (c == 'i')
        {
            c = getchar();
            if (c == '(')
            {
                c = getchar();
                param();
                if (c == ')')
                {
                    c = getchar();
                    if (c == '{')
                    {
                        c = getchar();
                        cuerpo();
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

void program()
{
    if (c == 'b' || c == 'g' || c == '#' || c == 'y' || c == 'x')
    {
        func();
        otrafunc();
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
    program();
}

int main()
{
    parser();
    return 0;
}