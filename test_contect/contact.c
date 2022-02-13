
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
    ps->data = (struct PersonInfo*) malloc(DEFAULT_SZ*sizeof(struct PersonInfo));
    if(ps->data == NULL)
    {
        return;
    }
    ps->size = 0;//设置通讯录最初0个元素
    ps->capacity = DEFAULT_SZ;//初始容量是3个

    //memset(ps->data, 0, sizeof(ps->data));
   
}

void CheckCapacity(struct Contact* ps)
{
    if(ps->size == ps->capacity)
    {
        //增容
        struct PersonInfo* ptr = realloc(ps->data, (ps->capacity+2)*sizeof(PeopleInfo));//typedef 可以改名不加struct
        if(ptr != NULL)
        {
            ps->data = ptr;
            ps->capacity += 2;
            printf("增容成功\n");
        }
        else
        {
            printf("增容失败\n");
        }
    }
}

void AddContact(struct Contact* ps)
{
    //检查当前通讯录容量
    //1.如果满了，就增容
    //2.如果不满，啥事不干
    CheckCapacity(ps);
    //增加数据
    // if (ps->size == MAX)
    // {
    //     printf("通讯录已满，无法添加\n");
    // }
    // else
    // {
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
    // }
    
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

static int FindByName(const struct Contact* ps, char name[MAX_NAME])
//static关键字 这个函数只能在源文件内部可以看到
{
    int i = 0;
    for ( i = 0; i < ps->size; i++)
    {
        if (0 == strcmp(ps->data[i].name,name))//字符比较用strcmp
        {
            return i;//找到返回名字元素的下标
        }
    }
    return -1;//找不到返回-1
}

void DelContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要删除人的名字:>");
    scanf("%s", name);
    //1.查找要删除的人在的位置
    int pos = FindByName(ps, name);
    
    //2.删除
    if(pos == -1)
    {
        printf("要删除的人不存在\n");
    }
    else
    {
        //删除数据
        int j = 0;
        for ( j = pos; j < ps->size-1 ; j++)
        {
            ps->data[j] = ps->data[j+1]; //i处的元素删除，其后面的元素向前一位覆盖
        }
        ps->size--;
        printf("删除成功\n");
    }
}

void SearchContact(const struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("要查找的人不存在\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                ps->data[pos].name,
                ps->data[pos].age,
                ps->data[pos].sex,
                ps->data[pos].tele,
                ps->data[pos].addr);
    }
    
}

void ModifyContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要修改人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if(pos == -1)
    {
        printf("要修改的人不存在\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", ps->data[pos].name);
        printf("请输入年龄:>");
        scanf("%d", &(ps->data[pos].age));
        printf("请输入性别:>");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[pos].addr);
    }
    printf("修改成功\n");
}

void DestroyContact(Contact* ps)
{
    free(ps ->data);
    ps->data = NULL;
}

