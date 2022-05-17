#include<stdio.h>

void my_strcat(char input1[], char input2[])
{
    int i, j;
    i = j = 0;
    while (input1[i]!='\0')
        i++;
    // while (input2[j]!='\0')
    // {
    //     input1[i+j] = input2[j];
    //     j++;
    // }   
    while( (input1[i++] = input2[j++]) != '\0')
        ;
}
int main()
{
    char input1[100];
    char input2[10];
    scanf("%s%s", input1, input2);
    my_strcat(input1, input2);

    printf("%s\n", input1);
    return 0;
}