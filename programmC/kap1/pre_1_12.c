#include<stdio.h>

int main()
{
    int ch;

    while ((ch = getchar())!= EOF)
    {
        putchar(ch);
        if(ch == ' ')
            printf("\n");
        if(ch == '\n')
            break;
    }
    
    return 0;
}