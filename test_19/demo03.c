#include<stdio.h>
#include<string.h>
#include<assert.h>
/*
strncmp 函数
int strncmp ( const char * str1, const char * str2, size_t num );
模拟实现：my_strncmp()
*/
int my_strncmp(const char* str1, const char* str2, unsigned int num)
{
    assert(str1 && str2);
    //比较
    while (num--)
    {
        if (*str1 == *str2)
        {
            str1 ++;
            str2 ++;
        }
        else
        {
            return (*str1 - *str2);
        }
    }

    //在num个数内，str1 和 str2 仍然相当
    return 0;
    
}

// int main()
// {
//     //strncmp - 字符串比较
//     char* p1 = "abcdef";
//     char* p2 = "abcwer";

//     // int ret = strncmp(p1, p2, 4);
//     // printf("%d\n", ret);
//     int ret = my_strncmp(p1, p2, 2);
//     printf("%d\n", ret);
//     return 0;
// }

/*
strstr --查找字符串
const char * strstr ( const char * str1, const char * str2 );
      char * strstr (       char * str1, const char * str2 );
模拟实现：
    my_strstr()
*/
char* my_strstr(const char* str1, const char* str2)
{
    assert(str1 && str2);

    char* s1 = NULL;
    char* s2 = NULL;
    char* start = (char*) str1;//记录相同元素指针的位置

    if(*str2 == '\0')
    {
        return start;
    }

    while (*start)
    {
        s1 = start;
        s2 = (char*) str2;//初始化

        while ((*s1 == *s2) && (*s2 != '\0') && (*s1 != '\0'))
        {
            s1++;
            s2++;
        }
        if(*s2 == '\0')//if(!*s2)
        {
            return start;//完全匹配 返回起始点 找的了substr
        }
        if(*s1 == '\0')
        {
            return NULL; // 当str2比str1大时
        }
        start++;
    }
    return NULL;//没找到
}

int main()
{
    char *p1 = "abbbcdef";
    char *p2 = "bbc";

    // char* ret = strstr(p1, p2);
    // if(ret == NULL)
    // {
    //     printf("字符串不存在\n");
    // }
    // else
    // {
    //     printf("%s\n", ret);//defghidef
    // }
    char* ret = my_strstr(p1, p2);
    if(ret == NULL)
    {
        printf("字符串不存在\n");
    }
    else
    {
        printf("%s\n", ret);//defghidef
    }
    return 0;
}