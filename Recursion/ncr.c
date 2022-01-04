#include <stdio.h>

double fact(double n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

double nCr1(double n, double r)
{
    double num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);
    return num / den;
}

//using pascal's triangle
double nCr(double n, double r)
{
    if (n == r || r == 0)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    printf("%lf\n", nCr1(13, 6));
    printf("%lf\n", nCr(13, 6));
    return 0;
}