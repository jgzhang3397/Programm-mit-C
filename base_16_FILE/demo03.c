#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

void test01()
{
    char buf[1024] = {0};

    FILE* pf = fopen("test.txt", "r");
    if(pf == NULL)
    {
        return;
    }
    else
    {
        //读文件
        fgets(buf, 1024, pf);
        //printf("%s", buf);//buf 里 存在‘\n'
        puts(buf);//直接换行

        fgets(buf, 1024, pf);
        printf("%s", buf);
        //puts(buf);

        fclose(pf);
        pf = NULL;
    }
}

void test02()
{
    FILE* pf = fopen("test.txt", "w");
    if(pf == NULL)
    {
        return;
    }
    else
    {
        //写文件
        fputs("hello", pf);
        fputs("world", pf);

        fclose(pf);
        pf = NULL;
    }
}

void test03()
{
    //从键盘读取一行文本信息
    char buf[1024] = {0};
    fgets(buf, 1024, stdin);//stdin --鼠标 
    fputs(buf, stdout);//stdout -- 屏幕
}

void test04()
{
    char buf[1024] = {0};
    gets(buf);
    puts(buf);
}

struct S
{
    int n;
    float score;
    char arr[10];
};

void test05()
{
    struct S s = {100, 3.14f, "hello"};
    FILE* pf = fopen("test.txt", "w");
    if(pf == NULL)
    {
        printf("%s\n", strerror(errno));
        return;
    }
    else
    {
        //格式化形式 写文件
        fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
        printf("%d %f %s", s.n, s.score, s.arr);

        fclose(pf);
        pf = NULL;
    }
}

void test06()
{
    struct S s = {0};
    FILE* pf = fopen("test.txt", "r");
    if(pf == NULL)
    {
        printf("%s\n", strerror(errno));
        return;
    }
    else
    {
        //格式化形式 读文件
        fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);

        printf("%d %f %s", s.n, s.score, s.arr);

        fclose(pf);
        pf = NULL;
    }
}

void test07()
{
    struct S s = {0};

    fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);
    fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr);
}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    test07();
    return 0;
}