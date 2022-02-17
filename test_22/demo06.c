#include<stdio.h>
#include<string.h>
#include<errno.h>

void test01()
{
    FILE* pf = fopen("testo.txt", "r");
    if(pf == NULL)
    {
        return;
    }
    //1. 定位文件指针
    //'SEEK_CUR'文件指针当前位置， 
    //‘SEEK_END'文件的末尾位置
    //‘SEEK_SET'文件的起始位置
    //‘2’表示向右偏移2个字节 '-2'表示向左偏移
    fseek(pf, 2, SEEK_CUR);

    //2. 读取文件
    int ch = fgetc(pf);
    printf("%c\n", ch);

    fclose(pf);
    pf = NULL;

}

void test02()
{
    FILE* pf = fopen("testo.txt", "r");
    if(pf == NULL)
    {
        return;
    }

    //1. 定位文件指针
    fseek(pf, -2, SEEK_END);

    //ftell 返回文件指针相对于起始位置的偏移量
    int pos = ftell(pf);
    printf("%d\n", pos);

    fclose(pf);
    pf = NULL;
}

void test03()
{
    FILE* pf = fopen("testo.txt", "r");
    if(pf == NULL)
    {
        return;
    }

    //1. 定位文件指针
    fseek(pf, -2, SEEK_END);

    //ftell 返回文件指针相对于起始位置的偏移量
    int pos = ftell(pf);
    printf("%d\n", pos);

    //rewind 让文件指针的位置回到文件的起始位置
    rewind(pf);
    pos = ftell(pf);
    printf("%d\n", pos);

    fclose(pf);
    pf = NULL;
}

void test04()
{
    //feof();//EOF -- end of file - 文件结束标志
    FILE* pf = fopen("texto.txt", "r");
    if(pf == NULL)
    {
        return;
    }

    int ch = fgetc(pf);
    printf("%d\n", ch);//-1,文件结束标志

    fclose(pf);
    pf = NULL;

}

void test05()
{
    //strerror - 把错误码对应的错误信息的字符串地址返回
    //printf("%s\n", strerror(errno));

    //perror
    FILE* pf = fopen("test02.txt", "r");
    if(pf == NULL)
    {
        perror("error: ");//error: : No such file or directory
        return;
    }
    //读文件
    //...

    fclose(pf);
    pf = NULL;
}

/*
在文件读取过程中，不能用feof函数的返回值直接用来判断文件是否结束
应用于当文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束
*/
void test06()
{
    FILE* pf = fopen("test.txt", "r");
    if(pf == NULL)
    {
        perror("open file test.txt");
        return;
    }

    //读文件
    int ch = 0;
    while ((ch = fgetc(pf)) != EOF)
    {
        putchar(ch);
    }
    if(ferror(pf))
    {
        printf("error\n");
    }
    else if(feof(pf))
    {
        printf("end of file\n");
    }
    
    fclose(pf);
    pf = NULL;
}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();
    return 0;
}