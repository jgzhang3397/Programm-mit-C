#include<stdio.h>

int main()
{
    int year = 0;
    scanf("%d", &year);

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("this is leap year\n");
    else
        printf("this is not leap year\n");

    return 0;
}   