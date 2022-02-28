#include<stdio.h>
#include<string.h>

/*
Test01():
    Add()   
*/
int Add(int a, int b)
{
    return a+b;
}
void Test01()
{
    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("sum: %d\n", sum);
}

/*
Test02():
    strcpy():
        char * strcpy ( char * destination, const char * source );
        destination
            Pointer to the destination array where the content is to be copied.
        source
            C string to be copied.
*/

void Test02()
{
    //strcpy string copy
    char arr1[]="Hallo!";
    char arr2[20]="**********";
                // Hallo!\0
                //'\0' means end
    strcpy(arr2, arr1);
    printf("%s\n", arr2);
}

/*
Test03():
    void * memset ( void * ptr, int value, size_t num );
    Fill block of memory
    Sets the first num bytes of the block of memory pointed 
    by ptr to the specified value (interpreted as an unsigned char).

    ptr
        Pointer to the block of memory to fill.
    value
        Value to be set. The value is passed as an int, 
        but the function fills the block of memory 
        using the unsigned char conversion of this value.
    num
        Number of bytes to be set to the value.
        size_t is an unsigned integral type.

*/
void Test03()
{
    char arr[]="Hello World!\n";
    memset(arr, '*', 5);//memset, memroy setting
    printf("%s\n", arr);
}

/*
Test04():
    int get_Max(int x, int y)
*/
int get_Max(int x, int y)
{
    if(x>y)
       return x;
    else 
       return y;
}
void Test04()
{
    int a = 10;
    int b = 20;
    printf("Please enter two values:>");
    scanf("%d%d", &a, &b);
    int max = get_Max(a, b);
    printf("max: %d\n", max);
}

/*
Test05():
    swap the values ​​of a and b
    The difference between passing a value and passing an address
*/
void Swap1(int x, int y)
{
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}

void Swap2(int* pa, int* pb)
{
    int temp = 0;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void Test05()
{
    int a = 10;
    int b = 20;
    printf("a=%d b=%d\n",a,b);//a=10 b=20
    Swap1(a, b);
    printf("a=%d b=%d\n",a,b);//a=10 b=20
    Swap2(&a, &b);
    printf("a=%d b=%d\n",a,b);//a=20 b=10
}

/*
Test06():
    输出100～200之间的素数
    Print the prime numbers between 100 and 200
*/
#include<math.h>

int is_prime_num(int n)
{
    int j = 2;
    for(j=2; j<=sqrt(n); j++)
    {
        if(n%j == 0)
           return 0;
    }
    return 1;
}

void Test06()
{
    int i = 0;
    for(i=100; i<=200; i++)
    {
        if(is_prime_num(i)==1)
        {
            printf("%d ", i);
        }
    }
}

/*
Test07():
    Determine the leap year between 2000 and 2100 and output
*/
int is_leap_year(int i)
{
    if((i%4==0 && i%100!=0)||i%400==0)
       return 1;
    else
       return 0;
}

void Test07()
{
    int year = 2000;
    for(year=2000; year<=2100; year++)
    {
        if(is_leap_year(year)==1)
        {
            printf("%d ", year);
        }
    }
}

/*
Test08():
    二分查找
    在一个有序的序列中查找一个数，找到了返回其下标，没找到返回-1
    binary search
    Find a number in an ordered sequence, return its subscript if found, return -1 if not found
*/
int binary_search(int arr[], int k, int sz)
{
    int left = 0;
    int right = sz -1;
    while (left<=right)
    {
        int mid = (left + right)-1;
        if(arr[mid]< k)
        {
            left = mid + 1;
        }
        else if(arr[mid]> k)
        {
            right = mid -1;
        }
        else
        {
            return mid;
        }
    }
    return -1;  
}

void Test08()
{
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int k = 0;
    printf("Please enter urs number:>");
    scanf("%d", &k);

    int result = binary_search(arr, k, sz);
    if(result == -1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("%d ", result);
    }
}

/*
Test09():
    函数递增 function increment
*/
void Add_Increment(int* p)
{
    (*p)++;
}
void Test09()
{
    int num = 0;
    printf("%d ", num);
    Add_Increment(&num);
    printf("%d ", num);
    Add_Increment(&num);
    printf("%d ", num);
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
    Test09();
    return 0;
}
