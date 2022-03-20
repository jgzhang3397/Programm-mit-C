#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
=====指向函数指针数组的指针======
*/
int Add_T1(int x, int y)
{
    return x + y;
}
void Test01()
{
    int arr[10] = {0};
    int (*p)[10] = &arr;//取出数组的地址；

    int (*pfArr[4])(int, int);//pfArr是一个数组-函数指针的数组
    int (*(*ppfArr)[4])(int, int) = &pfArr;
    //ppfArr是一个数组指针，指针指向的数组有四个元素
    //指向的数组的每个元素的类型是一个函数指针 int(*)(int, int)
}

int Add_T2(int x, int y)
{
    return x + y;
}
void Test02()
{
    //指针数组
    int* arr[10];
    //数组指针
    int* (*pa)[10] = &arr;
    //函数指针
    int (*pAdd)(int, int) = Add_T2;//&Add_T2

    //int sum = (*pAdd)(1, 2);
    int sum = pAdd(1, 2);

    printf("sum = %d\n", sum);

    //函数指针的数组
    int (*pArr[5])(int, int);
    //指向函数指针数组的指针
    int (*(*ppArr)[5])(int, int) = &pArr;
}

/*
Test03():
    ======回调函数=======
*/
void print(char *str)
{
    printf("Hello %s", str);
}
void test(void (*p)(char*))
{
    printf("test\n");
    p("World");
}
void Test03()
{
    test(print);
}

/*
Test04():
    冒泡排序
*/
void bubble_sort(int arr[], int sz)
{
    int i = 0;
    for ( i = 0; i < sz; i++)
    {
        int j = 0;
        for ( j = 0; j < sz-1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = 0;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }   
    } 
}
void Test04()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int sz = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, sz);
    int i;
    for(i=0; i<sz; i++)
    {
        printf("%d ", arr[i]);
    }
}

/*
Test05():
    qsort - 库函数 - 排序
    void qsort (void* base, 
                size_t num, 
                size_t size,
                int (*compar)(const void* e1,const void* e2));
    base --> 待排数组的首元素地址
    num --> 元素个数
    size -> 单个元素的大小，单位字节
    (*compar)(const void* e1,const void* e2))：--> 函数指针，比较两个元素的所用函数的地址
    函数指针的两个参数是：待比较两个元素的地址

    void* ？ ：
        void* 类型的指针，可以接收任意类型变量的地址
        void* 类型的指针，不能进行解引用操作
        void* 类型的指针，不能进行+—整数的操作   

*/
struct stu
{
    char name[20];
    int age;
};
int cmp_int(const void* e1, const void* e2)
{
    //比较两个整型值的
    return *(int*)e1 - *(int*)e2;
}

int cmp_float(const void* e1, const void* e2)
{
    //比较两个浮点型值的
    if(*(float*)e1 == *(float*)e2)
    {
        return 0;
    }
    else if(*(float*)e1 > *(float*)e2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    //return (int) (*(float*)e1 - *(float*)e2);
}

int cmp_stu_by_age(const void* e1, const void* e2)
{
    return ((struct stu*) e1)->age - ((struct stu*) e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
    //比较名字就是比较字符串
    //字符串比较不能直接用><=来比较， 应该用strcmp函数
    return strcmp(((struct stu*) e1)->name , ((struct stu*) e2)->name);
}

void test1()
{
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    int i = 0;
    for ( i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
}
void test2()
{
    float f[] = {5.9, 16.8, 12.3, 5.0};
    int sz = sizeof(f)/sizeof(f[0]);
    qsort(f, sz, sizeof(f[0]), cmp_float);
    int i = 0;
    for ( i = 0; i < sz; i++)
    {
        printf("%.1f ", f[i]);
    }
}
void test3()
{
    struct stu s[3] = {{"zaver", 22}, {"lukas", 13}, {"anna", 8}};
    int sz = sizeof(s)/sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
    int i;
    for(i=0; i<sz; i++)
    {
        printf("%d ", s[i].age);
    }
    printf("\n");
    qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
    for(i=0; i<sz; i++)
    {
        printf("%s ", s[i].name);
    }
}
void Test05()
{
    test1();
    printf("\n");
    test2();
    printf("\n");
    test3();
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


