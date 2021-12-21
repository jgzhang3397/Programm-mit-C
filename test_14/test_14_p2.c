#include<stdio.h>

// int main()
// {
//     short s = 0;//2
//     int a = 10;
//     printf("%d\n", sizeof(s=a+5));//2, sizeof()里的表达式不参与运算
//     printf("%d\n", s);//0
//     return 0;
// }

// int main()
// {
//     int a = 0;
//     //~ 按2进制位取反
//     //00000000000000000000000000000000
//     //11111111111111111111111111111111 -补码
//     //11111111111111111111111111111110 -反码
//     //10000000000000000000000000000001 -原码-1
//     printf("%d\n", ~a);//-1
//     return 0;
// }

// int main()
// {
//     int a = 11;
//     a = a|(1<<2);
//     printf("%d\n", a);//00000000000000000000000000001111 = 15
//     //00000000000000000000000000001011 a= 11

//     //00000000000000000000000000000100 1<<2
//     //1<<2
//     //00000000000000000000000000000001

//     //00000000000000000000000000001111 result1=a

//     //11111111111111111111111111111011 &result1
//     //00000000000000000000000000000100 ~

//     //00000000000000000000000000001011 = result2
//     int result2 = a &(~(1<<2));
//     printf("%d\n", result2);//11
//     return 0;
// }

// int main()
// {
//     int a = 10;
//     //printf("%d\n", ++a);//前置++， 先++，后使用 11
//     printf("%d\n", a++);//后置++， 先使用，后++， 10
//     return 0;
// }

// int main()
// {
//     int a = (int)3.14;//强制转换
//     return 0;
// }


// void test1(int arr[])
// {
//     printf("%d\n", sizeof(arr));//arr 是指针变量 4
// }
// void test2(char ch[])
// {
//     printf("%d\n", sizeof(ch));//ch 是指针变量 4  
// }
// int main()
// {
//     int arr[10]={0};
//     char ch[10]={0};
//     printf("%d\n", sizeof(arr));//4*10
//     printf("%d\n", sizeof(ch));//1*10 
//     test1(arr);//数组传参传的是首元素地址，需要指针接收
//     test2(ch);
//     return 0;
// }

// int main()
// {
//     int i = 0, a = 1, b = 2, c = 3, d = 4;
//     // i = a++ && ++b && d++; //0&&NaN = 0, 右边不再算了
//     i = a++||++b||d++; //1||NaN = 1, 右边不算
//     printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//     return 0;
// }

// //三目操作符
// int main()
// {
//     int a = 10, b = 20;
//     // if(a>5)
//     //     b = 3;
//     // else
//     //     b = -3;
//     // b = (a>5?3:-3);
//     int max = (a>b?a:b);
//     return 0;
// }

// int main()
// {
//     int a = 1;
//     int b = 2;
//     int c = (a>b, a=b+10, a, b= a+1); // b = 13， 从左到右去算，结果取最后一个
//     printf("%d\n", c);
//     return 0;
// }

// //struct 结构体
// //student
// //Eine struct erstellen
// struct stu
// {
//     char name[20];
//     int age;
//     int id[20];
// };
// int main()
// {
//     int a = 10;
//     //verwenden eine struct eine s1 erstellen und initialisieren
//     struct stu s1 = {"Mike", 20, 979877};
//     struct stu* ps = &s1;
//     printf("%s\n", ps->name);
//     //printf("%s\n", (*ps).name);
//     // printf("%s\n", s1.name);
//     // printf("%d\n", s1.age);
//     // printf("%d\n", s1.id);
//     return 0;
// }

// int main()
// {
//     char a = 3;
//     //00000000000000000000000000000011
//     //00000011 -a
//     char b = 127;
//     //00000000000000000000000001111111
//     //01111111 -b
//     char c = a+b;
//     //00000000000000000000000000000011 -a 整型提升
//     //00000000000000000000000001111111 -b
//     //00000000000000000000000010000010 -c
//     //10000010 -c
//     //11111111111111111111111110000010 -补码 = 反码+1
//     //11111111111111111111111110000001 -反码
//     //10000000000000000000000001111110 -原码 - 126
//     printf("%d\n", c);
//     return 0;
// }
//Exsample
// int main()
// {
//     char a = 0xb6; 11010110
//     short b = 0xb600;
//     int c = 0xb6000000;
//     if (a == 0xb6)
//         printf("a");
//     if (b == 0xb600)
//         printf("b");
//     if (c == 0xb6000000)
//         printf("c");
//     return 0;
// }

int main()
{
    char c = 1;
    printf("%lu\n", sizeof(c));
    printf("%lu\n", sizeof(+c));
    printf("%lu\n", sizeof(!c));
    return 0;
}