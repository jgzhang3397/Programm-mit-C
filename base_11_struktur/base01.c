#include<stdio.h>
/*
=====Struktur========
    结构体
    声明
    初始化
    成员访问
    传参
*/
/*
Test01():
    Beschreibung eines Students, die Informationen
    Name, Alt, Nummer, Sex
    struct keyword des Struktures, Stu: Tag des Struktures
    struct Stu: 结构体类型
*/
struct Stu01
{
    //成员变量
    char name[20];
    short age;
    char tel[20];
    char sex[10];
}s1, s2, s3;//s1,s2,s3 globale Variante

typedef struct Stu02
{
    //成员变量
    char name[20];
    short age;
    char tel[20];
    char sex[10];
}stud01;

void Test01()
{
    struct Stu01 s1={"Luna",88, "187666356262","Female"};//s lokale Variante
    stud01 s2={"Lukas",12,"15247667911","Male"};
    printf("%s %d %s %s\n", s1.name, s1.age, s1.tel, s1.sex);
    printf("%s %d %s %s\n", s2.name, s2.age, s2.tel, s2.sex);
    
}

/*
Test02():
    结构体之间会互相调用
*/
struct S
{
    int age;
    double d;
    char arr[20];
};
struct T
{
    char arr[10];
    struct S s;
    char *pc;
};

void Test02()
{
    char arr[]="Hello";
    struct T t = {"Hallo",{100,3.14,"HelloWorld"},arr};
    printf("%s\n", t.arr);//Hallo
    printf("%s\n", t.s.arr);//HelloWorld
    printf("%lf\n",t.s.d);//3.14
    printf("%s\n", t.pc);//Hello
}

/*
Test03():
    结构体类型传参：
        传值：s1.age ...
        传址：ps-> age ... (ps: 结构体指针)
*/
typedef struct Stu
{
    //成员变量
    char name[20];
    short age;
    char tel[20];
    char sex[5];
}stud02;

void Print1(stud02 temp)
{
    printf("Name ist %s\n", temp.name);
    printf("Age is %d\n", temp.age);
    printf("Telefnummer ist %s\n", temp.tel);
    printf("Geschelcht: %s\n", temp.sex);
}
void Print2(stud02* ps)
{
    printf("Name ist %s\n", ps->name);
    printf("Age is %d\n", ps->age);
    printf("Telefnummer ist %s\n", ps->tel);
    printf("Geschelcht: %s\n", ps->sex);
}

void Test03()
{
    stud02 s = {"Lukas",55,"01637821509","Man"};
    Print1(s);
    Print2(&s);//besser..
}

int main()
{
    //Test01();
    //Test02();
    Test03();
    return 0;
}

