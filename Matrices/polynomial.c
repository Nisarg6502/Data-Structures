#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Polynomial
{
    int n;
    struct Term *t;
};

void Create(struct Polynomial *p)
{
    printf("Number of terms");
    scanf("%d", &p->n);
    p->t = (struct Term *)malloc(p->n * sizeof(struct Term));
    printf("Enter terms");
    for (int i = 0; i < p->n; i++)
    {
        scanf("%d%d", &p->t[i].coeff, &p->t[i].exp);
    }
}

struct Polynomial *add(struct Polynomial p1, struct Polynomial p2)
{
    struct Polynomial *sum;
    sum = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    sum->t = (struct Term *)malloc((p1.n + p2.n) * sizeof(struct Term));
    int i, j, k;
    i = j = k = 0;
    while (i < p1.n && j < p2.n)
    {
        if (p1.t[i].exp > p2.t[j].exp)
        {
            sum->t[k++] = p1.t[i++];
        }
        else if (p1.t[i].exp < p2.t[j].exp)
        {
            sum->t[k++] = p2.t[j++];
        }
        else
        {
            sum->t[k].exp = p1.t[i].exp;
            sum->t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }
    }
    for (; i < p1.n; i++)
    {
        sum->t[k++] = p1.t[i];
    }
    for (; j < p2.n; j++)
    {
        sum->t[k++] = p2.t[j];
    }
    sum->n = k;
    return sum;
}

void Display(struct Polynomial p)
{
    for (int i = 0; i < p.n; i++)
    {
        printf("%dx%d+", p.t[i].coeff, p.t[i].exp);
    }
    printf("\n");
}

int main()
{

    struct Polynomial p1, p2, *p3;
    Create(&p1);
    Display(p1);
    printf("\n");
    Create(&p2);
    Display(p2);
    printf("\n");
    p3 = add(p1, p2);
    Display(*p3);
    return 0;
}