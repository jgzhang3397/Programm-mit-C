# basic 04
## Test01: Alarm Clock
> - input: 0:0 100
> - output: 01:40
> - solution code:
```
    ...
    scanf("%d:%d %d", &hour, &minute, &mins);//"%d:%d %d"
    ...
    printf("%02d:%02d\n", hour, minute);//%02d
```
## Test02: the sum of greatest common divisor & least common multiple of n & m
> - LCM = n * m / GCD
> - long long n & m
```
long long get_GCD(long long n, long long m)
{
    long long k;
    while ((k = n%m)!= 0)
    {
        n = m;
        m = k;
    }
    return m;
}
```