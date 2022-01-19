#include<stdio.h>
#include<string.h>
#include<assert.h>

// int main()
// {
//     //gcc 编译器
//     // ret = a - b
//     char* p1 = "abc";
//     char* p2 = "baz";
//     // int ret = strcmp(p1, p2);

//     // printf("%d\n", ret);

//     if(strcmp(p1, p2)>0)
//     {
//         printf("p1>p2\n");
//     }
//     else if(strcmp(p1, p2)== 0)
//     {
//         printf("p1=p2\n");
//     }
//     else
//     {
//         printf("p1<p2\n");
//     }
//     return 0;
// }

/*
int strcmp ( const char * str1, const char * str2 );
注意事项：
    1. 第一个字符串大于第二个字符串，则返回大于0的数字
    2. 第一个字符串等于第二个字符串，则返回0
    3. 第一个字符串小于第二个字符串，则返回小于0的数字
    4. 如何判断两个字符串大小 ==》模拟实现my_strcmp
*/
int my_strcmp(const char* str1, const char* str2)
{
    assert(str1 && str2);
    //比较
    while (*str1 == *str2)
    {
        if(*str1 == '\0')
        {
            return 0;
        }
        str1 ++;
        str2 ++;
    }

    //返回1 或 -1
    if(*str1 > *str2)
        return 1;
    else
        return -1;
    //返回相差值
    //return (*str1 - *st2); 
}
// int main()
// {
//     char* p1 = "abcdef";
//     char* p2 = "abqwe";
//     // int ret = strcmp(p1, p2);
//     // printf("ret = %d\n", ret);
//     int ret = my_strcmp(p1, p2);
//     printf("ret = %d\n", ret);
//     return 0;
// }

/*
char * strncpy ( char * destination, const char * source, size_t num );
注意事项：
    1. 拷贝num个字符从源字符串到目标空间
    2. 如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后面追加0，直到num个
    3. 模拟实现my_strncpy
*/
char* my_strncpy(char* dest, const char* src, unsigned int num)
{
    assert(dest && src);
    char* ret = dest;

    //拷贝num个字符从源字符串src到目标空间
    while (num && (*dest++ = *src++))
    {
        num--;
    }
    if(num>0)//num
    {
        while (--num)
        {
            // *dest= '\0';
            // dest++;
            *dest++ = '\0';
        }
    }
    return ret;   
}
// int main()
// {
//     char arr1[10] = "abc";
//     char arr2[] = "hello";

//     // strncpy(arr1, arr2, 6);
//     // printf("%s\n", arr1);
//     my_strncpy(arr1, arr2, 6);
//     printf("%s\n", arr1);
//     return 0;
// }

/*
char * strncat ( char * destination, const char * source, size_t num );

Appends the first num characters of source to destination, plus a terminating null-character.

If the length of the C string in source is less than num, only the content up to the terminating null-character is copied.

模拟实现my_strncat
*/
char* my_strncat(char* dest, const char* src, unsigned int num)
{
    assert(dest && src);
    char* ret = dest;

    //1. 找到目的字符串的'\0'
    while (*dest != '\0')
    {
        dest ++;
    }
    
    //2. 追加num个源字符串到目标字符串
    while (num--)
    {
        if(*src != '\0')
        {
            *dest++ = *src++;
        }
    }
    return ret;
    //4. 如果num>源字符串的个数
    if(num>0)
    {
        *dest = '\0';
    }
    return ret;
}
int main()
{
    char arr1[30] = "hello";
    char arr2[] = "world";
    // strncat(arr1, arr2, 3);
    // printf("%s\n", arr1);
    my_strncat(arr1, arr2, 6);
    printf("%s\n", arr1);
    return 0;
}