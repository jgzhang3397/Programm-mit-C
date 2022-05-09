#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
/*
确定signed / unsigned char, short, int, long 取值范围
*/
void demo01_with_limits_h()
{
    printf("Size of signed Char %d\n", CHAR_BIT);
    printf("Size of signed Char Max %d\n", CHAR_MAX);
    printf("Size of signed Char Min %d\n", CHAR_MIN);
    printf("Size of unsigned Char Max %u\n", UCHAR_MAX);
    printf("\n\n");

    //printf("Size of signed Short %d\n", SHRT_BIT);
    printf("Size of signed Short Max %d\n", SHRT_MAX);
    printf("Size of signed Short Min %d\n", SHRT_MIN);
    printf("Size of unsigned Short Max %u\n", USHRT_MAX);
    printf("\n\n");

    //printf("Size of signed Int %d\n", INT_BIT);
    printf("Size of signed Int Max %d\n", INT_MAX);
    printf("Size of signed Int Min %d\n", INT_MIN);
    printf("Size of unsigned Int Max %u\n", UINT_MAX);
    printf("\n\n");

    printf("Size of signed Long Max %d\n", LONG_BIT);
    printf("Size of signed Long Max %ld\n", LONG_MAX);
    printf("Size of signed Long Min %ld\n", LONG_MIN);
    printf("Size of unsigned Long Max %lu\n", ULONG_MAX);

}

void demo012_without_limits_h()
{
    printf("Size of signed Char Max %d\n", (char)((unsigned char)~0>>1));
    printf("Size of signed Char Min %d\n", -(char)((unsigned char)~0>>1)-1);
    printf("Size of unsigned Char Max %u\n", 2*((unsigned char)~0>>1)+1);
    printf("\n\n");

    printf("Size of signed Short Max %d\n", (short)((unsigned short)~0>>1));
    printf("Size of signed Short Min %d\n", -(short)((unsigned short)~0>>1)-1);
    printf("Size of unsigned Short Max %u\n", 2*((unsigned short)~0>>1)+1);
    printf("\n\n");

    printf("Size of signed Int Max %d\n", (int)((unsigned int)~0>>1));
    printf("Size of signed Int Min %d\n", -(int)((unsigned int)~0>>1)-1);
    printf("Size of unsigned Int Max %u\n", 2*((unsigned int)~0>>1)+1);
    printf("\n\n");

    printf("Size of signed Long Max %ld\n", (long)((unsigned long)~0>>1));
    printf("Size of signed Long Min %ld\n", -(long)((unsigned long)~0>>1)-1);
    printf("Size of unsigned Long Max %lu\n", 2*((unsigned long)~0>>1)+1);

}

int main()
{
    //demo01_with_limits_h();
    //demo012_without_limits_h();

    //127 = 1+2+4+8+16+32+64
    //0111 1111
    printf("Size of signed Char Max %d\n", (char)((unsigned char)~0>>1));
    printf("Size of signed Char Max %d\n", ((signed char)~0>>1));

    return 0;
}