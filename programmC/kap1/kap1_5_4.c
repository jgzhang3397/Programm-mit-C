#include<stdio.h>

#define IN 1 //在单词内
#define OUT 0 //在单词外
//统计输入的行数，单词数，字符数
int main()
{
    int c, nl, nw, nc, state;

    state = OUT;

    nl = nw = nc = 0;

    while ((c = getchar())!= EOF)
    {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT && (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')))
        {
            state = IN;
            ++nw;
        }

        //?? 怎么跳出循环
    }
    printf("nc: %d\t nl: %d\t nw: %d\n", nc, nl, nw);
    return 0;
}