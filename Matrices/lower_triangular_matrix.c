#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[i * (i - 1) / 2 + (j - 1)] = x;
    }
}

int Get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.A[i * (i - 1) / 2 + (j - 1)];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i >= j)
            {
                printf("%d ", m.A[i * (i - 1) / 2 + (j - 1)]);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    printf("Enter dimensions");
    scanf("%d", &m.n);
    int x;
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }

    Display(m);
    printf("\n%d", Get(m, 1, 1));
    return 0;
}