#include<stdio.h>
#define MAXLINE 1000

/*
读入一组文本行，把最长的打印出来
*/
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; //当前行长度
    int max; //当前最大行长度
    char line[MAXLINE]; //当前输入的行
    char longest[MAXLINE]; //当前最长的行长度

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if(len > max)
        {
            max = len;
            copy(longest, line);
        }
        else if(len == 1)//input == '\n' while end
            break;
    }

    if(max >0)
        printf("longest: %s\n", longest);
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
        i++;
    
}