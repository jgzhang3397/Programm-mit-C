#include<stdio.h>

int main()
{
    int c, i, nwrite, nother;
    int ndigit[10];

    nwrite = nother = 0;

    //initialization
    for(i=0; i<10; ++i)
        ndigit[i] = 0;
    

    while ((c = getchar())!= EOF)
    {
        if(c >= '0' && c <= '9')
            ++ndigit[c - '0'];//把各个数存放在数组的相应下标位置
        else if (c == ' ' || c == '\t')
            ++nwrite;
        else if(c == '\n')
            break;
        else 
            ++nother;
    }
    
    printf("digits = ");
    for(i=0; i<10; ++i)
        printf(" %d", ndigit[i]);
    printf("\nwrite spade = %d, others = %d\n", nwrite, nother);
    return 0;
}