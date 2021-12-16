#include<stdio.h>
#include<string.h>
//zweidim- Array erstellen
int main()
{
    int arr[3][4]={{1,2,3},{4,5}}; // drei Zeile und vier Spalten 三行四列
    int arr2[][4]={{1,2,3,4},{5,6,7,8}};// Zeile kann weglassen, aber Spalten kann nicht
    int i = 0;
    for(i=0; i<3; i++)
    {
        int j = 0;
        for(j=0; j<4; j++)
        {
            //printf("%d ", arr[i][j]);
            printf("&arr[%d][%d] = %p ", i, j, &arr[i][j]);
        }
        printf("\n");
    }
    //int arr3[2][]={{1,2,3},{4,5}};
}

// int main()
// {
//     // char arr1[] ="abcdefg";//[a] [b] [c] ... [\0]
//     // // int sz = sizeof(arr1)/sizeof(arr1[0]);
//     // // for(int i = 0; i<(sz-1); i++)
//     // // {
//     // //     printf("%c\n", arr1[i]);
//     // // }
//     // int len = strlen(arr1);
//     // for(int i = 0; i<len; i++)
//     // {
//     //     printf("%c\n", arr1[i]);
//     // }
//     int arr[]={1,2,3,4,5,6,7,8,9,0};
//     //int len = strlen(arr); es geht nicht, strlen() nur fuer char
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     for(int i = 0; i<sz; i++)
//     {
//         //printf("%d ", arr[i]);
//         printf("&arr[%d]= %p\n", i, &arr[i]);//数组中的内存是连续存放的
//     }
//     return 0;
// }
// int main()
// {
//     char arr1[]="abc"; //a b c \0
//     char arr2[]={'a','b','c'}; // a b c
//     printf("%lu\n", sizeof(arr1));//4
//     printf("%lu\n", sizeof(arr2));//3
//     printf("%d\n", strlen(arr1));//3
//     printf("%d\n", strlen(arr2));//Zufallswert, keine \0 gefunden 
//     return 0;
// }
// int main()
// {
//     //erstellen ein Array mit int, breite 10
//     // int arr1[10]={1,2,3};// geteilte Init, ausschliessend sind alle null
//     // char arr2[5]={'a', 98};
//     // char arr3[5]="abcd";
//     // char arr4[]="abcdefg";
//     // printf("%d\n", sizeof(arr4)); //8
//     // printf("%d\n", strlen(arr4)); //7
//     // int n = 5;
//     // char arr3[n]; es geht nicht, nur const keine variante
//     return 0;
// } 