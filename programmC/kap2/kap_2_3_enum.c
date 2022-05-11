#include<stdio.h>

enum boolean {no, yes};

enum week {montag=1, dienstag, mittwoch, donestag, freitag, samstag, sonntag};
int main()
{
    printf("%d\n", no);//0
    printf("%d\n", yes);//1

    printf("%d\n", montag);//1
    printf("%d\n", dienstag);//2
    printf("%d\n", mittwoch);//3
    return 0;
}