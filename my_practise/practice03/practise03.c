#include<stdio.h>
// //小练习
// char* my_strcpy(char* dest, const char* src);
// //写一个函数指针pf，能够指向my_strcpy
// char*（*pf)(char*, const char*) = my_strcpy;
// //写一个函数指针数组pfArr，能够存放4个my_strcpy函数的地址
// char* (*pfArr[4])(char*, const char*) = {0};

//==============计算器============
int Add(int x, int y)
{
    return x + y;
}
int Sub(int x, int y)
{
    return x - y;
}
int Mul(int x, int y)
{
    return x * y;
}
int Div(int x, int y)
{
    return x / y;
}
int Xor(int x, int y)
{
    if(x == y)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void menu()
{
    printf("***************************\n");
    printf("****1. add     2. sub******\n");
    printf("****3. mul     4. div******\n");
    printf("****5. xor     0. exit*****\n");
    printf("***************************\n");
}

void Test01()
{
    int input = 0;
    int x, y;
    int (*pfArr[])(int, int)= {0, Add, Sub, Mul, Div, Xor};
    int sz = sizeof(pfArr)/sizeof(pfArr[0]);
    do
    {
        menu();
        printf("pls enter a number : ->");
        scanf("%d", &input);
        if(input>=1 && input < sz)
        {
            printf("pls enter x & y:>");
            scanf("%d%d", &x, &y);
            // int result = (*pfArr[input])(x, y);
            int result = pfArr[input](x, y);
            printf("%d\n", result);
        }
        else if(input == 0)
        {
            printf("Exit\n");
            break;
        }
        else
        {
            printf("Error\n");
        }
    } while (input); 
}

//回调函数
void Calc(int (*pf)(int, int))
{
    int x, y;
    printf("pls enter x & y :>");
    scanf("%d%d", &x, &y);
    printf("%d\n", pf(x, y));
    //printf("%d\n", (*pf)(x, y));
}

void Test02()
{
    int input = 0;
    int x, y;
    do
    {
        menu();
        printf("pls enter a number : ->");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            Calc(Add);//函数名就是函数的地址
            break;
        case 2:
            Calc(Sub);
            break;
        case 3:
            Calc(Mul);
            break;
        case 4:
            Calc(Div);
            break;
        case 5:
            Calc(Xor);
            break;
        case 0:
            printf("Exit!\n");
            break;
        default:
            break;
        }
    } while (input); 
}

int main()
{
    //Test01();
    Test02();
    return 0;
}