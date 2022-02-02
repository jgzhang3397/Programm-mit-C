#include<stdio.h>
#include"contact.h"
#include"contact.c"

void menu()
{
    printf("**************************************************\n");
    printf("********* 1. add              2. del    **********\n");
    printf("********* 3. search           4. modify **********\n");
    printf("********* 5. show             6. sort   **********\n");
    printf("********* 0. exit                       **********\n");
    printf("**************************************************\n");
}

int main()
{
    int input = 0;
    //创建通讯录
    struct Contact con;//con 就是通讯录，里面包含 1000个元素的数和size
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            AddContact(&con);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            ShowContact(&con);
            break;
        case 6:
            /* code */
            break;
        case 0:
            printf("退出通讯录\n");
            break;
        default:
            printf("选择错误\n");
        }
    } while (input);
    
    return 0;
}