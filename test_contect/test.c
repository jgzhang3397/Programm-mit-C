#include<stdio.h>
#include"contact.h"
#include"contact.c"

void menu()
{
    printf("**************************************************\n");
    printf("********* 1. add              2. del    **********\n");
    printf("********* 3. search           4. modify **********\n");
    printf("********* 5. show             6. sort   **********\n");
    printf("********* 7. save             0. exit   **********\n");
    printf("**************************************************\n");
}

int main()
{
    int input = 0;
    //创建通讯录
    struct Contact con;//con 就是通讯录，里面包含data指针和size，capacity
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD://增加代码的可读性，使用enum
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);
            break;
        case MODIFY://修改
            ModifyContact(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            /* code */
            break;
        case EXIT:
            SaveContact(&con);
            //销毁通讯录-释放动态开辟的内存 free释放内存，防止内存泄漏
            DestroyContact(&con);
            printf("退出通讯录\n");
            break;
        case SAVE:
            SaveContact(&con);
            break;
        default:
            printf("选择错误\n");
        }
    } while (input);
    
    return 0;
}