#include<stdio.h>

int main()
{
    long  spa=0, tab=0, ret = 0;
    int nl;
    while ((nl = getchar())!= EOF)
    {
        if(nl == ' ')
            ++spa;
        else if(nl == '\t')
            ++tab;
        else if(nl == '\n')
        {
            ++ret;
            break;
        }      
    }
    printf("%ld\t%ld\t%ld\n", spa, tab, ret);
    return 0;
}