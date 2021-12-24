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
#include<assert.h>
void my_strcpy(char* dest, char* src)
{
    assert(dest != NULL);
    assert(src != NULL);
    // if(dest != NULL && src != NULL)
    // {
        while (*dest++ = *src++)
        {
            ;
        }
    // }
}
int main()
{
    //strcpy
    char arr1[]="#######################";
    char arr2[]="bit";
    my_strcpy(arr1, arr2);
    printf("%s\n", arr1);
}