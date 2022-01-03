#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return sum(n - 1) + n;
}

int Isum(int n)
{
    int i, s = 0;
    for (i = 1; i < n; i++)
        s += i;
    return s;
}

int main()
{
    int r = sum(6);
    int s = Isum(6);
    printf("%d\n", r);
    printf("%d\n", s);
    return 0;
}