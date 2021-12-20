#include <stdio.h>

int y = 0; //globle variable acts like static variable

int fun(int n)
{
    static int x = 0; //static variable
    if (n > 0)
    {
        x++;
        y++;
        return fun(n - 1) + x + y;
    }
    return 0;
}

int main()
{
    int r = fun(6);
    printf("%d\n", r);
    return 0;
}