#include<stdio.h>
#define MAXLINE 1000

/*
把每个输入行中的尾部空格及制表符都删除掉，并删除空格行
*/
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; //当前行长度
    char line[MAXLINE]; //当前输入的行
    char output[MAXLINE]; //输出行

    while ((len = getLine(line, MAXLINE)) >= 0)
    {
        printf("input len :%d\n", len);
        copy(output, line);
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

//copy 从from copy到 to
void copy(char to[], char from[])
{
    int i;
    i=0;
    if((to[0] = from[0]) == '\0')
        printf("nothing to output\n");
    while ((to[i] = from[i]) != '\0')
    {
        printf("%c", to[i]);
        i++;
    }
    printf("\n");
}