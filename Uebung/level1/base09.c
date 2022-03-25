#include<stdio.h>
/*
Test01()&Test02():
    描述
    凯刚写了一篇美妙的作文，请问这篇作文的标题中有多少个字符？
    注意：标题中可能包含大、小写英文字母、数字字符、空格和换行符。统计标题字 符数时，空格和换行符不计算在内。

    输入描述：
    输入文件只有一行， 一个字符串s。

    输出描述：
    输出文件只有一行，包含一个整数，即作文标题的字符数（不含空格和换行符）。
*/
void Test01()
{
    char c;
    int count = 0;
    while(scanf("%c", &c)!=EOF)
    {
        if((c!=' ') && (c!='\n'))
            count++;
    }
    printf("%d\n", count);
}

/*
    char * gets ( char * str );
        Get string from stdin
*/
#include<stdlib.h>
#include<string.h>
void Test02()
{
    int n;
    int count = 0;
    char* s = (char *)malloc(n*sizeof(char));
    if(s==NULL)
    {
        fprintf(stderr, "Memory allocation Failed!\n");
        exit(0);
    }
    gets(s);//用gets 是因为其可以输出数组中的空格，而scanf不能
    int sz = strlen(s);
    int i = 0;
    for(i=0; i<sz; i++)
    {
        if(*(s+i) != ' ')
            count ++;
    }
    printf("%d\n", count);
    free(s);
    s = NULL;

}

/*
Test03()&Test04():
    描述
    有个软件系统登录的用户名和密码为（用户名：admin，密码：admin），用户输入用户名和密码，判断是否登录成功。
    输入描述：
    多组测试数据，每行有两个用空格分开的字符串，第一个为用户名，第二个为密码。
    输出描述：
    针对每组输入测试数据，输出为一行，一个字符串（“Login Success!”或“Login Fail!”）。  

    输入：
    admin admin
    
    输出：
    Login Success!

    输入：
    admin abc
    
    输出：
    Login Fail!
*/

void Test03()
{
    char name[] = "admin";
    char pin[] = "admin";
    char input1[10] = {0};
    char input2[10] = {0};

    while (scanf("%s %s", input1, input2)!=EOF)
    {
        if(strcmp(name, input1)==0 && strcmp(pin, input2)==0)
            printf("Login Success!\n");
        else
            printf("Login Fail!\n");
    }
    
}

//不用字符操作函数
void Test04()
{
    int i = 0;
    char pins[10] = "admin";
    char inputs1[10];
    char inputs2[10];
    while (scanf("%s %s", inputs1, inputs2)!=EOF)
    {
        while (pins[i] != '\0')
        {
            if(inputs1[i]==pins[i] && inputs2[i]==pins[i])
                i++;
            else
                break;
        }
        if(pins[i]=='\0')
            printf("Login Success!\n");
        else
            printf("Login Fail!\n");
    } 
}

/*
Test05()&Test06():
    输入描述：
    只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。
    输出描述：
    共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”；
    第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。

    示例1
        输入：
        error

        输出：
        Lucky Word
        2
    说明：
    单词error中出现最多的字母r出现了3次，出现次数最少的字母出现了1次，3-1=2，2是质数。 
*/

void Test05()
{
    char arr[100];
    //理论单词不出现空格
    scanf("%s", arr);
    int sum = 0, maxn=0, minn=100;
    int sz = strlen(arr);
    int i, j;
    int flag = 0;
    //sz*sz次遍历数组，通过sum++得到maxn和minn
    for(i=0; i<sz; i++)
    {
        for(j=0; j<sz; j++)
        {
            if(arr[j]==arr[i])
                sum++;
        }

        if(sum>maxn)
            maxn = sum;
        if(sum<minn)
            minn = sum;

        sum = 0;
    }

    //判断是否为素数
    int result = maxn - minn;
    for(i=2; i<result; i++)
    {
        if(result%i==0)//如果被除自身只外的数整除，不是素数
        {
            flag = 1;
            break;
        }
    }
    if(result == 1 || result == 0)
        flag = 1;
    if(flag == 1)
        printf("No Answer\n0\n");
    else
        printf("Lucky Word\n%d\n", result);

}

void Test06()
{
    int arr[26] = {0};
    int maxn = 0, minn = 100;
    int i = 0;
    char a;
    int result;
    //计算每个26个字母出现的次数
    while (scanf("%c", &a)!=EOF)
    {
        arr[a-'a']++;
        if(a=='\n')
            break;
    }
    for(i=0; i<26; i++)
    {
        if(arr[i]>maxn)
            maxn = arr[i];
        if(arr[i]>0 && arr[i]<minn)
            minn = arr[i];
    }
    result = maxn - minn;
    if(result < 2)
        printf("No Answer\n0\n");
    else
    {
        for(i=2; i<result; i++)
        {
            if(result%i==0)
                printf("No Answer\n0\n");
            break;
        }
        printf("Lucky Word\n%d", result);
    }  
}

/*
Test07()&Test08():
    描述
    对于一个较大的整数 N(1<=N<=2,000,000,000)
    比如 980364535，我们常常需要一位一位数这个数字是几位数，但是如果在这 个数字每三位加一个逗号，它会变得更加易于朗读。
    因此，这个数字加上逗号成如下的模样：980,364,535请写一个程序帮她完成这件事情

    输入描述：
    一行一个整数 N
    输出描述：
    一行一个字符串表示添加完逗号的结果

    示例1
        输入：
        980364535
        输出：
        980,364,535
*/

void insert(int sz, int x, char arr[sz], char c)
{
    int i;
    char temp;
    temp = arr[x];//避免x下标的元素被覆盖，所以将其转移到temp
    arr[x] = c;
    // for(i=1; i<sz-x; i++)
    // {
    //     arr[sz+1-i] = arr[sz-i];//加一位向后移
    // }
    for(i=sz-1; i>x; i--)
    {
        arr[i+1] = arr[i];////加一位向后移
    }
    arr[x+1] = temp;

}
void Test07()
{
    char arr[13];
    scanf("%s", arr);
    int sz = strlen(arr);
    int i;
    for(i=3; (sz>3)&&(i<sz); i+=3)
        insert(sz, sz-i, arr, ',');
    printf("%s", arr);
}

void Test08()
{
    char arr[15] = {0};
    scanf("%s", arr);
    int i = 0, j=0;
    int ret = 3;
    int len = strlen(arr);
    for(i=len-1; i>=0; i--)
    {
        if(j==ret)
        {
            ret+=4;//',xxx'整体后移
            for(int m=len; m>i; m--)
            {
                arr[m] = arr[m-1];
            }
            arr[i+1]=',';
            len++;//加了一个逗号，数组长度+1
            j++;
        }
        j++;
    }
    printf("%s", arr);
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
    Test08();
    return 0;
}
