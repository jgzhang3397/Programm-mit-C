#include <stdio.h>
#include <string.h>

/*
1. how to use struct & pointer 
2. difference with struct & typedef

*/

typedef struct Book
{
    char name[30]; // Programming with C
    short preis;   // 88$
}book;

void Test01()
{
    struct Book b1 = {"Programming with C", 88};
    struct Book* bp = &b1;

    book b2 = {"how to be rich", 18};
    book* b2p = &b2;

    printf("============== use with '->' =========\n");
    printf("%s\n", bp -> name);
    printf("%d $\n", bp -> preis);

    printf("%s\n", b2p -> name);
    printf("%d $\n", b2p -> preis);

    printf("============== use with '(*).' =========\n");
    printf("%s\n", (*bp).name);
    printf("%d $\n", (*bp).preis);

    printf("%s\n", (*b2p).name);
    printf("%d $\n", (*b2p).preis);

    printf("============== pass by value ============\n");
    printf("%s is ", b1.name);
    printf("%d $\n", b1.preis);


    b1.preis = 66;
    printf("After the discount it costs %d $\n", b1.preis);
    strcpy(b1.name, "Programming with Java");// strcpy = string copy.
    printf("%s\n", b1.name);
}

void Test02()
{
    /*
    The pointer is the address, 
    and the number of bytes of the pointer is 
    related to the addressing capability of the system.

    16-bit system, the pointer is 2 bytes,
    32-bit system, so 4 bytes,
    64-bit, it is 8 bytes.
    */
    printf("%lu\n", sizeof(double*));//8
    printf("%lu\n", sizeof(short*));//8
    printf("%lu\n", sizeof(char*));//8
    printf("%lu\n", sizeof(int*));//8

    printf("%lu\n", sizeof(double));//8
    printf("%lu\n", sizeof(short));//2
    printf("%lu\n", sizeof(char));//1
    printf("%lu\n", sizeof(int));//4

    double  d = 3.14;
    double* pd = &d;
    *pd = 5.5;

    printf("%.2f\n", d);//5.50
    printf("%.2f\n", *pd);//5.50

    printf("%lu\n", sizeof(pd)); // 32 - 4 / 64 - 8

    int a = 10;
    printf("the addresse of a = %p\n", &a);//0x7ffeefbff2ec
    int* p = &a;// p is a Pointer and an adresse of a
    *p = 20;    // * is operator to dereference
    printf("p = %p\n", p);//p = 0x7ffeefbff2ec
    printf("*p = %d\n", *p);//*p = 20
    printf("a = %d\n", a);//a = 20
}

int main()
{
    //Test01();
    Test02();
    return 0;
}

