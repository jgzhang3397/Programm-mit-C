/*
字符分类函数：
    iscntrl : 任何控制字符
    isspace : 空白字符：空格'', 换页'\f', 换行'\n', 回车'\r', 制表符‘\t'或者垂直制表符'\v'
    isdigit : 十进制数字0-9
    isxdigit : 十六进制数字，包括所有十进制数字,小写字母a-f, 大写字母A-F
    islower: 小写字母a-z, 小写字母返回1，其他字符返回0
    ...
*/
#include<stdio.h>
#include<ctype.h>

void test1()
{
    char ch = 'a';
    int ret = islower(ch);
    printf("%d\n", ret);//1
}

void test2()
{
    char ch = 'A';
    int ret = islower(ch);
    printf("%d\n", ret);//0
}

/*
字符转换：
    int tolower(int c);//大写转小写
    int toupper(int c);//小写转大写
*/
void test3()
{
    char ch = tolower('A');
    putchar(ch);//a
}

void test4()
{
    char ch = toupper('a');
    putchar(ch);//A
}

void test5()
{
    char arr[] = "HELLO,world";
    int i = 0;
    while (arr[i])
    {
        arr[i] = tolower(arr[i]);
        i++;
    }
    printf("%s\n", arr);
}

void test6()
{
    char arr[] = "HELLO,world";
    int i = 0;
    while (arr[i])
    {
        arr[i] = toupper(arr[i]);
        i++;
    }
    printf("%s\n", arr);
}
int main()
{
    test1();//小写字母返回非0
    test2();//其他的返回0

    test3();
    test4();
    test5();
    test6();
    return 0;
}
