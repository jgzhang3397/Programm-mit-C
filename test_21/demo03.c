#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

void review1()
{
    int *p = (int*) malloc(40);
    // int *p = realloc(NULL, 40);//和malloc一样
    if(p == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    int *p2 = realloc(p, 80);
    if(p2 != NULL)
    {
        p = p2;
    }
}

void error1()
{
    //1. 对NULL指针解引用操作
    int *p = malloc(40);
    //p进行相关的判断
    *p = 10; //malloc开辟空间失败，对NULL指针解引用
}

void error2()
{
    //2. 对动态开辟内存的越界访问
    int *p = (int*)malloc(40);//10个int 0-9
    if(p == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    //越界
    for (int i = 0; i <=10; i++)//error should <10
    {
        *(p + i) = i;
    }

    free(p);
    p = NULL;
    
}

void error3()
{
    //3. 对非动态开辟内存使用free释放
    int a = 10;
    int *p = &a;
    //...
    free(p);//error
    p = NULL;
}

void error4()
{
    //4. 使用free释放动态开辟内存一部分
    int *p = (int*)malloc(40);//10个int 0-9
    if(p == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    for (int i = 0; i <10; i++)
    {
        *p++ = i;
        printf("%d ", *p);
    }
    //回收空间
    free(p);//部分释放了，因为p指向的地址发生了改变，指向了动态内存的末尾
    p = NULL;
}

void error5()
{
    //5. 对同一块动态内存的多次释放
    int *p = (int*)malloc(40);
    if(p == NULL)
    {
        printf("%s\n", strerror(errno));
    }
    //使用
    //释放
    free(p);
    //...
    //p = NULL;
    free(p);//error 需前置null指针
}

#include<unistd.h>
void error6()
{
    //6. 动态开辟内存忘记释放(内存泄漏, 内存被吃完了)
    while (1)
    {
        int* p = (int*)malloc(1);
        sleep(1);
    }
    
}

void GetMemory(char *p)
{
    //1. 运行代码程序会出现崩溃的现象
    //2. 程序存在内存泄漏的问题
    //str以值传递给p
    //p是GetMemory函数的形参，只能函数内部有效
    //等GetMemory函数返回之后，动态开辟内存尚未释放 并且无法找到，所以造成内存泄漏
    p = (char*)malloc(100);

}

void GetMemory_korrect01(char** p)
{
    *p = (char *)malloc(100);
}

char* GetMemory_korrect02(char *p)
{
    p = (char*)malloc(100);
    return p;
}

void Test01(void)
{
    char *str = NULL;
    //GetMemory(str);//传值，传自己本身
    //GetMemory_korrect01(&str);//传地址
    str = GetMemory_korrect02(str);
    strcpy(str, "hello world");//str是空指针，程序崩溃
    printf(str);
    free(str);
    str = NULL;
}

void Test02()
{
    char* str = "abcdef";
    printf("%s\n", str);
    printf(str);
    printf("abcdef");
}
int main()
{
    // review1();
    // error1();
    // error2();
    // error3();
    // error4();
    // error5();
    //error6();
    Test01();
    //Test02();
    return 0;
}

