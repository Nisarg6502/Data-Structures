#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Count(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int Sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

void Display(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        printf("%d ", p->data);
        count++;
        p = p->next;
    }
}

int main()
{
    int A[] = {6, 13, 22, 1989, 2002};
    Create(A, 5);
    Display(first);
    printf("\nCount: %d", Count(first));
    printf("\nSum: %d", Sum(first));
    return 0;
}