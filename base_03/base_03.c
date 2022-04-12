#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*
// 问：下列代码中for循环了几次
// 答：0次，因为j=0 不是判断

int main()
{
    int i=0 , j = 0;
    for(i=0,j=0;j=0;i++,j++)
    {
        j++;
    }
    return 0;
}
*/

/*
Test01():
    Enter the password three times
    if 3 times wrong then quit
*/

void Test01()
{
    int i = 0;
    char password[20] = {0}; // password[]
    int n = 3;
    for ( i = 0; i < n; i++)
    {
        printf("Please enter the Password:>>>");
        scanf("%s", password);

        /*
        int strcmp ( const char * str1, const char * str2 );
            Compares the C string str1 to the C string str2.

            This function starts comparing the first character of each string. 
            If they are equal to each other, it continues with the following pairs 
            until the characters differ or until a terminating null-character is reached.
        
        return value	indicates
            <0	        the first character that does not match has a lower value in ptr1 than in ptr2
            0	        the contents of both strings are equal
            >0	        the first character that does not match has a greater value in ptr1 than in ptr2


        */

        if(strcmp(password,"123456")==0)// can not compare two char, should use 'strcmp'
        {
            printf("Password correct!\n");
            break;
        }
        else
        {
            printf("Password wrong!!!\n");
        }
    }
    if(i==3)
    {
        printf("FBI!! open the door:)\n");
        exit(0);
    }
}

/*
Test02():
    Willkommen zu mir!!!

    ####################
    W##################!
    Wi################!!
        ......
    Willkommen zu mir!!!

    Tips:
        Linux - gcc - #include <unistd.h> -- sheep(s)
        VC    - #include <windows.h> -- Sheep(ms)
*/
void Test02()
{
    char arr1[] = "123456789";
    char arr2[] = "*********";
    int left = 0;

    int len = sizeof(arr1)/sizeof(arr1[0]);//len = 10

    /*
    为什么-2？
    因为数组总长度是10，arr1[9] = '\0', arr1[0] - arr1[8] ==> '123456789'
    */
    //int right = sizeof(arr1)/sizeof(arr1[0])-2;

    /*
    size_t strlen ( const char * str );
        Returns the length of the C string str. except '\0'

    */

    int right = strlen(arr1)-1;
    while (left<=right)
    {
        arr2[left]=arr1[left];
        arr2[right]=arr1[right];
        printf("%s\n",arr2);
        sleep(1);//1s
        left++;
        right--;
    }
}

/*
Test03(): 
    Find a value by traversing(遍历) a sorted(有序的) array
*/
void Test03()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr)/sizeof(arr[0])-1;//9

    int k = 0;
    printf("Please enter the value:>>>");
    scanf("%d",&k);

    int i = 0;
    for(i=0; i<sz; i++)
    {
        if(k == arr[i])
        {
            printf("found it. put it on arr[%d], the %d.th number\n", i, arr[i]);
            break;
        }
    }
    if(i == sz)
    {
        printf("not found it\n");
    }
}

/*
Test04(): binary search(二分法查找)
    Find a value by traversing(遍历) a sorted(有序的) array
*/
void Test04()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr)/sizeof(arr[0]);//sz = 10
    int left = 0;
    int right = sz -1; //9
    int k = 0;
    printf("Please enter the value:>>>");
    scanf("%d",&k);

    while (left <= right)
    {
        int mid = (left + right)/2;
        if (arr[mid]>k)
        {
            right = mid -1;
        }
        else if (arr[mid]<k)
        {
            left = mid +1;
        }
        else
        {
            printf("found it. put it on arr[%d], the %d.th number\n", mid, arr[mid]);
            break;
        }
    }
    if(left>right)
        printf("not found it\n");
}

/*
Test05(): calculate 4! + 3! + 2! +1!
*/
void Test05()
{
    int i = 0;
    int erg = 1;
    int n = 0;
    int sum = 0;
    for (n=1; n<=4; n++)
    {
       erg = 1;
       for(i=1; i<=n; i++)
       {
          erg = erg * i;
       }
       sum = sum + erg;
    }
    printf("Sum = %d\n", sum);
}

/*
Test06(): optimize Test05()
*/
void Test06()
{
    int n = 0;
    int erg = 1;
    int sum = 0;
    for(n=1; n<=4; n++)
    {
        erg = erg * n;
        sum = sum + erg;
    }  
    printf("Sum = %d\n", sum);
}

/*
Test07(): Calculate n!
*/
void Test07()
{
    int erg = 1;
    int n = 0;
    int i = 0;
    printf("please enter n:>>>");
    scanf("%d", &n);
    for(i = 1; i<=n; i++)
    {
        erg = erg * i;
    }
    printf("The result: %d\n", erg);
}

/*
Test08():
Only outputs 0 to 9 Integer
*/

void Test08()
{
    int ch = 0;
    while ((ch=getchar()) != EOF)
    {
        if(ch<'0' || ch>'9')
           continue;
        putchar(ch);
    }
}

void Test09()
{
    int ch = 0;
    int ret = 0;
    char password[20]={0};
    printf("Please enter Password:>>>>");
    scanf("%s", password);

    /*
        缓冲区还剩一个‘\n'
        通过getchar（）读取‘\n'
        scanf结束标志是空格和回车 所以password里面不能有空格

        换行对应的asii码值是10
        10 = getchar() == ‘\n';
    */
    while ((ch = getchar()) != '\n')
    {
        ;//为了消耗换行输入
    }

    printf("please confirm (Y/N):>>>");
    ret = getchar();
    if(ret == 'Y' || ret == 'y')
    {

        printf("thank you!\n");
        printf("%s\n", password);
    }
    else
    {
        printf("schame...") ;
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
    //Test07();
    //Test08();
    Test09();
    return 0;
    
}
