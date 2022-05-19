#include<stdio.h>

// 重写squeeze(s1, s2)函数， 把字符串s1中与s2字符匹配的各个字符删掉,存入s3中
char* squeeze(char s1[], char s2[]);

int main()
{
    char input1[100];
    char input2[10];

    char* result = NULL;
    scanf("%s%s", input1, input2);

    result = squeeze(input1, input2);

    printf("%s\n", result);
    return 0;
}

char* squeeze(char s1[], char s2[])
{
    int i, j, k=0;
    int flag = 0;
    char s3[100] = {0};
    for(i=0; s1[i]!='\0'; i++)
    {
        flag = 0;
        for(j=0; s2[j]!='\0'; j++)
        {
            if(s1[i]==s2[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
           s3[k++]  = s1[i];
    }
    return s3;
}