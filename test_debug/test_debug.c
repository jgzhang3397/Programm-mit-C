//===========Vorstellung : Wie kann man die code debuggen, die Bug finden

//Beispiele
#include<stdio.h>

// int main()
// {
//     int i = 0;
//     int sum = 0;//behalt die endliche Resulte
//     int n = 0;
//     int ret = 1;//behalt die Fakytaet von n
//     scanf("%d", &n);
//     for (int i = 1; i <=n; i++)
//     {
//         ret = 1;
//         for (int j = 1; j<=i; j++)
//         {
//             ret *= j;
//         }
//         sum += ret;
//     }
//     printf("%d\n", sum);
//     return 0;
    
// }

// int main()
// {
//     int i = 0;
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     printf("%p\n", arr);
//     printf("%p\n", &i);
//     for (int i = 0; i <=sz; i++)//越界访问, i<sz
//     {
//         printf("hehe\n");
//         arr[i] = 0;//wenn die Addresse von arr[10] == i, endlossschleife
//     }
//     return 0;
// }

#include<string.h>
// void my_strcpy(char* dest, char* src)
// {
//     while (*src !='\0')
//     {
//         *dest = *src;
//         src++;
//         dest++;
//     }
//     *dest = *src;
// }
//============Optimerung
// void my_strcpy(char* dest, char* src)
// {
//     while (*src !='\0')
//     {
//         *dest++ = *src++;
//         // src++;
//         // dest++;
//     }
//     *dest = *src;
// }
//=============Optimerung weiter
// #include<assert.h>
// char* my_strcpy(char* dest, const char* src)
// {
//     char* ret = dest;
//     assert(dest != NULL);//断言
//     assert(src != NULL);
//     // if(dest != NULL && src != NULL)
//     // {
//         //把src指向的字符串拷贝到dest指向的空间，包含‘\0’字符
//         while (*dest++ = *src++)
//         {
//             ;
//         }
//     // }
//     return ret;
// }
// int main()
// {
//     //strcpy
//     char arr1[]="#######################";
//     char arr2[]="bit";
//     my_strcpy(arr1, arr2);
//     printf("%s\n", arr1);
// }

// int main()
// {
//     const int num = 10;//num kann nicht aendern
//     //const int* p = &num;
//     // *p = 20;//error const 放在指针变量的*左边时，修饰的是 *p，不能通过p来改变*p（num）的值

//     // int* const p = &num;
//     // //const 放在*右边，修饰的是指针变量p本身，p不能被改变
//     // int n = 100;
//     // p = &n;

//     const int* const p = &num;
//     *p = 20;
//     int n = 100;
//     p = &n;
//     printf("%d\n", num);
//     //printf("%d\n", *p);
//     return 0;
// }

#include<assert.h>
int my_strlen(const char* arr)//*arr 的内容不被改变
{
    int count = 0;
    assert(arr != NULL);//保证指针的有效性 不能为空指针
    while (*str != '\0')
    {
        count++;
        *str++;
    }
    return count;
}
int main()
{
    char arr[]="abcdef";
    int len = my_strlen(arr);
    printf("%d\n", len);
    return 0;
}