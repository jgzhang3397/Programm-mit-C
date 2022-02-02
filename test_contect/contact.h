#ifndef _TEST
#define _TEST
/*
error redefinition of 'xxx':
    1. .H文件没有进行
        #ifndef xxx
        #define xxx
        xxx
        #endif
    这种限制。
*/

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

struct PersonInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

//通讯录类型
struct Contact
{
    struct PersonInfo data[MAX];//存放一个信息
    int size; //记录当前已有的元素个数
};

#endif 


//声明函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);//只显示，不修改
