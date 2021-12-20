#include <stdio.h>

void fun(int n)
{
    if (n > 0)
    {
        printf("%i\n", n);
        fun(n - 1);
    }
}

int main()
{
    int x = 6;
    fun(x);
    return 0;
}