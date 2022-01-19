#include<stdio.h>
#include<string.h>
#include<assert.h>

/*
size_t strlen(const char* str);
    注意事项:
    1. 字符串以'\0' 作为结束标志， strlen函数返回的是在字符串中'\0'前面出现的字符个数（不包含'\0'）
    2. 参数指向的字符串必须要以'\0'结束
    3. 注意函数的返回值类型是size_t （unsigned int) 
    4. my_strlen对strlen函数进行模拟
*/
int my_strlen(const char* str)
{
    assert(str != NULL);
    int count = 0;
    while (*str != '\0')//while(*str), '\0' 的asii码值==0
    {
        count++;
        str++;
    }
    return count;
}

// int main()
// {
//     int len = my_strlen("abcdef");
//     //错误示范
//     // char arr[] = {'a', 'b', 'c', 'd', 'e'};
//     // int len = strlen(arr);
//     printf("%d\n", len);
//     return 0;
// }

// int main()
// {
//     //strlen的返回值是size_t == unsigned int >0
//     // 3 - 6 == -3(unsigned int) ==> > 0
//     if(strlen("abc") - strlen("abcdef") >0)
//     {
//         printf("hehe\n");
//     }
//     else
//     {
//         printf("haha\n");
//     }
//     printf("======================\n");
//     if(my_strlen("abc") - my_strlen("abcdef") >0)
//     {
//         printf("hehe\n");
//     }
//     else
//     {
//         printf("haha\n");
//     }
//     return 0;
// }

/*
char* strcpy(char* destination, const char* source);
    注意事项：
    1. 源字符串必须以'\0'结束
    2. 会将源字符串中的'\0'拷贝到目标空间
    3. 目标空间必须足够大，以确保能存放源字符串
    4. 目标空间必须可变
    5. my_strcpy 对 strcpy进行模拟实现
*/
char* my_strcpy(char* dest, const char* src)//const 修饰 指针src不发生改变
{
    assert(dest != NULL);
    assert(src != NULL);
    char* ret = dest;

    // while (*src != '\0')
    // {
    //     // *dest = *src;
    //     // dest++;
    //     // src++;
    //     *dest++ = *src++;
    // }
    //*dest = *src;//'\0' cpy
    
    //拷贝src指向的字符串到dest指向的空间，包含‘\0'
    while (*dest++ = *src++)
    {
        ;
    }
    //返回目的空间的起始地址
    return ret; 
}
// int main()
// {
//     char arr1[] = "abcdefghi";
//     char arr2[] = "hello";

//     //错误示范
//     //char *arr1 = "abcdefghi"; //指针arr1指向的是常量字符串，不可改变
//     // char arr2[] = {'a', 'b', 'v'};//此 arr2[]没有'\0'
//     // strcpy(arr1, arr2);
//     // printf("%s\n", arr1);
    
//     my_strcpy(arr1, arr2);
//     printf("%s\n", arr1);
//     return 0;
// }

/*
char* strcat (char* destination, const char* source);
    注意事项：
    1. 源字符串必须以'\0'结束
    2. 目标空间必须足够大，能容纳下源字符串的内容
    3. 目标空间必须可修改
    4. 字符串自己能给自己追加吗？不能！
*/
char* my_strcat(char* dest, const char* src)
{
    //assert(dest && src);
    assert(dest != NULL);
    assert(src);
    char* ret = dest;
    
    //1. 找到目的字符串的'\0'
    while (*dest != '\0')
    {
        dest ++;
    }
    //2. 追加
    while (*dest++ = *src++)
    {
        ;
    }
    return ret;
}
int main()
{
    char arr1[20] = "hello ";
    char arr2[] = "world";
    strcat(arr1, arr2);
    // printf("%s\n", arr1);
    my_strcat(arr1, arr2);
    printf("%s\n", arr1);
    return 0;
}