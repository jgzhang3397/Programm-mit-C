#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

struct S
{
    char name[20];
    int age;
    double score;
};

void test01()
{
    struct S s = {"leo", 18, 2.1};

    FILE* pf = fopen("test2.txt","wb");//"wb" 新建写入一个二进制文件
    if(pf == NULL)
    {
        return;
    }
    else
    {
        //二进制形式写文件
        fwrite(&s, sizeof(struct S), 1, pf);

        fclose(pf);
        pf = NULL;
    }
}

void test02()
{
    struct S temp = {0};

    FILE* pf = fopen("test2.txt","rb");//"rb" 只读一个二进制文件
    if(pf == NULL)
    {
        return;
    }
    else
    {
        //二进制形式读文件
        fread(&temp, sizeof(struct S), 1, pf);
        printf("%s %d %.2f\n", temp.name, temp.age, temp.score);

        fclose(pf);
        pf = NULL;
    }
}

int main()
{
    //test01();
    test02();
    return 0;
}