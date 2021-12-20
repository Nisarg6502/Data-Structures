#include <stdio.h>

int fun(int n)
{
    if (n > 100)
    {
        return n - 6;
    }
    return fun(fun(n + 13));
}

int main()
{
    int r = fun(89);
    printf("%d\n", r);
    return 0;
}