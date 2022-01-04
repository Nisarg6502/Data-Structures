#include <stdio.h>

int fib(int n)
{
    int t0 = 0, t1 = 1, s = 0;
    if (n <= 1)
    {
        return n;
    }
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int fibR(int n)
{
    int t0 = 0, t1 = 1, s = 0;
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

int F[13];
int memofib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = memofib(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = memofib(n - 1);
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    for (int i = 0; i < 13; i++)
    {
        F[i] = -1;
    }

    printf("%d\n", fib(6));
    printf("%d\n", fib(13));
    printf("%d\n", fibR(6));
    printf("%d\n", fibR(13));
    printf("%d\n", memofib(13));
    return 0;
}