#include<stdio.h>

int main()
{
    int ch;
    int count[10] = {0};
    int i = 0;
    int j = 0, k = 0;
    while ((ch = getchar())!= EOF)
    {
        if('a'<= ch && ch <= 'z' || 'A'<=ch && ch <= 'Z')
            ++count[i];
        if(ch == ' ')
            ++i;
        if(ch == '\n')
            break;
    }
    
    for(j=0; j<=i; j++)
    {
        printf("num %d the words lenth: ",  j+1);
        for(k=1; k<=count[j]; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}