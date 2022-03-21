#include<stdio.h>
/*
    数组名是首元素地址
        两个特例： 
            sizeof（数组名）--> 数组名表示整个数组
            &数组名 --> 数组名表示整个数组

*/
#include<string.h>
//一维数组
void Test01()
{
    int a[] = {1,2,3,4};
    //sizeof(数组名)-计算的数组总大小，单位字节
    printf("%lu\n", sizeof(a));//4*4 = 16;
    printf("%lu\n", sizeof(a + 0));//4\8     --数组名表示首元素地址的值 a+0 还是首元素地址，地址的大小就是指针的大小4\8个字节
    printf("%lu\n", sizeof(*a));//4          a是首元素地址，首元素地址解引用--*a == 首元素大小 
    printf("%lu\n", sizeof(a + 1));//4\8     第二个元素地址，指针的大小
    printf("%lu\n", sizeof(a[1]));//4        -第二个元素大小
    printf("%lu\n", sizeof(&a));//4\8        &a 取出的是数组的地址 -- 地址的大小就是4个或者8个字节
    printf("%lu\n", sizeof(*&a));//16        & 和 * 相互抵消 数组的地址解引用访问的是数组的大小
    printf("%lu\n", sizeof(&a + 1));//4\8    &a + 1 表示跳过当前数组，不过终归也是个地址，地址的大小就是4或者8
    printf("%lu\n", sizeof(&a[0]));//4\8     首元素地址
    printf("%lu\n", sizeof(&a[0] + 1));//4\8 第二个元素地址
}

//字符数组
void Test02()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%lu\n", sizeof(arr));//6*1 = 6
    printf("%lu\n", sizeof(arr + 0));//4\8   地址的大小：arr是首元素地址，因为arr没有单独放在sizeof里
    printf("%lu\n", sizeof(*arr));//1        arr首元素地址，*解引用成首元素大小，char类型1个字节
    printf("%lu\n", sizeof(arr[1]));//1      arr[1] 第二个元素大小
    printf("%lu\n", sizeof(&arr));//4\8      地址的大小，&arr是数组的地址
    printf("%lu\n", sizeof(&arr + 1));//4\8  地址的大小，&arr + 1 是跳过整个数组后的地址
    printf("%lu\n", sizeof(&arr[0] + 1));//4\8 第二个元素的地址
}

void Test03()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%lu\n", strlen(arr));//随机值a           没有'\0'
    printf("%lu\n", strlen(arr + 0));//随机值a       arr + 0 == arr
    //printf("%lu\n", strlen(*arr));//error *arr不能当作地址
    //printf("%lu\n", strlen(arr[1]));//error arr[1]不能当作地址
    printf("%lu\n", strlen(&arr));//随机值a          取数组的地址就是首地址
    printf("%lu\n", strlen(&arr + 1));//随机值 = a-6
    printf("%lu\n", strlen(&arr[0] + 1));//随机值-1
}
int main()
{
    //Test01();
    //Test02();
    Test03();
    return 0;
}