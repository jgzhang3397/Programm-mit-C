#include<stdio.h>
/*
Test01()&Test02():
    描述
    凯刚写了一篇美妙的作文，请问这篇作文的标题中有多少个字符？
    注意：标题中可能包含大、小写英文字母、数字字符、空格和换行符。统计标题字 符数时，空格和换行符不计算在内。

    输入描述：
    输入文件只有一行， 一个字符串s。

    输出描述：
    输出文件只有一行，包含一个整数，即作文标题的字符数（不含空格和换行符）。
*/
void Test01()
{
    char c;
    int count = 0;
    while(scanf("%c", &c)!=EOF)
    {
        if((c!=' ') && (c!='\n'))
            count++;
    }
    printf("%d\n", count);
}

/*
    char * gets ( char * str );
        Get string from stdin
*/
#include<stdlib.h>
#include<string.h>
void Test02()
{
    int n;
    int count = 0;
    char* s = (char *)malloc(n*sizeof(char));
    if(s==NULL)
    {
        fprintf(stderr, "Memory allocation Failed!\n");
        exit(0);
    }
    gets(s);//用gets 是因为其可以输出数组中的空格，而scanf不能
    int sz = strlen(s);
    int i = 0;
    for(i=0; i<sz; i++)
    {
        if(*(s+i) != ' ')
            count ++;
    }
    printf("%d\n", count);
    free(s);
    s = NULL;

}
int main()
{
    //Test01();
    Test02();
    return 0;
}
