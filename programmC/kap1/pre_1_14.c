#include<stdio.h>

int main()
{
    int ch;
    int count[255]= {0};
    int i, j;
    while ((ch = getchar())!= EOF)
    {
        ++count[ch];
        if(ch == '\n')
            break;
    }
    
    for(i=0; i<=255; i++)
    {
        if(count[i]!= 0)
        {
            if(count[10]!=0 && i == 10)
                printf("\\n:");
            else if(count[16]!=0 && i == 16)
                printf("space: ");
            else 
                printf("%c :", i);

            for(j=1; j<= count[i]; ++j)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}