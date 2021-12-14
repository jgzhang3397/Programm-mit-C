#include<stdio.h>
// //Funktionsrekursion
// //z.B.接受一个整数值（无符号），按照顺序打印他的每一位，例如：输入：1234， 输出：1 2 3 4
// void print(int num)
// {
//     if(num>9)
//     {
//         print(num/10);
//     }
//     printf("%d ", num%10);
// }
// int main()
// {
//     unsigned int num = 0;
//     printf("Bitte geben Sie eine Value ein:>");
//     scanf("%d", &num);
//     print(num);
//     return 0;
// }

// // #include<string.h>
// // int my_strlen(char* arr)
// // {
// //     int count = 0;
// //     while (*arr != '\0')
// //     {
// //         count++;
// //         arr++;
// //     }
// //     return count;
// // }
// //Verwendung mit Rekursion
// //把大事化小
// //my_strlen("bit")
// //1+my_strlen("it")
// //1+1+my_strlen("t");
// //1+1+1+0
// int my_strlen(char* arr)
// {
//     if(*arr != '\0')
//     {
//         return 1+my_strlen(arr+1);
//     }
//     else
//     {
//         return 0;
//     }
// }
// int main()
// {
//     char arr[] ="Hola";
//     // int len = strlen(arr);
//     // printf("Sum des Arrays: %d ", len);
//     int len = my_strlen(arr);
//     printf("Sum des Arrays: %d ", len);
//     return 0;
// }

// //求n的阶乘
// //factorial -n
// int fac1(int n)
// {
//     int i = 0;
//     int result = 1;
//     for(i=1; i<=n; i++)
//     {
//         result *= i;
//     }
//     return result;
// }
// //mit Rekursion
// int fac2(int n)
// {
//     if(n<=1)
//        return 1;
//     else
//        return n*fac2(n-1);
// }
// int main()
// {
//     int n = 0;
//     int result = 0;
//     printf("Bitte geben Sie eine Value ein:>");
//     scanf("%d", &n);
//     result = fac1(n);
//     printf("mit loop :%d\n", result);
//     result = fac2(n);
//     printf("mit Rekursion :%d\n", result);
//     return 0;
// }

// //斐波那契数(Fibonacci sequence)
// //Fib(0)=0
// //Fib(1)=1
// //Fib(n)=Fib(n-1)+Fib(n-2)(n>=2)
// //Es dauer so lange
// // int Fib(int n)
// // {
// //     if(n>=2)
// //     {
// //         return (Fib(n-1)+Fib(n-2));
// //     }
// //     else 
// //     {
// //         return n;
// //     }
// // }
// //Optimierung
// int Fib(int n)
// {
//     int a = 1;
//     int b = 1;
//     int c = 1;
//     while(n>2)
//     {
//         c = a+b;
//         a = b;
//         b = c;
//         n--;
//     }
//     return c;
// }
// int main()
// {
//     int result = 0;
//     int n = 0;
//     printf("Bitte geben Sie eine Value ein n:>");
//     scanf("%d", &n);
//     result = Fib(n);
//     printf("%d ", result);
//     return 0;
// }

// Ähnliche Frage 青蛙跳台阶 jump_floor
// int jump_floor(int n)
// {
//     if(n>3)
//     {
//         return jump_floor(n-1)+jump_floor(n-2);
//     }
//     else
//     {
//         return n;
//     }
// }
int jump_floor(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;
    while (n>=2)
    {
        c = a+b;
        a = b;
        b = c;
        n--;
    }
    return c;
    
}
int main()
{
    int n = 0;
    int ret = 0;
    printf("Bitte geben Sie die Value von Floor ein:>");
    scanf("%d", &n);
    ret = jump_floor(n);
    printf("Insgamt %d : mal Jump\n", ret);
}