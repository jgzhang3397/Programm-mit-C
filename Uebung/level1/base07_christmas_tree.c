#include<stdio.h>
/*
描述
今天是圣诞节，牛牛要打印一个漂亮的圣诞树送给想象中的女朋友，请你帮助他实现梦想。
    输入描述：
    输入圣诞树的大小 1<=n<=8

    输出描述：
    输出对应的圣诞树

    输入：
        3
输出：
           *
          * *
         * * *
        *     *
       * *   * *
      * * * * * *
     *           *
    * *         * *
   * * *       * * *
  *     *     *     *
 * *   * *   * *   * *
* * * * * * * * * * * *
           *
           *
           *
*/
void fun1()
{
    printf("     *      ");
}
void fun2()
{
    printf("    * *     ");
}
void fun3()
{
    printf("   * * *    ");
}
void fun4()
{
    printf("  *     *   ");
}
void fun5()
{
    printf(" * *   * *  ");
}
void fun6()
{
    printf("* * * * * * ");
}
void fun()
{
    printf("      ");
}
int main()
{
    int n,i,m,j;
    while(scanf("%d", &n)!=EOF && (1<= n && n<=8)){
        if(n==1)
        {
            printf("  *  \n");
            printf(" * * \n");
            printf("* * *\n");
            printf("  *  \n");
        }
        else
        {
            for(i=1; i<=6*(n-1); i++)
            {
                if(i%6==1)
                {
                    //i表示行
                    for(m=0; m<(n-2-i/6); m++)
                    {
                        fun();
                    }
                    for(j=1; j<=i/6+1; j++)
                    {
                        fun1();
                    }
                    printf("\n");
                }
                if(i%6==2)
                {
                    //i表示行
                    for(m=0; m<(n-2-i/6); m++)
                    {
                        fun();
                    }
                    for(j=1; j<=i/6+1; j++)
                    {
                        fun2();
                    }
                    printf("\n");
                }
                if(i%6==3)
                {
                    //i表示行
                    for(m=0; m<(n-2-i/6); m++)
                    {
                        fun();
                    }
                    for(j=1; j<=i/6+1; j++)
                    {
                        fun3();
                    }
                    printf("\n");
                }
                if(i%6==4)
                {
                    //i表示行
                    for(m=0; m<(n-2-i/6); m++)
                    {
                        fun();
                    }
                    for(j=1; j<=i/6+1; j++)
                    {
                        fun4();
                    }
                    printf("\n");
                }
                if(i%6==5)
                {
                    //i表示行
                    for(m=0; m<(n-2-i/6); m++)
                    {
                        fun();
                    }
                    for(j=1; j<=i/6+1; j++)
                    {
                        fun5();
                    }
                    printf("\n");
                }
                if(i%6==0)
                {
                    //i表示行
                    for(m=0; m<=(n-2-i/6); m++)
                    {
                        fun();
                    }
                    for(j=1; j<=i/6; j++)
                    {
                        fun6();
                    }
                    printf("\n");
                }
            }
            for(i=1; i<=n; i++)
            {
                for(j=1;j<=6*(n-1)-1;j++){
                    printf(" ");
                }
                printf("*\n");
            }
        }
    }
    return 0;
}