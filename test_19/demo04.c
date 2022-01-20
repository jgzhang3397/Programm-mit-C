#include<stdio.h>
#include<string.h>
#include<assert.h>

/*
strtok 函数
char * strtok ( char * str, const char * delimiters );

1. delimiters参数是个字符串，定义了用作分隔符的字符集合
2. str参数指定一个字符串，它包含了0个或者多个由delimiters字符串中一个或者多个分隔符分割的标记
3. strtok函数找的str中的下一个标记，并将其用‘\0’结尾，返回一个指向这个标记的指针
4. strtok函数会改变被操作的字符串，需要临时拷贝一个相同的字符串进行切割
5. strtok函数的第一个参数不为null，函数将找的str中的第一个标记，strtok函数将保存它在字符串中的位置
6. strtok函数str参数为null，函数将在同一个字符串被保存的位置开始，查找下一个标记
7. 如果字符串不存在更多标记，则返回null指针
*/

// int main()
// {
//     const char arr[] = {"198.168.01.22"};
//     char* p = {"."};

//     //复制源数组
//     char buf[100] = {0};
//     strcpy(buf, arr);

//     char* ret = NULL;

//     for(ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//     {
//         printf("%s\n", ret);
//     }
//     return 0;
// }

/*
strerror 函数
char * strerror ( int errnum );
*/
#include<errno.h>
int main()
{
    /*
    strerror(0) --> Undefined error: 0
    strerror(1) --> Operation not permitted
    strerror(2) --> No such file or directory
    ...

    errno 是一个全局的错误码的变量
    当 C语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中
    */
    // char* str = strerror(errno);
    // printf("%s\n", str);

    //打开文件
    FILE* pf = fopen("test.txt", "r");
    if(pf == NULL)
    {
        printf("%s\n", strerror(errno));//No such file or directory
    }
    else
    {
        printf("open file success\n");
    }
    return 0;
}