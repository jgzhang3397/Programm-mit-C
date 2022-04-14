#include<stdio.h>

void demo01()
{
    int fahr, celsius;
    int lower = 0;
    int upper = 300;
    int step = 20;

    fahr = lower;
    
    while (fahr<=upper)
    {
        celsius = 5 * (fahr-32) / 9;
        // printf("%d\t%d\n", fahr, celsius);
        printf("%3d\t%3d\n", fahr, celsius);
        fahr += step;
    }
}

void demo02()
{
    float fahr, celsius;
    int lower = 0;
    int upper = 300;
    int step = 20;

    fahr = lower;

    while (fahr<=upper)
    {
        celsius = 5.0/9.0*(fahr - 32.0);
        // printf("%d\t%d\n", fahr, celsius);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
}
int main()
{
    //demo01();
    demo02();
    return 0;
}