#include <stdio.h>
#include <string.h>


// struct Book
// {
//     char name[30]; // Programmierung mit C
//     short preis;   // 88$
// };
// int main()
// {
//     struct Book b1 = {"Programmierung mit C", 88};
//     struct Book* bp = &b1;
//     printf("%s\n", bp -> name);
//     printf("%d\n", bp -> preis);

//     printf("%s\n", (*bp).name);
//     printf("%d\n", (*bp).preis);

//     printf("%s is ", b1.name);
//     printf("%d$\n", b1.preis);
//     b1.preis = 66;
//     printf("Nach der Rabatt kostet es %d$\n", b1.preis);
//     strcpy(b1.name, "Programmierung mit C++");// strcpy = string copy.
//     printf("%s\n", b1.name);
//     return 0;
// }

// int main()
// {
//     printf("%lu\n", sizeof(double*));
//     printf("%lu\n", sizeof(short*));
//     printf("%lu\n", sizeof(char*));
//     printf("%lu\n", sizeof(int*));

//     printf("%lu\n", sizeof(double));
//     printf("%lu\n", sizeof(short));
//     printf("%lu\n", sizeof(char));
//     printf("%lu\n", sizeof(int));

//     // double  d = 3.14;
//     // double* pd = &d;
//     // *pd = 5.5;
//     // printf("%lf\n", d);
//     // printf("%lf\n", *pd);
//     // printf("%d\n", sizeof(pd)); // 32 - 4 / 64 - 8
//     // int a = 10;
//     // printf("die Addre von a = %p\n", &a);
//     // int* p = &a;// p ist eine Variante, Zeiger-Variante
//     // *p = 20;    // * ist Operator um zu dereferenz
//     // printf("p = %p\n", p);
//     // printf("*p = %d\n", *p);
//     // printf("a = %d\n", a);
//     return 0;
// }