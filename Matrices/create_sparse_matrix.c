#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void Create(struct Sparse *s)
{
    printf("Enter Dimensions");
    scanf("%d%d", &s->m, &s->n);
    printf("Number of non-zero");
    scanf("%d", &s->num);

    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));
    printf("Enter non-zero elements");
    for (int k = 0; k < s->num; k++)
    {
        scanf("%d%d%d", &s->ele[k].i, &s->ele[k].j, &s->ele[k].x);
    }
}

void Display(struct Sparse s)
{
    int k = 0;
    for (int p = 0; p < s.m; p++)
    {
        for (int q = 0; q < s.n; q++)
        {
            if (p == s.ele[k].i && q == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Sparse s;
    Create(&s);
    Display(s);
    return 0;
}