#include<stdio.h>
#include<string.h>

/*
判断字符串arr2 是否是 arr1  旋转后的字符串，如果是yes，不是no
*/
//Loesung2
//使得arr1 ==》abcdefabcdef，arr2是其子集则ret == 1
/*
strcat的使用：在一个字符串后追加另一个字符串
*/
//#include<string.h>
// int main()
// {
//     char arr1[30] = "abc";//arr1作为目标数组，必须给定大小范围
//     char arr2[] = "edf";
//     strcat(arr1, arr2);
//     printf("%s\n", arr1);
//     return 0;   
// }
/*
strncat的使用：可以复制相同的字符串
*/
// int main()
// {
//     char arr1[30] = "abcdef";
//     strncat(arr1, "abcdef", 3);
//     printf("%s\n", arr1);
//     return 0;
// }

int is_left_move(char* arr1, char* arr2)
{
    //判断arr2是否是与arr1相等
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    if(len1 != len2)
        return 0;
    
    //strncat不能追加相同名称的字符串可能是编译器问题？必须将arr1拷贝给arr3
    char arr3[30];
    strcpy(arr3, arr1);
    //1.在arr1字符串中加一个arr1字符串
    //strcat(arr1, arr1);//不能自己给自己追加，负责找不到‘/0’ 而导致程序崩溃
    strncat(arr1, arr3, len1);
    //2.判断arr2是否是arr1指向字符串的子集
    //strstr --找子串
    char* ret = strstr(arr1, arr2);
    if(ret == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    char arr1[6] = "abcdef";
    char arr2[] = "cdefab";
    int ret = is_left_move(arr1, arr2);
    if(ret == 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}