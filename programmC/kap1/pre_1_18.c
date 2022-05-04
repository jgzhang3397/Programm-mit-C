#include<stdio.h>
#define MAXLINE 1000

/*
把所有长度大于10个字符的输入行打印出来
*/
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; //当前行长度
    char line[MAXLINE]; //当前输入的行
    char output[MAXLINE]; //输出行

    while ((len = getLine(line, MAXLINE)) > 1)
    {
        if(len > 11)
        {
            printf("input len :%d\n", len);
            copy(output, line);
        }
        else if(len <= 10)
            printf("inputs length : %d<= 10, enter input again!\n", len);
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