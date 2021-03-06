
/*
    mem相关函数：
        1. memcpy: 从source的位置开始向后复制num个字节到dest的内存位置
    void * memcpy ( void * destination, const void * source, size_t num );
        void* - 通用类型的指针-无类型指针

*/
#include<stdio.h>
#include<string.h>
#include<assert.h>
void test1()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5] = {0};
    int len = sizeof(arr2)/sizeof(arr2[0]);
    //memcpy 前 
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr2[i]);
    }
    printf("\n");
    //cpy 后
    memcpy(arr2, arr1, sizeof(arr1));
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr2[i]);
    }  
}

struct S
{
    char name[20];
    int age;
};

/*
    i++ 与 ++i 的主要区别有两个：

        1、 i++ 返回原来的值，++i 返回加1后的值。

        2、 i++ 不能作为左值，而++i 可以。
*/

void* my_memcpy(void* dest, const void* src, size_t num)
{
    assert(dest != NULL);
    assert(src != NULL);
    //num 个 字节 需要强转成char* 类型
    void* ret = dest;
    while (num--)
    {
        *(char*)dest = *(char*)src;
        (char*)dest++;
        (char*)src++;//先强转，后++
    }
    return ret;
}

void test2()
{
    struct S arr1[] = {{"leo", 20}, {"anna", 18}};
    struct S arr2[3] = {0};
   // memcpy(arr2, arr1, sizeof(arr1));  
    my_memcpy(arr2, arr1, sizeof(arr1));  
    printf("%s, %d\n", arr2[0].name, arr2[0].age);
}

/*
dest & src地址大小比较：确定拷贝顺序
    dest<src src的m个数据从前向后拷贝
    dest>src&&dest<src+count src的m个数据从后向前拷贝
    dest>src+count, 两种拷贝方法都可
*/
void* my_memmove(void* dest, const void* src, size_t num)
{
    assert(dest && src);
    void* ret = dest;
    if(dest<src)
    {
        //前->后
        while (num--)
        {
            *(char*)dest = *(char*)src;
            (char*)dest++;
            (char*)src++;
        }
        
    }
    else
    {
        //后->前
        //先找的最后一个字节的地址 dest + num -1
        while (num--)//20 - 1= 19
        {
            *((char*)dest + num) = *((char*)src + num);
        }
        
    }

    // if(dest<src || dest>(char*)src+count)
    // {
    //     //前->后
    // }
    // else
    // {
    //     //后->前
    // }
    return ret;
}

void test3()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    int len = sizeof(arr)/sizeof(arr[0]);
    //my_memcpy(arr+2, arr, 20);//在arr中从arr[2]向后拷贝5个值到arr里，20个字节
    //1 2 1 2 1 2 1 8 9 10

    //理想值：1 2 1 2 3 4 5 8 9 10
    //原因：找不到3，4，5的值，被1，2取代
    //解决办法：memmove()
    //memmove(arr+2, arr, 20);//1 2 1 2 3 4 5 8 9 10
    //memcpy(arr+2, arr, 20);//1 2 1 2 1 2 1 8 9 10
    my_memmove(arr+2, arr, 20);
    for ( i = 0; i <len ; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void test4()
{
    //01 00 00 00 02 00 00 00 03 00 00 00
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 5, 4, 3};
    //01 00 00 00 02 00 00 00 05 00 00 00
    int ret = memcmp(arr1, arr2, 9);
    printf("%d\n", ret);//3-5=-2
}

void test5()
{
    int arr[10] = {0};
    memset(arr, '*', 40);/40 是字节数
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        printf("%c ", arr[i]);
    }
    
}

int main()
{
    //test1();//memcpy
    //test2();//my_memcoy
    //test3();//memmove && my_memmove
    //test4();//memcmp
    test5();//memset
    return 0;
}