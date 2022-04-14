#include<stdio.h>

void demo01()
{
    int fahr;
    for(fahr = 0; fahr<=300; fahr += 20)
    {
        printf("%3d\t%3.1f\n", fahr, (5.0/9.0)*(fahr - 32.0));
    }
}

void pre1_5()
{
    int fahr;
    for(fahr = 300; fahr>=0; fahr -= 20)
    {
        printf("%3d\t%3.1f\n", fahr, (5.0/9.0)*(fahr - 32.0));
    }
}

int main()
{
    pre1_5();
    return 0;
}