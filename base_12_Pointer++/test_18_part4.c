#include<stdio.h>
#include<string.h>
//=========自定义qsort函数-->bubble_sort==========
struct stu
{
    char name[20];
    int age;
};
int cmp_int(const void* e1, const void* e2)
{
    //比较两个整型值的
    return *(int*)e1 - *(int*)e2;
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
    return ((struct stu*) e1)->age - ((struct stu*) e2)->age;
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
    //比较名字就是比较字符串
    //字符串比较不能直接用><=来比较， 应该用strcmp函数
    return strcmp(((struct stu*) e1)->name , ((struct stu*) e2)->name);
}
void Swap(char* buf1, char* buf2, int width)
{
    int i = 0;
    for ( i = 0; i < width; i++)
    {
        char temp = *buf1;
        *buf1 = *buf2;
        *buf2 = temp;
        buf1++;
        buf2++;
    }
    
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
    int i = 0;
    //趟数
    for ( i = 0; i < sz-1; i++)
    {
        //每一趟比较的对数
        int j = 0;
        for(j = 0; j<sz - i; j++)
        {
            //两个元素比较
            if(cmp((char*)base + j*width , (char*)base + (j+1)*width) > 0)
            {
                //交换
                Swap((char*)base + j*width, (char*)base + (j+1)*width , width);
            }
        }
    }
    
}
void test4()
{
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
    int i = 0;
    for ( i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
}
void test5()
{
    struct stu s[3] = {{"zaver", 22}, {"lukas", 13}, {"anna", 8}};
    int sz = sizeof(s)/sizeof(s[0]);
    bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}
int main()
{
    test4();
    //test5();
    return 0;
}


