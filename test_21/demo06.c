#include<stdio.h>
#include<stdlib.h>
/*
柔性数组
    数组的大小可以被调整
    特点：
    1. 结构中的柔性数组成员之前必须至少一个其他成员
    2. sizeof 返回的这种结构大小不包括柔性数组的内存
    3. 包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小
*/

struct S
{
    int n;
    int arr[];//柔性数组，未知大小
};

void Test01()
{
    // struct S s;
    // printf("%u\n", sizeof(s));
    struct S* ps = malloc(sizeof(struct S)+ 5*sizeof(int));
    ps->n = 100;
    for (int i = 0; i < 5; i++)
    {
        ps->arr[i] = i;
    }

    struct S* ptr = realloc(ps, 44);
    if(ptr != NULL)
    {
        ps = ptr;
    }
    for (int i = 5; i < 10; i++)
    {
        ps->arr[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", ps->arr[i]);
    }
    free(ps);
    ps = NULL;
}

struct S1
{
    int n;
    int* arr;
};

void Test02()
{
    struct S1* ps = (struct S1*)malloc(sizeof(struct S1));
    ps->arr = malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        ps->arr[i] = i;
        //printf("%d ", ps->arr[i]);
    }

    //调整空间大小
    int* ptr = realloc(ps->arr, 10*sizeof(int));
    if(ptr != NULL)
    {
        ps->arr = ptr;
    }
    for (int i = 5; i < 10; i++)
    {
        ps->arr[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", ps->arr[i]);
    }
    
    //释放内存
    free(ps->arr);
    ps->arr = NULL;
    free(ps);
    ps = NULL;
}

int main()
{
    //Test01();//柔性数组，空间连续，访问效率更高
    Test02();
    return 0;
}