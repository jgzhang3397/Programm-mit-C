#include<stdio.h>
#define MAXLINE 1000

/*
编写reserve(s) 函数, 把字符串s颠倒过来
*/
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void reserve(char line[]);
int main()
{
    int len; //当前行长度
    char line[MAXLINE]; //当前输入的行
    char output[MAXLINE]; //输出行

    while ((len = getLine(line, MAXLINE)) >= 0)
    {
        printf("input len :%d\n", len);
        reserve(line);
    }
    return 0;
}

//将一行读入到s中，并返回其长度
int getLine(char s[], int lim)
{
    int c=0, i = 0;

    for(i=0; i<lim-1 && (c = getchar())!= EOF; ++i)
    {
        s[i] = c;
        if(c == '\n' || c == '\t')//删除尾部空格或者制表符
        {
            s[i] = '\0';
            break;
        }
    }
    return i;
        
}

//reserve(output)
void reserve(char output[])
{
    int i = 0;
    int count = 0;
    while (output[i] != '\0')
    {
        i++;
        count++;//算出多少位
    }

    i=0;
    while (count >= i)
    {
        printf("%c", output[count-i]);//逆序输出
        i++;
    } 
    printf("\n");
}