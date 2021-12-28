/*
输入一个人的出生日期（包括年月日），将该生日中的年、月、日分别输出。

数据范围：年份满足 1990 ~ 2015，月份满足1~12  ，日满足 1~30
输入描述：
    输入只有一行，出生日期，包括年月日，年月日之间的数字没有分隔符。
输出描述：
    三行，第一行为出生年份，第二行为出生月份，第三行为出生日期。输出时如果月份或天数为1位数，需要在1位数前面补0。
示例：
    输入：20130225 
    输出：
        year=2013
        month=02
        date=25
*/
//Loesung 1
    // int a, b, c;
    // scanf("%4d%2d%2d",&a, &b, &c);
    // if(1<=b && b<=12 && 1<=c && c<=30)
    // {
    //     printf("year=%4d\nmonth=%02d\ndate=%02d\n", a, b, c);
    // }
    
#include<stdio.h>

int main()
{
    int brith;
    scanf("%d", &brith);
    int year = brith/10000;
    int month = brith%10000/100;
    int days = brith%100;
    while (1990<=year && year<=2015 && 1<=month && month<=12 && 1<=days && days<=30) 
    {
        printf("year=%d\n", year);
        if(month>=10)
        {
            printf("month=%d\n", month);
        }
        else
        {
            printf("month=0%d\n", month);
        }
        if(days>10)
        {
            printf("date=%d\n", days);
        }
        else
        {
            printf("date=0%d\n", days);
        }
        break;
    }
    return 0;
}