#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

/*
scanf/prinf : 是针对标准输入流(键盘)/标准输出流(屏幕)的 格式化输入/输出语句
fscanf/fprinf : 是针对所有输入流/所有输出流的 格式化输入/输出语句
sscanf/sprinf : 
    sscanf: 是从字符串中读取格式化的数据
    sprinf: 是把格式化的数据存储到字符串中

*/

struct S
{
    int n;
    float score;
    char arr[10];
};

void test01()
{
    struct S s = {100, 3.14f, "abcdf"};
    struct S temp = {0};
    char buf[1024] = {0};

    sprintf(buf, "%d %f %s", s.n, s.score, s.arr);//把结构体内容全部转换成字符串格式
    //printf("%s\n", buf);

    sscanf(buf, "%d %f %s", &(temp.n), &(temp.score), temp.arr);//把格式化成字符串的数据存在temp结构体中
    printf("%d %.2f %s\n", temp.n, temp.score, temp.arr);
}

int main()
{
    test01();
    return 0;
}