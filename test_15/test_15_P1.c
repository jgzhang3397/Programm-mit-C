//=====Schwerpunkt=====
//Was ist Pointer?
//Pointer und die Sort des Pointers
//Pointer, die nicht begrenzt nicht initialisiert etw..
//Pointer umberechnen
//Pointer und Arrays
//2 stufe Pointer
//Pointer-Arrays

#include<stdio.h>

// int main()
// {
//     int a = 10;
//     int* p = &a;//p = Pointer-Variante, also die Addresse 
//     return 0;
// }

// int main()
// {
//     // printf("%d\n", sizeof(char*));
//     // printf("%d\n", sizeof(short*));
//     // printf("%d\n", sizeof(int*));
//     // printf("%d\n", sizeof(double*));
//     int a = 0x11223344;
//     int* pa = &a;
//     char* pc = &a;
//     //指针类型决定了指针进行解引用操作时，能够访问的空间的大小
//     //int* p; *p能访问4个字节
//     //char* p; *p能访问1个字节
//     //double* p; *p能访问8个字节
//     printf("%p\n", pa);
//     printf("%p\n", pa+1);
//     printf("%p\n", pc);
//     printf("%p\n", pc+1);
//     //指针类型决定了：指针走一步走多远
//     //int* p; p+1 --> 4
//     //char* p; p+1 --> 1
//     //double* p; p+1 --> 8
//     return 0;
// }

// int main()
// {
//     int arr[10]={0};
//     int* p = arr;//arr 数组名--首元素地址
//     //char* p = arr;
//     for ( int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//     {
//         *(p+i) = 1;
//     }
    
//     return 0;
// }
int main()
{
    //int a = 0; //局部变量不初始化，默认是随机值
    int* p; //局部指针变量被初始化成随机值，应避免！！
    *p = 20;
    return 0;
}