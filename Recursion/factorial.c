#include <stdio.h>

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return fact(n - 1) * n;
}

int Ifact(int n)
{
    int i, fact = 1;
    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int f = fact(6);
    int fa = Ifact(6);
    printf("%d\n", f);
    printf("%d\n", fa);
    return 0;
}