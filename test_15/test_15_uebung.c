#include<stdio.h>
// //实现init（）初始化数组全为0
// //printf jeder Vektor darin
// //reverse() 数组元素逆置
// void init(int arr[], int sz)
// {
//     for (int i = 0; i < sz; i++)
//     {
//         arr[i] = 0;
//     }
    
// }
// void my_print(int arr[], int sz)
// {
//     for(int i = 0; i< sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
// void reverse(int arr[], int sz)
// {
//     // for (int i = 0; i < sz; i++)
//     // {
//     //     arr[i]=arr[sz-i];
//     // }  
//     int left = 0;
//     int right = sz -1;
//     while (left<right)
//     {
//         int temp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = temp;
//         left++;
//         right--;
//     }
// }
// int main()
// {
//     int arr[]={1,2,3,4,5,6,7,8,9,10};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     //init(arr, sz);
//     my_print(arr, sz);
//     reverse(arr, sz);
//     my_print(arr, sz);
//     return 0;
// }

// ////die Inhalt zweies Arrays umtauschen
// int main()
// {
//     int arr1[]={1,3,5,7,9};
//     int arr2[]={2,4,6,8,0};
//     int sz = sizeof(arr1)/sizeof(arr1[0]);
//     int temp =0;
//     for (int i = 0; i < sz; i++)
//     {
//         temp = arr1[i];
//         arr1[i] = arr2[i];
//         arr2[i] = temp;
//     }
//     return 0;
// }

// int main()
// {
//     int arr[]={1,2,3,4,5};
//     short* p = (short*)arr;
//     for (int i = 0; i < 4; i++)
//     {
//         *(p+i) = 0;
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// int main()
// {
//     int a = 0x11223344;
//     char *pc = (char*)&a;//44332211-->00332211
//     *pc = 0;
//     printf("%x\n", a);//0x11223300
// }

int i;//Globale Variante, == 0
int main()
{
    i--;
    //-1
    //10000000000000000000000000000001 --原码
    //11111111111111111111111111111110 --反码
    //11111111111111111111111111111111 --补码=反码+1
    if(i > sizeof(i))// sizeof ist unsigned int immer gross null, so i ist auch unsigned int
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}