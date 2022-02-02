
#include<string.h>
#include"contact.h"
/*
实现函数的功能：

通讯录实现：
    1. 存放1000个好友的信息
        名字
        电话
        性别
        住址
        年龄
    2. 增加好友信息
    3. 删除指定名字的好友的信息
    4. 查找好友信息
    5. 修改好友信息
    6. 打印好友信息
    7. 排序
*/

void InitContact(struct Contact* ps)
{
    memset(ps->data, 0, sizeof(ps->data));
    ps->size = 0;//设置通讯录最初0个元素
}

void AddContact(struct Contact* ps)
{
    if (ps->size == MAX)
    {
        printf("通讯录已满，无法添加\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", ps->data[ps->size].name);
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[ps->size].age));
        printf("请输入性别:>");
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[ps->size].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[ps->size].addr);

        ps->size++;
        printf("添加成功\n");
    }
    
}

void ShowContact(const struct Contact* ps)
{
    if(ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    else 
    {
        int i = 0;
        //-20: 左对齐
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
        for ( i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                    ps->data[i].name,
                    ps->data[i].age,
                    ps->data[i].sex,
                    ps->data[i].tele,
                    ps->data[i].addr);
        }
        
    }
    
}

