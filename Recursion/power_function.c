#include <stdio.h>

int power(int m, int n)
{
    {
        if (n == 0)
        {
            return 1;
        }
        return m * power(m, n - 1);
    }
}
int power1(int m, int n)
{
    {
        if (n == 0)
            return 1;
        if (n % 2 == 0)
            return power1(m * m, n / 2);
        return m * power1(m * m, (n - 1 / 2));
    }
}
int main()
{
    int p = power(2, 6);
    printf("%d\n", p);
    int p1 = power(2, 13);
    printf("%d\n", p1);
    return 0;
}