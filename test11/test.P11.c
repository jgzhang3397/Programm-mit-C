#include<stdio.h>
#include"add.h"
#include"add.c"

// int main()
// {
//     //the total number of characters written is returned. prinf()
//     printf("%d", printf("%d", printf("%d", 56)));
//     return 0;
//}

int main()
{
    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("%d ", sum);
    return 0;
}