#include <stdio.h>

// int main()
// {
//     int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     int *ptr1 = (int *)(&aa + 1);//&aa代表着数组的首地址 &aa + 1 代表数组末尾的地址就是10后面, ptr1 --> 10 ++
//     int *ptr2 = (int *)(*(aa + 1));//aa是首元素地址，首元素是第一行 aa + 1 是第二行， 
//     //加*解引用就是第二行的数组名aa[1],就是第二行首元素地址，ptr2 --> 6

//     printf("%d,%d\n", *(ptr1 - 1), *(ptr2 -1));// 10 , 5

//     return 0;
// }

// int main()
// {
//     char* a[] = {"work", "in", "germany"};//字符指针数组
//     char** pa = a;//char* 数组类型 **解引用 数组首元素

//     pa++;//跳过一个char* 因为char** 比如 int * p+1 跳过一个整型int
//     printf("%s\n", *pa);//in
//     return 0;
// }

/*
c数组：
    char* "ENTER"
    char* "NEW"
    char* "POINT"
    char* "FIRST"
cp数组：
    char** c + 3   ==>        char* "FIRST"
    char** c + 2   ==>        char* "POINT"
    char** c + 1   ==>        char* "NEW"
    char** c       ==>        char* "ENTER"
cpp类型char*** 指向cp数组首元素地址

*/
int main()
{
    char* c[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char** cp[] = {c+3, c+2, c+1, c};
    char*** cpp = cp;

    printf("%s\n", **++cpp);//++cpp cp数组第二个元素地址，两次解引用得到 POINT
    printf("%s\n", *--*++cpp + 3);//++cpp cp数组第三个元素地址，解引用得到c + 1 然后-- 就是c 然后解引用就是得到 ENTER
    //再加3 得到ER
    printf("%s\n", *cpp[-2] + 3);//cpp[-2] ==> *(cpp -2) 表示cp数组第一个元素地址 再解引用是 FIRST 再加3 ==> ST
    printf("%s\n", cpp[-1][-1] + 1);//cpp[-1] ==> *(cpp -1)  cp数组第二个元素地址 ==> *（*（cpp-1））-1 ==》*（c + 2 -1)
    //*(c + 1) ==> NEW ==> +1 ==> EW
    return 0;
}