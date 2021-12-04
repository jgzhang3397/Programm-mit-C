#include <stdio.h>
#include <string.h>
int main()
{
    int day = 0;
    scanf("%d", &day);
    switch(day)
    {
        case 1:
            printf("星期%d", 1);
        break;
        case 2:
            printf("星期%d", 1);
        break;
        case 3:
            printf("星期%d", 1);
        break;
        case 4:
            printf("星期%d", 1);
        break;
        case 5:
            printf("星期%d", 1);
        break;
    }
    return 0;
}

// int main()
// {
//     int a = 1;
//     printf("Bitte geben Sie eine Nummer:");
//     scanf("%d", &a);
//     if((a%2) ==1)
//         printf("Es ist ungerade Zahl\n");
//     else
//         printf("Es is gerade Zahl\n");

//     // int a = 1;
//     // while (a<100)
//     // {
//     //     if(a%2 == 1)
//     //        printf("%d ", a);
//     //     a++;
//     // }
//     return 0;
// }

// int main()
// {
//     int a = 4;
//     if(5 == a)
//        printf("xd\n");
//     // if(a = 5)
//     //    printf("lol\n");
//     return 0;
// }

// int main()
// {
//     int a = 1;
//     int b = 2;
//     if(a==2)
//     {
//       if(b==2)
//          printf("xd\n");
//     }
//     else
//        printf("LOL\n");
//     // int a = 10;
//     // if(a<18)
//     // {
//     //    printf("kind\n");
//     //    printf("Keine Akohol\n");
//     // }
//     // else if(a>=18 && a<30)
//     //    printf("junge Erwachsene\n");
//     // else if (a>=30)
//     //    printf("Erwachsene\n");
//     return 0;
// }

// int main()
// {
//     char ch = 'w';
//     printf("%c\n", ch);
//     char* pc = &ch;
//     *pc = 'a';
//     printf("%p\n", pc);
//     printf("%c\n", *pc);
//     printf("%lu\n", sizeof(pc));
// }

// int main()
// {
//     int a = 10;  // 4 Byte = 32 bits, 2^32 = 4G
//     // Computer 4G = 4 * 1024 * 1024 * 1024 Byte
//     // 1 Byte = 8 Bits 1 KB = 1024 Bytes 1 MB = 1024 KB 1 GB = 1024 MB
//     int* p = &a; //bekommen Addresse 指针变量
//     *p = 20;
//     printf("%p\n", &a);
//     printf("%p\n", p);
//     printf("%d\n", a);
//     return 0;
// }

// #define Maximal 100
// //函数
// int Max(int x, int y)
// {
//     if(x>y)
//        return x;
//     else
//        return y;
// }
// //宏的方式
// #define MAX(X,Y) ((X>Y) ? X : Y)
// int main()
// {
//     int a = Maximal;
//     int b = 20;
//     //函数
//     int max = Max(a, b);
//     printf("Max = %d\n", max);
//     //宏的方式
//     max = MAX(a,b);
//     printf("Max = %d\n", max);
//     return 0;
// }

// //extern int add(int , int);
// int add(int x, int y)
// {
//     int z = x + y;
//     return z;
// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     int sum = add(a, b);
//     printf("sum= %d\n", sum);
//     return 0;
// }

// void test()
// {
//     static int a = 1;
//     // 1. static 修饰局部变量，使其生命周期延长
//     // 2. static 修饰全局变量，使静态的全局变量只能在自己的源文件使用
//     // 3. static 修饰函数改变了函数的链接属性，外部链接属性-->内部链接属性
//     a++;
//     printf("a=%d\n",a);//a = 2,3,4,5,6
// }
// int main()
// {
//     int i = 0;
//     while (i<5)
//     {
//         test();
//         i++;
//     }
//     return 0;
// }

// int main()
// {
//     auto int a = 10; //局部变量 -- 自动变量 auto可省略
//     return 0;
// }

// int main()
// {
//     // 只要是整数， 内存中存储的都是二进制补码；
//     // 正数： 源码，反码，补码相同；
//     // 负数：
//     // 源码 ------------》反码 -------------》补码
//     // 直接按照正负        源码的符号位置不变      反码加1
//     // 写出的二进制序列     其他位取反
//     //z.B. 
//     //-2
//     //1 0000000 00000000 00000000 00000010 --源码
//     //1 1111111 11111111 11111111 11111101 --反码
//     //1 1111111 11111111 11111111 11111110 --补码
//     int a = 0;
//     int b = ~a;
//     printf("%d\n", b);
//     return 0;
// }

// int main()
// {
//     // (exp1 ? exp2 : exp3)
//     // if exp1 = true then result = exp2 falls false result =  exp3.
//     int a = 10;
//     int b = 20;
//     int max = ((a>b) ? a : b);
//     //int max = 0;
//     // if (a>b)
//     //     max = a;
//     // else
//     //     max = b;
//     printf("%d\n", max);
//     return 0;
// }

// int main()
// {
//     // 0 gleich false, not 0 gleich true, && logic und
//     // || logic or
//     int a = 0;
//     int b = 2;
//     int c = a && b;
//     int d = a || b;
//     printf("%d\n", c);
//     printf("%d\n", d);
//     return 0;
// }

// int main()
// {
//     int a = 10;
//    // int b = a++;
//    // printf("%d %d:",a, b);//a = 11, b = 10;
// //    int b = ++a;
// //    printf("%d %d:",a, b);
//     int b = a--;
//     return 0;
// }

// int main()
// {
//     int a = 0;
//     int b = ~a;
//     printf("%d\n", b);
//     return 0;
// }

// int Max(int x, int y)
// {
//     if(x>y)
//     {
//         return x;
//     }
//     else
//     {
//         return y;
//     }
// }
// int main()
// {
//     int n1 = 10;
//     int n2 = 20;
//     int max = 0;
//     max = Max(n1, n2);
//     printf("Max: %d", max);
//     return 0;
// }

// int main()
// {
//     int a = 3;
//     int b = 5;
//     int c = a & b;// und
//     int d = a | b;// or
//     int e = a ^ b;// not or gleich= 0, not gleich = 1.
//     // a = 011
//     // b = 101
//     printf("%d\n", c); //c = 001
//     printf("%d\n", d); //d = 111
//     printf("%d\n", e); //e = 110
//     return 0;
// }

// int main()
// {
//     int a = 1;
//     int b = a<<3;
//     printf("%d\n", b);//0001 => 1000
//     printf("%d\n", a);
//     return 0;
// }

// int main()
// {
//     int arr[10]={1,2,3,4,5,6,7,8,9,0};
//     int i = 0;
//     while(i<10)
//     {
//         printf("arr[]=: %d ", arr[i]);
//         i++;
//     }
//     return 0;
// }
// int add(int n1, int n2)
// {
//     return n1 + n2 ;
// }

// int main()
// {
//     int n1 = 10;
//     int n2 = 20;
//     int sum = 0;
//     sum = add(n1, n2);
//     printf("sum:= %d\n", sum);
//     return 0;
// }

// int main()
// {
//     int line = 0;
//     printf("stuideren an der TU Darmstadt\n");
//     while(line<20)
//     {
//         printf("schreiben weiter Code!%d\n", line);
//         line ++;
//     }
//     if(line>=20)
//     {
//         printf("Get a Job finally!!!\n");
//     }
//     return 0;
// }

// int main()
// {
//     int input = 0;
//     printf("an der Darmstadt\n");
//     printf("Studieren fleißig (0/1) :");
//     scanf("%d", &input);
//     if(input == 1)
//     {
//         printf("Job!!!\n");
//     }
//     else
//     {
//         printf("Go home :)\n");
//     }
//     return 0;
// }