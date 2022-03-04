#include<stdio.h>

/*
Test01():
    function recursion
    Accepts an integer value (unsigned) and prints each bit of it in order, 
    for example: 
        input: 1234
        output: 1 2 3 4
*/

void print(int num)
{
    if(num>9)
    {
        print(num/10);
    }
    printf("%d ", num%10);
}

void Test01()
{
    unsigned int num = 0;
    printf("Pls enter a number:>");
    scanf("%d", &num);
    print(num);
}

#include<string.h>
/*
Test02():
    1. Override strlen method：my_strlen()

    2. with function recursion: my_strlen_recursion()
            把大事化小
            my_strlen("bit")
            1+my_strlen("it")
            1+1+my_strlen("t");
            1+1+1+0
*/
int my_strlen(char* arr)
{
    int count = 0;
    while (*arr != '\0')
    {
        count++;
        arr++;
    }
    return count;
}
int my_strlen_recursion(char* arr)
{
    if(*arr != '\0')
    {
        return 1+my_strlen_recursion(arr+1);
    }
    else
    {
        return 0;
    }
}
void Test02()
{
    char arr[] ="Hola";

    int len = strlen(arr);
    printf("Sum des Arrays with strlen: %d\n", len);

    len = my_strlen(arr);
    printf("Sum des Arrays with my_strlen: %d\n", len);

    len = my_strlen_recursion(arr);
    printf("Sum des Arrays with my_strlen_recursion: %d\n", len);
}

/*
Test03():
    求n的阶乘
    factorial -n

        1. int fac1(int n);

    with recursion:
        2. int fac2(int n);
*/
int fac1(int n)
{
    int i = 0;
    int result = 1;
    for(i=1; i<=n; i++)
    {
        result *= i;
    }
    return result;
}

int fac2(int n)
{
    if(n<=1)
       return 1;
    else
       return n*fac2(n-1);
}

void Test03()
{
    int n = 0;
    int result = 0;
    printf("Pls enter the number:>");
    scanf("%d", &n);
    result = fac1(n);
    printf("with loop :%d\n", result);
    result = fac2(n);
    printf("with recursion :%d\n", result);
}

/*
Test04():
    斐波那契数(Fibonacci sequence)
        Fib(0)=0
        Fib(1)=1
        Fib(n)=Fib(n-1)+Fib(n-2)(n>=2)
*/
int Fib(int n)
{
    //运算时间太久
    if(n>=2)
    {
        return (Fib(n-1)+Fib(n-2));
    }
    else 
    {
        return n;
    }
}

int Fib_Optimize(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;
    if(n<2)
    {
        return n;
    }
    while(n>2)
    {
        c = a+b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

void Test04()
{
    int result = 0;
    int n = 0;
    printf("Pls enter the number:>");
    scanf("%d", &n);

    result = Fib(n);
    printf("%d\n", result);

    result = Fib_Optimize(n);
    printf("%d\n", result);
}

/*
Test05():
    青蛙跳台阶：
        一只青蛙一次可以跳上1 级台阶，也可以跳上2 级。求该青蛙跳上一个n 级的台阶总共有多少种跳法
    jump_floor
*/

int jump_floor(int n)
{
    if(n>3)
    {
        return jump_floor(n-1)+jump_floor(n-2);
    }
    else
    {
        return n;
    }
}

int jump_floor_Optimze(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;
    if(n<2)
    {
        return n;
    }
    while (n>=2)
    {
        c = a+b;
        a = b;
        b = c;
        n--;
    }
    return c;  
}

void Test05()
{
    int n = 0;
    int ret = 0;
    printf("Please enter the value of Floor:>");
    scanf("%d", &n);

    ret = jump_floor(n);
    printf("A total of %d kind of jump\n", ret);

    ret = jump_floor_Optimze(n);
    printf("A total of %d kind of jump\n", ret);
}

int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    Test05();
    return 0;
}

