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
int main()
{
    test01();
    return 0;
}