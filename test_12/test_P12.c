#include<stdio.h>
//Funktionsrekursion
//z.B.接受一个整数值（无符号），按照顺序打印他的每一位，例如：输入：1234， 输出：1 2 3 4
void print(int num)
{
    if(num>9)
    {
        print(num/10);
    }
    printf("%d ", num%10);
}
int main()
{
    unsigned int num = 0;
    printf("Bitte geben Sie eine Value ein:>");
    scanf("%d", &num);
    print(num);
    return 0;
}