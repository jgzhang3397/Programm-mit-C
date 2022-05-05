#include<stdio.h>
#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];
/*
读入一组文本行，把最长的打印出来 --使用外部变量
*/
int getLine(void);
void copy(void);

int main()
{
    int len; //当前行长度
    extern int max; //当前最大行长度
    char line[MAXLINE]; //当前输入的行
    extern char longest[MAXLINE]; //当前最长的行长度

    max = 0;
    while ((len = getLine()) > 0)
    {
        if(len > max)
        {
            max = len;
            copy();
        }
        else if(len == 1)//input == '\n' while end
            break;
    }

    if(max >0)
        printf("longest: %s\n", longest);
    return 0;
}

//将一行读入到s中，并返回其长度
int getLine(void)
{
    int c=0, i = 0;
    extern char line[];

    for(i=0; i<MAXLINE-1 && (c = getchar())!= EOF; ++i)
    {
        line[i] = c;
        if(c == '\n')
        {
            i++;
            break;
        }
    }

    line[i] = '\0';
    return i;
        
}

//copy 从from copy到 to
void copy(void)
{
    int i;
    extern char line[], longest[];
    i=0;
    while ((longest[i] = line[i]) != '\0')
        i++;
    
}