#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

/*
void* calloc (size_t num, size_t size)
    函数的功能是为num个大小为size的元素开辟一块空间，并且把空间的每个字节初始化为0
    与函数malloc的区别在于calloc会在返回地址之前将申请的空间的每个字节初始化为0

void* realloc (void* ptr, size_t size)
    调整动态开辟空间的大小
    使用注意事项：
        *如果指针变量地址p指向的空间之后有足够的内存空间可以追加，则直接追加，返回改指针变量地址p
        *如果p指向的空间之后会没有足够的空间，则realloc函数重新找一个内存区域，开辟一块满足需求的
         空间，并且把原本内存中的数据拷贝回来，释放旧的内存空间，最后返回新开辟的内存空间地址
        *得用一个新的变量来结束ralloc函数的返回值

注意事项：
    1. 为避免对空指针的解引用操作，需要使用前判断p是否为空指针
    2. 对动态开辟内存的越界访问，注意for遍历时的最大遍历值for_max
    3. 对非动态开辟内存的free（动态开辟内存：malloc,calloc,realloc)
        int a = 10;
        int* p = &a;
        *p = 20;
        free(p);
        p = null;
*/
void test_calloc()
{
    //malloc(10*sizeof(int));
    int *p = (int*)calloc(10, sizeof(int));
    if(p == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", *(p+i));//每个字节初始化为0
        } 
    }

    //释放空间
    //free函数是用来释放动态开辟的空间的
    free(p);
    p = NULL;
}

void test_realloc()
{
    int* p = (int*)malloc(20);
    if(p == NULL)//注意一定要返回值判断
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            *(p + i) = i;
            printf("%d ", *(p + i));
        }
        printf("\n");
    }
    //在使用malloc开辟20个字节空间后，通过realloc再开辟20个字节空间
    //p = realloc(p, 40); //有风险
    int* ptr = realloc(p, INT16_MAX*sizeof(int));
    if(ptr!= NULL)
    {
        p = ptr;
        for (int i = 0; i < INT16_MAX; i++)
        {
            *(p + i) = i;
            printf("%d ", *(p + i));
        }
    }
    free(p);
    p = NULL;
}

int main()
{
    //test_calloc();
    test_realloc();
    return 0;
}