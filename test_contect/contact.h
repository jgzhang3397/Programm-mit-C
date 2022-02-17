#ifndef _TEST
#define _TEST
#include<string.h>
#include<stdlib.h>
#include<errno.h>
/*
error redefinition of 'xxx':
    1. .H文件没有进行
        #ifndef xxx
        #define xxx
        xxx
        #endif
    这种限制。
*/
enum Option
{
    EXIT,//0
    ADD,//1
    DEL,//2
    SEARCH,//3
    MODIFY,//4
    SHOW,//5
    SORT,//6
    SAVE//7
};

//#define MAX 1000
#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

typedef struct PersonInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}PeopleInfo;

//通讯录类型--动态增长
typedef struct Contact
{
    struct PersonInfo *data;//存放一个信息
    int size; //记录当前已有的元素个数
    int capacity; //记录通讯录最大容量
}Contact;

#endif

//声明函数

//初始化通讯录
void InitContact(struct Contact* ps);

//添加好友信息
void AddContact(struct Contact* ps);

//显示好友信息
void ShowContact(const struct Contact* ps);//只显示，不修改-- const

//删除指定好友信息
void DelContact(struct Contact* ps);

//查找指定好友信息
void SearchContact(const struct Contact* ps);

//查找指定好友信息
void ModifyContact(struct Contact* ps);

//
void DestroyContact(Contact* ps);

//保存到文件
void SaveContact(Contact* ps);

//加载文件中的信息到通讯录
void LoadContact(Contact* ps);

void CheckCapacity(Contact* ps);

