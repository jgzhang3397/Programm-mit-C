# practice
## contents
> ### Test01
>
> - ``` void init(int arr[], int sz) ```
>> - initalize the array with all 0
> - ``` void my_print(int arr[], int sz) ```
>> - traverse print each element of the array
> - ``` void reverse_S1(int arr[], int sz) ```
>> - used 'for loop'
``` 
    int middle = (sz+1)/2;
    for(i=0; i<middle; i++)
    {
        ...
    }
```
>> - used 'while'
```
    int left = 0;
    int right = sz - 1;
    while(left < right)
    {
        ...
        left++;
        right--;
    }
```
>
> ### Test02
``` 
    void exchange(int* arr1, int* arr2, int sz) 
    {
        ...
    }
```    
> - swap the inhalts of two array1 & array2
>
> ### Test04
> - char* == 2bytes
> - short* == 4bytes
> - int* == 8bytes
> 
> ### Test05
> - (unsigned int) (sizeof(i));
```
    i = -1;
    printf("%d\n", i); // -1
    printf("%lu\n, i); // 4294967295
```
>
> ### Test06
> - count a the count of binary 1 of the num (n)
>> - num == 13 == 1101; 
>> - count == 3;
> 
```
int count_bit_one_V1(unsigned int n)
{
    ...
    if(n%2==1)
        count++;
    n = n/2;
    ...
}

int count_bit_one_V2(int n)
{
    ...
    if(((n>>i)&1)==1)
        count++;
    ...
}

int count_bit_one_V3(int n)
{
    ...
    n = n & (n-1);
    count++;
    ...
}
```
> ### Test07
> - How many bits are different in two integers m & n  
```
int get_diff_bit(int m, int n)
{
    int temp = m^n;//0 for same, 1 for difference
    ...
    temp = temp&(temp-1);
    count++;
    ...
}
```
>
> ### Test08
> - Get all the even and odd bits in an and print them  
```
    ...
    for ( i = 30; i >=0; i-=2)
    {
        (m>>i)&1;
    }
    ...
    for ( i = 31; i >=1; i-=2)
    {
        (m>>i)&1;
    }
    ...
```
