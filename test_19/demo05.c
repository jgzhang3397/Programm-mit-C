/*
字符分类函数：
    iscntrl : 任何控制字符
    isspace : 空白字符：空格'', 换页'\f', 换行'\n', 回车'\r', 制表符‘\t'或者垂直制表符'\v'
    isdigit : 十进制数字0-9
    isxdigit : 十六进制数字，包括所有十进制数字,小写字母a-f, 大写字母A-F
    islower: 小写字母a-z
    ...
*/
#include<stdio.h>
#include<ctype.h>

// void test1()
// {
//     char ch = 'a';
//     int ret = islower(ch);
//     printf("%d\n", ret);//1
// }

// void test2()
// {
//     char ch = '@';
//     int ret = islower(ch);
//     printf("%d\n", ret);//0
// }

// int main()
// {
//     test1();//小写字母返回非0
//     test2();//其他的返回0
//     return 0;
// }

/*
字符转换：
    int tolower(int c);//大写转小写
    int toupper(int c);//小写转大写
*/
// void test1()
// {
//     char ch = tolower('A');
//     putchar(ch);//a
// }

// void test2()
// {
//     char ch = toupper('a');
//     putchar(ch);//A
// }

// void test3()
// {
//     char arr[] = "HELLO,world";
//     int i = 0;
//     while (arr[i])
//     {
//         arr[i] = tolower(arr[i]);
//         i++;
//     }
//     printf("%s\n", arr);
// }

// void test4()
// {
//     char arr[] = "HELLO,world";
//     int i = 0;
//     while (arr[i])
//     {
//         arr[i] = toupper(arr[i]);
//         i++;
//     }
//     printf("%s\n", arr);
// }

// int main()
// {
//     // test1();
//     // test2();
//     test3();
//     test4();
//     return 0;
// }

/*
    mem相关函数：
        1. memcpy: 从source的位置开始向后复制num个字节到dest的内存位置
    void * memcpy ( void * destination, const void * source, size_t num );
        void* - 通用类型的指针-无类型指针

*/
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
        (char*)src++;
    }
    return ret;
}

void test2()
{
    struct S arr1[] = {{"leo", 20}, {"anna", 18}};
    struct S arr2[3] = {0};
    //memcpy(arr2, arr1, sizeof(arr1));  
    my_memcpy(arr2, arr1, sizeof(arr1));  
    printf("%s, %d\n", arr2[0].name, arr2[0].age);
}

int main()
{
    //test1();
    test2();
    return 0;
}