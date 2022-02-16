#include<stdio.h>
#include<string.h>
#include<errno.h>
void test01()
{
    //打开文件test.txt
    //相对路径
    //.. 表示上一级路径
    //.  表示当前路径
    //fopen("..test.txt","r");

    //绝对路径
    //fopen("jingangzhang//workspace//Programm-mit-C//test.txt","r");

    FILE* pf = fopen("test.txt", "w");//"w"会创建新的文件，且会覆盖旧文件内容,"r"不会，直接报错
    if(pf == NULL)
    {
        printf("%s\n", strerror(errno));
        return;
    }
    else
    {
        fclose(pf);
        pf = NULL;
    }
}

void test02()
{
    FILE* pfWrite = fopen("testo.txt", "w");
    if(pfWrite == NULL)
    {
        printf("%s\n", strerror(errno));
        return;
    }
    else
    {
        //写文件
        fputc('a', pfWrite);
        fputc('b', pfWrite);
        fputs("sb", pfWrite);

        //关闭文件
        fclose(pfWrite);
        pfWrite = NULL;
    }
}

void test03()
{
    FILE* pfRead = fopen("testo.txt", "r");
    if(pfRead == NULL)
    {
        printf("%s\n", strerror(errno));
        return;
    }
    else
    {
        //读文件
        printf("%c", fgetc(pfRead));
        printf("%c", fgetc(pfRead));
        printf("%c", fgetc(pfRead));
        

        //关闭文件
        fclose(pfRead);
        pfRead = NULL;
    }
}

/*
从键盘输入
输出到屏幕
键盘&屏幕都是外部设备

键盘-标准输入设备 -stdin
屏幕-标准输出设备 -stdout
是一个程序默认打开的两个流设备

stdin FILE*
stdout FILE*
stderr FILE*
*/

void test04()
{
    int ch = fgetc(stdin);
    fputc(ch, stdout);

}

int main()
{
    //test01();
    //test02();
    //test03();
    test04();
    return 0;
}