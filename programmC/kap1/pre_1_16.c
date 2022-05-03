#include<stdio.h>
#define MAXLINE 1000

/*
打印任意长度输入行的长度及文本行的字符
*/
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; //当前行长度
    char line[MAXLINE]; //当前输入的行
    char output[MAXLINE]; //输出行

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        printf("input len :%d\n", len);
        copy(output, line);
        if(len == 1)
            break;
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
        if(c == '\n')
        {
            i++;
            break;
        }
    }

    s[i] = '\0';
    return i;
        
}

//copy 从from copy到 to
void copy(char to[], char from[])
{
    int i;
    i=0;
    while ((to[i] = from[i]) != '\0')
    {
        printf("%c", to[i]);
        i++;
    }
}