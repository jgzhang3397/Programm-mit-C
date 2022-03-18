#include<stdio.h>
#include<string.h>
int main()
{
    // char arr[] = "abcdef";//a b c d e f \0

    // printf("%lu\n", strlen(arr));//6 除去‘\0‘
    // printf("%lu\n", strlen(arr + 0));//6 arr首元素地址 == arr + 0
    // //printf("%d\n", strlen(*arr));//error 非法访问内存
    // //printf("%d\n", strlen(arr[1]));//error strlen接收的必是地址
    // printf("%lu\n", strlen(&arr));//6 数组的地址 -- 数组指针 char(*p)[7] = &arr;
    // printf("%lu\n", strlen(&arr + 1));//随机值
    // printf("%lu\n", strlen(&arr[0] + 1));//5


    // printf("%d\n", sizeof(arr));//7 * 1
    // printf("%d\n", sizeof(arr + 0));//4\8 首元素地址
    // printf("%d\n", sizeof(*arr));//1 首元素大小
    // printf("%d\n", sizeof(arr[0]));//1 首元素大小
    // printf("%d\n", sizeof(&arr));//4\8 地址-->整个数组地址
    // printf("%d\n", sizeof(&arr + 1));//4\8 地址-->跳过该数组地址
    // printf("%d\n", sizeof(&arr[0] + 1));//4\8 地址-->第二个元素的地址

    char *p = "abcdef"; // a b c d e f \0
    // printf("%lu\n", sizeof(p));//4\8 首地址
    // printf("%lu\n", sizeof(p + 1));//4\8 第二个元素b的地址
    // printf("%lu\n", sizeof(*p));//p 首地址 *p == a --> 1
    // printf("%lu\n", sizeof(p[0]));//p 首地址 p[0] == a --> 1
    // printf("%lu\n", sizeof(&p));//4\8 
    // printf("%lu\n", sizeof(&p + 1));//4\8 
    // printf("%lu\n", sizeof(&p[0] + 1));//4\8 

    printf("%lu\n", strlen(p));//6
    printf("%lu\n", strlen(p + 1));//5
    //printf("%lu\n", strlen(*p));//error
    //printf("%lu\n", strlen(p[0]));//error
    printf("%lu\n", strlen(&p));//随机值 p是地址，地址是随机的
    printf("%lu\n", strlen(&p + 1));//随机值 + 1
    printf("%lu\n", strlen(&p[0] + 1));//5
    return 0;
}