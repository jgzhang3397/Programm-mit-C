#include<stdio.h>
/*
Test01():
    实现init（）初始化数组全为0
    printf jeder Vektor darin
    reverse() 数组元素逆置
*/
void init(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        arr[i] = 0;
    }
}

void my_print(int arr[], int sz)
{
    for(int i = 0; i< sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse_S1(int arr[], int sz)
{
    int middle = (sz+1)/2;
    for (int i = 0; i < middle; i++)
    {
        int temp = arr[i];
        arr[i] = arr[sz-1-i];
        arr[sz-1-i] = temp;
    }  
}
void reverse_S2(int arr[], int sz)
{
    int left = 0;
    int right = sz -1;
    while (left<right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void Test01()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    my_print(arr, sz);

    reverse_S1(arr, sz);
    my_print(arr, sz);

    reverse_S2(arr, sz);
    my_print(arr, sz);

    init(arr, sz);
    my_print(arr, sz);
}

/*
Test02():
    die Inhalt zweies Arrays umtauschen
*/
void exchange(int* arr1, int* arr2, int sz)
{
    int i,temp;
    for(i=0; i<sz; i++)
    {
        temp = *(arr1+i);
        *(arr1+i) = *(arr2+i);
        *(arr2+i) = temp;
    }
}
void Test02()
{
    int arr1[]={1,3,5,7,9};
    int arr2[]={2,4,6,8,0};
    int sz = sizeof(arr1)/sizeof(arr1[0]);
    int temp =0;

    my_print(arr1, sz);
    my_print(arr2, sz);

    exchange(arr1, arr2, sz);

    // for (int i = 0; i < sz; i++)
    // {
    //     temp = arr1[i];
    //     arr1[i] = arr2[i];
    //     arr2[i] = temp;
    // }

    my_print(arr1, sz);
    my_print(arr2, sz);
}

/*
Test03()&Test04();
    指针传地址
*/
void Test03()
{
    int arr[]={1,2,3,4,5};
    int sz = sizeof(arr)/sizeof(arr[0]);

    //short* p = (short*)arr; // address + 2bytes
    int* p = (int*) arr; //address + 4bytes

    my_print(arr, sz);

    for (int i = 0; i < sz; i++)
    {
        *(p+i) = 0;
    }
    
    my_print(arr, sz);
}

void demo_charpointer()
{
    int a = 0x11223344;
    char *pc = (char*)&a;
    *pc = 0;////44332211-->00332211
    printf("%x\n", a);//0x11223300
}

void demo_shortpointer()
{
    int a = 0x11223344;
    short *ps = (short*)&a;
    *ps = 0;//44332211-->00002211
    printf("%x\n", a);//0x11220000
}

void demo_intpointer()
{
    int a = 0x11223344;
    int *pi = (int*)&a;
    *pi = 0;//44332211-->00000000
    printf("%x\n", a);//0x00000000
}

void Test04()
{
    demo_charpointer();
    demo_shortpointer();
    demo_intpointer();
}

void Test05()
{
    // int i;
    // i--;
    int i = -1;
    //10000000000000000000000000000001 --原码
    //11111111111111111111111111111110 --反码
    //11111111111111111111111111111111 --补码=反码+1 unsigned int >> 0
    if(i > sizeof(i))// sizeof ist unsigned int immer gross null, so i ist auch unsigned int
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
}

/*
Test06():
    统计一个数其二进制1的个数

    V3
    n = 13 
    1101 n
    1100 n-1
    n = n&(n-1) == 1100
    1011 n-1
    n = n&(n-1) == 1000
    0111 n-1
    n = n&(n-1) == 0000
*/

int count_bit_one_V1(unsigned int n)// immer groesser als null
{
    int count = 0;
    while (n)
    {
        if(n%2==1)
        {
            count++;
        }
        n = n/2;
    } 
    return count;
}

int count_bit_one_V2(int n)
{
    int count = 0;
    int i = 0;
    for (int i = 0; i < 32; i++)
    {
        if(((n>>i)&1)==1)
        {
            count++;
        }
    }
    return count;  
}

int count_bit_one_V3(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

void Test06()
{
    int a = 0;
    printf("Pls enter a number:>");
    scanf("%d", &a);
    //int count = count_bit_one_V1(a); //a = -1, count = 32
    int count = count_bit_one_V2(a);   // a = -1, count = 32
    //int count = count_bit_one_V3(a); // a = -1, count = 32
    printf("count = %d\n", count);

    //-1
    //10000000000000000000000000000001 --原码
    //11111111111111111111111111111110 --反码
    //11111111111111111111111111111111 --补码
    // count == 32 
}

/*
Test07():
    两个int32位整数m和n的二进制表达中，有多少位bit不同
    0000 1111 == m
    0000 0000 == n

    0000 1111 == temp
    0000 1110 == temp-1

    temp&(temp-1)

    0000 1110 == temp
    0000 1101 == temp-1
    ...
*/
int get_diff_bit(int m, int n)
{
    int temp = m^n;//相同为0，相异为1
    int count = 0;
    //return count_bit_one(temp);
    while (temp)
    {
        temp = temp&(temp-1);
        count++;
    }
    return count;
}
void Test07()
{
    int m = 0;
    int n = 0;
    scanf("%d%d",&m,&n);
    int count = get_diff_bit(m,n);
    printf("count=%d\n", count);
}

/*
Test08():
    获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
*/
void print_Test08(int m)
{
    int i = 0;
    printf("ungerade Zahl\n");
    for ( i = 30; i >=0; i-=2)
    {
        printf("%d ", (m>>i)&1);
    }
    printf("\n");
    printf("gerade Zahl\n");
    for ( i = 31; i >=1; i-=2)
    {
        printf("%d ", (m>>i)&1);
    }
    printf("\n");
}
void Test08()
{
    int m = 0;
    scanf("%d", &m);
    print_Test08(m);
}

/*
Test09():
    遍历数组并打印
*/
void print(int *p, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ",*(p+i));
    }
}
void Test09()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(arr, sz);
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
