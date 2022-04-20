#include <stdio.h>
#include <string.h>

/*
Test01() : getchar & putchar
Test02() : break & continue
Test03() : switch & case
Test04() : scanf & while
Test05() : % take a remainder
Test06() : if + condition judgment
Test07()/Test08() : Pointer
Test09()/Test10() : define & function 
Test11() : static
Test12() : Original Code Inverse Code Complement Code 源反补
Test13() : (exp1 ? exp2 : exp3)
Test14() : Logical Operators
Test15() : ++i & i++
Test16() : bitwise operators
Test17() : '>>' & '<<'
Test18() : iterate over the array 
*/

//========getchar & putchar==============
void Test01()
{
    int ch = 0;
    while ((ch=getchar())!=EOF) // eof = control + z - end of file = -1
    {
        putchar(ch);
    }
}

//==============break & continue===========
void Test02()
{
    for (int i = 0; i < 10; i++)
    {
        if(i == 5)
            //break; //all loops stop
            continue;//this loop end no 5 is printed 
        printf("%d ", i);
    }
    
}

//==============switch & case===================
void Test03()
{
    int n = 1;
    int m = 2;
    switch (n)
    {
    case 1:
        m++; // m = 3 no break continue
    case 2:
        n++; // n = 2 no break continue
    case 3:
        switch (n)
        {
        case 1:
            n++;
        case 2:
            m++; // m = 4 
            n++; // n = 3 
            break;
        }
    case 4:
        m++; // m = 5
        break;
    default:
        break;
    }
    printf("m= %d, n = %d\n", m, n);// m = 5, n = 3
}

//=============scanf & while===============
void Test04()
{
    while (1)
    {
        int day = 0;
        printf("pls give a number: ");
        scanf("%d", &day);
        if(day>=1 && day<=7)
        {
            switch(day)
            {
                case 1:
                    if(day == 1)
                        printf("Oh my god!\n");
                case 2:
                case 3:
                case 4:
                case 5:
                    printf("Workday\n");
                    break;
                case 6:
                    printf("happy time\n");
                case 7:
                    printf("Weekend\n");
                    break;
                default:
                    break;
            }
        }
        else
        {
            printf("no sense try again\n");
        }   
    }
}

//======= % remainder ==========
void Test05()
{
    int a = 1;
    printf("pls give a number:");
    scanf("%d", &a);
    if((a%2) ==1)
        printf("it's a odd number\n");
    else
        printf("it's a even number\n");

    // int a = 1;
    // while (a<100)
    // {
    //     if(a%2 == 1)
    //        printf("%d ", a);
    //     a++;
    // }
}

//========if=========
void Test06()
{
    int a = 10;
    if(a<18)
    {
       printf("kids\n");
       printf("no alcohol\n");
    }
    else if(a>=18 && a<30)
       printf("young poeple\n");
    else if (a>=30)
       printf("adults\n");  
}

//=======Pointer=======
void Test07()
{
    char ch = 'w';
    printf("%c\n", ch);//w
    char* pc = &ch;
    *pc = 'a';
    printf("%p\n", pc);//0x7ffeefbff2ff
    printf("%c\n", *pc);//a
    printf("%lu\n", sizeof(pc));//8
}

/*
4 Byte = 32 bits, 2^32 = 4G
4G = 4 * 1024 * 1024 * 1024 Byte
1 Byte = 8 Bits 
1 KB = 1024 Bytes 
1 MB = 1024 KB 
1 GB = 1024 MB
*/
void Test08()
{
    int a = 10; 
    int* p = &a; //p is pointer variable
    *p = 20;
    printf("%p\n", &a); //0x7ffeefbff2fc
    printf("%p\n", p);  //0x7ffeefbff2fc
    printf("%d\n", a);  //20
}

//=========== define & function ===================
#define MAX_NUM 100
//define macro
#define MAX(X,Y) ((X>Y) ? X : Y)
//===========function==========
int Max(int x, int y)
{
    if(x>y)
       return x;
    else
       return y;
}

void Test09()
{
    int a = MAX_NUM;
    int b = 20;

    int max = Max(a, b);
    printf("Max = %d\n", max);

    max = MAX(a,b);
    printf("Max = %d\n", max);
}

int Add(int x, int y)
{
    int z = x + y;
    return z;
}

void Test10()
{
    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("sum= %d\n", sum);
}

//===================static================
void test_Test11()
{
    static int a = 1;
    // 1. static 修饰局部变量，使其生命周期延长
    // 2. static 修饰全局变量，使静态的全局变量只能在自己的源文件使用
    // 3. static 修饰函数改变了函数的链接属性，外部链接属性-->内部链接属性
    a++;
    printf("a=%d\n",a);//a = 2,3,4,5,6
}
void Test11()
{
    int i = 0;
    while (i<5)
    {
        test_Test11();
        i++;
    }
}

void Test12()
{
    /*
        auto int a = 10; //局部变量 -- 自动变量 auto可省略
        printf("%d\n", a);
    */

    // 只要是整数， 内存中存储的都是二进制补码；
    // 正数： 源码，反码，补码相同；
    // 负数：
    //   源码 ------------>   反码    ------------->   补码
    //   直接按照正负          源码的符号位置不变         反码加1
    //   写出的二进制序列       其他位取反
    //========================
    // ======== 0 ==========
    //？？？
    int a = 0;
    int b = ~a;
    printf("%d\n", b);//-1

    ////======-2=====
    //1 0000000 00000000 00000000 00000010 --源码
    //1 1111111 11111111 11111111 11111101 --反码
    //1 1111111 11111111 11111111 11111110 --补码
    //取反
    //0 0000000 00000000 00000000 00000001 --补码
    a = -2;
    b = ~a;
    printf("%d\n", b);//1
}

//============(exp1 ? exp2 : exp3)==============
/*
    (exp1 ? exp2 : exp3):
        if exp1 = true then result = exp2 falls false result =  exp3.
*/
void Test13()
{
    int a = 10;
    int b = 20;
    int max = ((a>b) ? a : b);
    //int max = 0;
    // if (a>b)
    //     max = a;
    // else
    //     max = b;
    printf("%d\n", max);//20
}

//=============Logical Operators===========
/*
0 == false
not 0 == true
&& logic and
|| logic or
*/
void Test14()
{
    int a = 0;
    int b = 2;
    int c = a && b;
    int d = a || b;
    printf("%d\n", c);//0
    printf("%d\n", d);//1
}

//=============++i & i++===========
void Test15()
{
    int a = 10;
    int b = a++;
    printf("a= %d, b=%d\n",a, b);//a = 11, b = 10;
    b = ++a;
    printf("a= %d, b=%d\n",a, b);//a = 12, b = 12
    b = a--;
    printf("a= %d, b=%d\n",a, b);//a = 11, b = 12
}

//=========== bitwise operators ==========
void Test16()
{
    int a = 3;
    int b = 5;
    int c = a & b;// and
    int d = a | b;// or
    int e = a ^ b;// not or : same = 0, not same = 1.
    // a = 011
    // b = 101
    printf("%d\n", c); //c = 001
    printf("%d\n", d); //d = 111
    printf("%d\n", e); //e = 110
}

//============ '>>' & '<<' ====================
void Test17()
{
    int a = 1;
    int b = a<<3; //0001 => 1000
    printf("%d\n", b);//1000 == 8
    printf("%d\n", a);//0001 == 1

    int c = b>>1; //1000 ==> 0100
    printf("%d\n", c);//0100 == 4
}

//============= iterate over the array =============
void Test18()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    // int i = 0;
    // while(i<10)
    // {
    //     printf("arr[%d]= %d ", arr[i]);
    //     i++;
    // }
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("arr[%d]= %d ", i, arr[i]);
    }  
}

int main()
{
    Test01();
    //Test02();
    //Test03();
    //Test04();
    //Test05();
    //Test06();
    //Test07();
    //Test08();
    //Test09();
    //Test10();
    //Test11();
    //Test12();
    //Test13();
    //Test14();
    //Test15();
    //Test16();
    //Test17();
    //Test18();
    return 0;
}
