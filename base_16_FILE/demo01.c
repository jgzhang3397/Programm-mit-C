#include<stdio.h>
#include<unistd.h>
/*
File: Program File & Data File
程序文件：
    源程序文件.c
    目标文件.obj in windows
    可执行文件.exe in windows

数据文件：
    文件的内容不一定是程序，而是程序运行时读写的数据
*/

int main()
{
    int a = 10000;
    FILE* pf = fopen("test.txt","wb");
    fwrite(&a, 4, 1, pf);//把a 二进制形式写到文件中
    fclose(pf);
    pf = NULL;
    return 0;
}


