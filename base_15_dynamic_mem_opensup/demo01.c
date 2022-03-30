#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
/**
 * Test01()&Test02():
 * 动态内存管理：
 *      动态内存函数：
 *          void* malloc(size_t size)
 *          void free(void* ptr)
 *          calloc
 *          realloc
 * 
 */
struct S
{
    char name[20];
    int age;
};

void Test01()
{
    // struct S s[20];//少了
    // struct S s[100];//多了
    // int arr[100];//多了，需要堆上申请动态内存

    int n = 0;
    //gcc 支持c99标准，可以创建变长数组
    scanf("%d", &n);
    int arr[n];
    int i = 0;
    for ( i = 0; i < n; i++)
    {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
}

void Test02()
{
    //向内存申请10个int的空间
    int* p = (int*)malloc(10*sizeof(int));
    /*
    malloc函数：
        向内存申请一块连续可用的空间，并返回指向这块空间的指针
            开辟成功，返回一个开辟好空间的指针
            开辟失败，返回一个NULL指针，因此malloc的返回值一定要做检查
            返回值的类型是void*， 所以malloc函数不具体开辟空间的类型，需要具体使用时决定
            如果参数size为0，malloc的行为是未定义的，取决于编译器
    */
    //int* p = (int*)malloc(__INT_MAX__);
    if(p == NULL)
    {
        //打印错误原因的一个方式
        printf("%s\n", strerror(errno));
    }
    else
    {
        //正常使用空间
        for (int i = 0; i < 10; i++)
        {
            *(p + i) = i;
            printf("%d ", *(p + i));
        }
        
    }
    //当动态申请的空间不再使用时
    //就应该释放还给操作系统
    free(p);
    /*
    free函数用来释放动态开辟的内存
        如果参数ptr指向的空间不是动态开辟的，那free函数的行为是未定义的
        如果参数ptr是NULL指针，则函数什么都不做
    */
    p = NULL;//防止内存泄漏
}
int main()
{
    //Test01();
    Test02();
    return 0;
}