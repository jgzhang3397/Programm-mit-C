//=====Struktur========
//结构体
//声明
//初始化
//成员访问
//传参

#include<stdio.h>
//Beschreibung eines Students, die Informationen
//Name, Alt, Nummer, Sex
//struct keyword des Struktures, Stu: Tag des Struktures
//struct Stu: 结构体类型
// struct Stu
// {
//     //成员变量
//     char name[20];
//     short age;
//     char tel[20];
//     char sex[5];
// }s1, s2, s3;//s1,s2,s3 globale Variante

// typedef struct Stu
// {
//     //成员变量
//     char name[20];
//     short age;
//     char tel[20];
//     char sex[5];
// }stud;

// int main()
// {
//     struct Stu s1={"Luna",88, "187666356262","Female"};//s lokale Variante
//     stud s2={"Lukas",12,"15247667911","Male"};
//     return 0;
// }

// struct S
// {
//     int age;
//     double d;
//     char arr[20];
// };
// struct T
// {
//     char arr[10];
//     struct S s;
//     char *pc;
// };
// int main()
// {
//     char arr[]="Hello";
//     struct T t = {"Hallo",{100,3.14,"HelloWorld"},arr};
//     printf("%s\n", t.arr);//Hallo
//     printf("%s\n", t.s.arr);//HelloWorld
//     printf("%lf\n",t.s.d);//3.14
//     printf("%s\n", t.pc);//Hello
//     return 0;
// }

typedef struct Stu
{
    //成员变量
    char name[20];
    short age;
    char tel[20];
    char sex[5];
}stud;
void Print1(stud temp)
{
    printf("Name ist %s\n", temp.name);
    printf("Age is %d\n", temp.age);
    printf("Telefnummer ist %s\n", temp.tel);
    printf("Geschelcht: %s\n", temp.sex);
}
void Print2(stud* ps)
{
    printf("Name ist %s\n", ps->name);
    printf("Age is %d\n", ps->age);
    printf("Telefnummer ist %s\n", ps->tel);
    printf("Geschelcht: %s\n", ps->sex);
}
int main()
{
    stud s = {"Lukas",55,"01637821509","Man"};
    Print1(s);
    Print2(&s);//besser..
}