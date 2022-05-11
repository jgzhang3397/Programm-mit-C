#include<stdio.h>

// 重写for循环， 不使用 && 和 ||
int main()
{
    char s[100] = {0};
    int c = 0;
    int i = 0;

    // for(i=0; i<100 && ( (c = getchar()) != '\n'  &&  c != EOF ); ++i)
    //     s[i] = c;
    
    while (i<100)
    {
        if( ((i<100) + ((c = getchar()) != '\n') + (c != EOF)) ==3 )
            s[i] = c ;
        else
            break;
        ++i;
    }
    
    printf("%s\n", s);
    return 0;
}