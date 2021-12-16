#include<stdio.h>
// void bubble_sort(int arr[], int sz)
// {
//     //确定冒泡排序的趟数
//     int i = 0;
//     //int sz = sizeof(arr)/sizeof(arr[0]);
//     for(i=0; i<sz-1; i++)
//     {
//         int flag = 1;//假设已经有序
//         //Inhalt
//         int j = 0;
//         for(j=0; j<sz-1-i; j++)
//         {
//             int temp = 0;
//             temp = arr[j];
//             arr[j]=arr[j+1];
//             arr[j+1]=temp;
//             flag = 0;//nicht in Ordnung
//         }
//         if(flag==1)
//         {
//             break;
//         }
//     }
// }
// int main()
// {
//     int arr[] = {10,9,8,7,6,5,4,3,2,1};
//     int i = 0;
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     //对arr进行排序，升序
//     //arr是数组，对数组arr进行传参，传的是&arr[0]
//     bubble_sort(arr, sz);
//     for(i=0; i<sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

int main()
{
    int arr[]={1,2,3};
    //beide sind gleich Addresse arr= &arr[0]
    printf("%p\n", arr);
    printf("%p\n", arr+1);

    printf("\n%p\n", &arr[0]);
    printf("%p\n", &arr[0]+1);
    //printf("%d\n", *arr);//1
    //2mal Besonders
    //1.sizeof(arr)bedeutet die ganze Breite von Arrays 
    //2.&arr bedeutet die ganz Addresse von Arrays
    printf("\n%p\n", &arr);
    printf("%p\n", &arr+1);
    
}