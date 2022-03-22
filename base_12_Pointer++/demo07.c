#include<stdio.h>
#include<string.h>

int main()
{
    //二维数组
    int a[3][4] = {0};

    printf("%lu\n", sizeof(a));//3*4*4 = 48
    printf("%lu\n", sizeof(a[0][0]));//1*4 = 4
    printf("%lu\n", sizeof(a[0]));//4*4 = 16 a[0]第一行作为一维数组的数组名，sizeof(a[0])单独放在sizeof（）内
    //a[1]第二行的数组名
    printf("%lu\n", sizeof(a[0] + 1));//4\8 地址 a[0]没有单独放在sizeof中，表示首元素地址 1行第一个
    //a[0] + 1 ：1行第二个元素地址
    printf("=======================\n");
    printf("%p\n", &a[0][0]);//0x7ffeefbff1c0
    printf("%p\n", a[0] + 1);//0x7ffeefbff1c4
    printf("%p\n", a + 1);//0x7ffeefbff1d0
    printf("%p\n", &a[0] + 1);//0x7ffeefbff1d0
    printf("======================\n");

    printf("%lu\n", sizeof(*a[0] + 1));//4  1行第二个元素地址解引用
    printf("%lu\n", sizeof(a + 1));//4\8 a 首元素地址 ，二维数组首地址就是第一行 a就是第一行地址 a + 1 表示第二行地址

    printf("%lu\n", sizeof(*(a + 1)));//4*4 = 16 第二行地址解引用
    printf("%lu\n", sizeof(&a[0] + 1));//4\8 地址 第二行的地址
    printf("%lu\n", sizeof(*(&a[0] + 1)));//4*4 = 16 第二行地址解引用
    printf("%lu\n", sizeof(*a));//4*4 = 16 第一行地址解引用
    printf("%lu\n", sizeof(a[3]));//4*4 = 16 sizeof内部表达式不访问，计算第四行数组大小

    return 0;

}