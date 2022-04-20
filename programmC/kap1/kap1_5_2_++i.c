#include<stdio.h>

void demo01()
{
    long nc;
    nc = 0;
    while (getchar() != EOF)
    {
        ++nc;
    }
    printf("%ld\n", nc);
}

void demo02()
{
    long nc = 0;
    for ( nc = 0; getchar()!=EOF; ++nc)
    {
        getchar();
        printf("%ld\n", nc);
    } 
}

int main()
{
    demo02();
    return 0;
}