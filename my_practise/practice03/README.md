# Simple calculator
> - function pointer to function
> - Array of function pointers to store the address of the function
> - ## Test01:
>> 1. Write a function pointer array pfArr, which can store the addresses of all calculation functions  
```
...
int Add(int x, int y)
{
    return x + y;
}
...

int (*pfArr[])(int, int)= {0, Add, Sub, Mul, Div, Xor};
...
if(input>=1 && input < sz)
{
    ...
    // int result = (*pfArr[input])(x, y);
    int result = pfArr[input](x, y);
    ...
}

```
>
> - ## Test02:
```
...
switch (input)
        {
        case 1:
            Calc(Add);//The function name is the address of the function
            break;
        case 2:
        ...
...
void Calc(int (*pf)(int, int))
{
    ...
    printf("%d\n", pf(x, y));
    //printf("%d\n", (*pf)(x, y));
}
```
