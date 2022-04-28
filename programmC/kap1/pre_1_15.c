#include<stdio.h>
//重新温度转换
#define LOWER 0
#define UPPER 300
#define STEP 20

float t_Transform(float fahr);
void t_Transform_v2(float fahr, float celsius);

int main()
{
    float fahr, celsius;
    fahr = LOWER;

    // while (fahr <= UPPER)
    // {
    //     celsius = t_Transform(fahr);

    //     printf("fahr= %3.0f\tcelsius= %6.1f\n", fahr, celsius);
    //     fahr += STEP;
    // }
    
    t_Transform_v2(fahr, celsius);
    return 0;
}

float t_Transform(float fahr)
{
    float celsius;
    celsius = 5.0/9.0*(fahr - 32.0);
    return celsius;
}

void t_Transform_v2(float fahr, float celsius)
{

    for(fahr = LOWER; fahr<=UPPER; fahr+=STEP)
    {
        celsius = t_Transform(fahr);

        printf("fahr= %3.0f\tcelsius= %6.1f\n", fahr, celsius);
    }
}