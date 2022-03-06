#include<stdio.h>
#include<string.h>
/*
Test01():
    Create twodim array
*/
void Test01()
{
    int arr[3][4]={{1,2,3},{4,5}}; // drei Zeile und vier Spalten three rows and four columns 三行四列
    int arr2[][4]={{1,2,3,4},{5,6,7,8}};// Zeile kann weglassen, aber Spalten kann nicht
    int i = 0;
    for(i=0; i<3; i++)
    {
        int j = 0;
        for(j=0; j<4; j++)
        {
            printf("%d ", arr[i][j]);
            //printf("&arr[%d][%d] = %p ", i, j, &arr[i][j]);//print addresse
        }
        printf("\n");
    }
}

/*
Test02()&Test03():
    size_t strlen ( const char * str ); only for char
*/
void Test02()
{
    char arr1[] ="abcdefg";//[a] [b] [c] ... [\0]
    
    int len = strlen(arr1); //7
    int sz = sizeof(arr1)/sizeof(arr1[0]);//sz = len + 1 = 8
    for(int i = 0; i<len; i++)
    {
        printf("%c ", arr1[i]);
    }
}

/*
    //it doesn't work, strlen() only for char
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    int len = strlen(arr); 
*/
void Test03()
{
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    
    int sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<sz; i++)
    {
        printf("%d\n", arr[i]);
        printf("&arr[%d]= %p\n", i, &arr[i]);//数组中的内存是连续存放的 
        //The memory in the array is stored contiguously
    }
}

void Test04()
{
    char arr1[]="abc"; //a b c \0
    char arr2[]={'a','b','c'}; // a b c
    printf("%lu\n", sizeof(arr1));//4
    printf("%lu\n", sizeof(arr2));//3
    printf("%lu\n", strlen(arr1));//3
    printf("%lu\n", strlen(arr2));// Random value, no \0 found
}

void Test05()
{
    //create an array with int, width 10
    int arr1[10]={1,2,3};// shared init, excluding all are null
    char arr2[5]={'a', 98};// 'a' 'b' '\n' ....
    char arr3[5]="abcd";// 'a' 'b' 'c' 'd' '\0'
    char arr4[]="abcdefg";

    printf("%lu\n", sizeof(arr4)); //8
    printf("%lu\n", strlen(arr4)); //7

    // int n = 5;
    // char arr3[n]; //es geht nicht, nur const keine variante
}

/*
Test06():
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    对arr进行排序，升序
    arr是数组，对数组arr进行传参，传的是&arr[0]
    冒泡排序
*/
void bubble_sort(int arr[], int sz)
{
    int i = 0;
    for(i=0; i<sz-1; i++)
    {
        //int flag = 1;//假设已经有序
        
        int j = 0;
        for(j=0; j<sz-1-i; j++)
        {
            int temp = 0;
            temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;

            //flag = 0;
        }
        // if(flag==1)
        // {
        //     break;
        // }
    }
}

void Test06()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    
    bubble_sort(arr, sz);//arr = &arr[0]
    for(i=0; i<sz; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Test07()
{
    int arr[]={1,2,3};

    //both are the same Address arr= &arr[0]
    printf("%p\n", arr);
    printf("%p\n", arr+1);//相差4

    printf("\n%p\n", &arr[0]);
    printf("%p\n", &arr[0]+1);

    printf("%d\n", *arr);//1

    /*
        1.sizeof(arr)bedeutet die ganze Breite von Arrays 
        2.&arr bedeutet die ganz Addresse von Arrays
    */
    printf("\n%p\n", &arr);
    printf("%p\n", &arr+1);//相差12
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
