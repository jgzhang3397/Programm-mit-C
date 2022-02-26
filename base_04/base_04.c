#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Test01():
    goto 语句的用法， 示列关机程序
*/
void Test01()
{
    char input[20] = {0};
    //system("sudo shutdown -S +60");
again:
    printf("Please enter within a minute: I am a idiot or the computer will shut down!\nPlease enter:>");
    /*
    "%[^\n]" == > 读到\n结束读取
    "%[^\n]%*c" ==> 读到\n结束读取,存入input,再抛弃一个字符
    */
    scanf("%[^\n]", input);
    if(strcmp(input,"I am a idiot")==0)
    {
        exit(0);
    }
    else
    {
        goto again;
    }
}

void Test02()
{
    char input[20] = {0};
    do
    {
        // system("sudo shutdown -S +60");
        printf("Please enter within a minute: I am a idiot or the computer will shut down!\nPlease enter:>");
        scanf("%[^\n]", input);
    } while (strcmp(input, "I am idiot") != 0);
    exit(0);
    
}

/*
Test03():
    打印9*9乘法表
    1*1=1
    2*1=1 2*2=2
    3*1=3 3*2=6 3*3=9
    ......
*/
void Test03()
{
    int i = 0;
    int j = 1;
    for(i=1; i<=9; i++)
    {
        //int j = 1;
        for(j=1; j<=i; j++)
        {
            printf("%d*%d=%-2d ", i, j, i*j);//%2d - 右对齐， %-2d 左对齐
        }
        printf("\n");
    }
}

/*
Test04():
    find the maximum value of an array
*/
void Test04()
{
    int i = 0;
    int arr[]={-1,0,1,2,3,4,5,6,7,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int max = arr[0];
    for(i=0; i<sz; i++)
    {
        if(arr[i]>=max)
           max = arr[i];
    }
    printf("Max= %d\n", max);
}

/*
Test05():
求和 sum 
what is sum of (1/1-1/2+1/3-1/4+1/5-...+1/99-1/100)
*/
void Test05()
{
    int i = 0;
    double sum = 0.0;
    int flag = 1;
    for(i=1; i<=100; i++) // i ~= 0!!!
    {
        sum += flag*1.0/i;
        flag = -flag;
    }
    printf("Sum = %lf\n", sum); 
}

/*
Test06():

判断9出现的次数在0到100之间
*/
void Test06()
{
    int i = 0;
    int count = 0;
    for(i=0; i<100; i++)
    {
        if(i%10==9)
        {
            printf("%d ",i);
            count++;
        }
        if(i/10==9)
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nCount: %d\n", count);
}

/*
Test07():
    求100 - 200 间的素数
    素数？
    只能被1和其本身整除
*/
#include<math.h>
void demo01()
{
    int i = 0;
    int j = 0;
    int count = 0;
    for ( i = 101; i < 200; i++)
    {
        for(j=2; j<i; j++)
        {
            if(i%j==0)
            {
                break;
            }
        }
        if(j==i)
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nCount: %d\n", count);
}
void Test07()
{
    int i = 0;
    int j = 0;
    int count = 0;
    //demo01
    //demo01();
    for(i=101; i<200; i+=2)
    {
        int j = 0;
        for(j=2; j<=sqrt(i); j++)
        {
            if(i%j==0)
             break;
        }
        if(j>sqrt(i))
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nCount: %d\n", count);
}

/*
Test08():
    求2000年到2100年之间的闰年
    闰年？
    1.能被4整除但不被100整除
    2.能被400整除
*/
void Test08()
{
    int year = 0;
    int count = 0;
    for(year=2000; year<=2100; year++)
    {
        // if( year %4==0 && year %100!=0)
        // {
        //     printf("%d ",year);
        //     count ++;
        // }
        // else if (year %400==0)
        // {
        //     printf("%d ", year);
        //     count ++;
        // } 
        if((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0))
        {
            printf("%d ", year);
            count++;
        }
    }
    printf("\nCount = %d\n", count);  
}

/*
Test09():
    求两个数的最大公约数
*/
void Test09()
{
    int m = 0;
    int n = 0;
    int r = 0;
    printf("Please enter two number:>>>");
    scanf("%d%d", &m, &n);
    while (m%n!=0)
    {
        r = m%n;
        m = n;
        n = r;
    }
    printf("最大公约数是:%d\n", n);
}

/*
比较a, b, c 三个数的大小 并 从大到小排序

*/
void Test10()
{
    int a = 0;
    int b = 0;
    int c = 0;
    printf("Please enter the 3 number:>>>");
    scanf("%d%d%d", &a, &b, &c);
    if(a<b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if(a<c)
    {
        int temp = a;
        a = c;
        c = temp;
    }
    if(b<c)
    {
        int temp = b;
        b = c;
        c = temp;
    }
    printf("Sort from largest to smallest: %d %d %d ", a, b, c);
}

int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    //Test05();
    //Test06();
    //Test07();
    //Test08();
    //Test09();
    Test10();
    return 0;
}
