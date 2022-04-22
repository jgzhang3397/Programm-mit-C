#include<stdio.h>

int main()
{
    int ch;
    while ((ch = getchar())!= EOF)
    {
        putchar(ch);
        if(ch == '\t')
            printf("\\t");
        else if(ch == 16)//16 == del
            printf("\\b");
        else if(ch == 92) // '\'
            printf("\\");
        else if(ch == '\n')
            break;
    }
    
    return 0;
}