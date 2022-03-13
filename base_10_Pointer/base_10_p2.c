#include<stdio.h>

/*
Test01():
    pointer traversal array
    指针遍历数组
*/
void Test01()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    // int* p = arr;
    // for ( i = 0; i < sz; i++)
    // {
    //     printf("%d\n", *p);
    //     p++;
    // }
    int* p =&arr[9];
    for ( i = 0; i < sz; i++)
    {
        printf("%d\n", *p);
        p--;
    }
}

void Test02()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    printf("%p\n", &arr[9]);//0x7ffeefbff2e4
    printf("%p\n", &arr[0]);//0x7ffeefbff2c0

    printf("%lu\n", &arr[9]-&arr[0]);//9
    printf("%ld\n", &arr[0]-&arr[9]);//-9
}

/*
Test03():
    my strlen
*/
#include<string.h>
int my_strlen(char* str)
{
    char* start = str;//str == 数组首地址
    char* end = str;
    while (*end != '\0')
    {
        end++;
    }
    return end - start;  
}
void Test03()
{
    char arr[]="Hello";
    int mylen = my_strlen(arr);
    int len = strlen(arr);

    printf("%d\n", mylen);//5
    printf("%d\n", len);//5
}

/*
Test04():
    1. &arr- &数组名 -数组名不是首元素的地址-数组名表示整个数组 -&数组名 取得是整个数组的地址
    2. sizeof(arr) - sizeof(数组名)- 数组名表示整个数组 -sizeof(数组名)计算的是整个数组的大小
*/
void Test04()
{
    int arr[10] = {0};

    //arr == 地址，首元素地址 
    printf("%p\n", arr);        // 0x7ffeefbff2c0
    printf("%p\n", arr+1);      // 0x7ffeefbff2c4
    printf("%p\n", &arr[0]);    // 0x7ffeefbff2c0
    printf("%p\n", &arr[0]+1);  // 0x7ffeefbff2c4

    //&arr == 整个数组的地址
    printf("%p\n", &arr);       //0x7ffeefbff2c0
    printf("%p\n", &arr+1);     //0x7ffeefbff2e8
                                // e8 - c0 == 40(d)
}

/*
Test05():
    p+i == &arr[i]
*/
void Test05()
{
    int arr[10]={0};
    int* p = arr;
    int i = 0;
    for ( i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        *(p+i) = i;
        printf("%d\n", *(p+i));
    }
    
    for ( i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%p <=============> %p\n", p+i, &arr[i]);
    }
}

/*
Test06():
    =======二级指针===========

*/
void Test06()
{
    int a = 10;
    int* pa = &a;
    int** ppa = &pa;//二级指针
    //int*** pppa = &ppa;//三级指针。。
    **ppa = 20;
    printf("%d\n", **ppa);//20
    printf("%d\n", *pa);//20
    printf("%d\n", a);//20
}

/*
Test07():
    指针数组
    数组指针
*/
void Test07()
{
    int a = 10, b = 20, c = 30;
    int* pa = &a;
    int* pb = &b;
    int* pc = &c;
    //int* arr[]={&a, &b, &c};//指针数组
    int* arr[] = {pa, pb, pc};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d\n", *(arr[i]));
    }   
}

int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    //Test05();
    //Test06();
    Test07();
    return 0;
}
