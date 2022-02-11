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

void Insert(struct Node *p, int index, int x)
{

    struct Node *t;
    if (index < 0 || index > Count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else if (index == Count(p))
    {
        for (int i = 0; i < Count(p); i++)
        {
            p = p->next;
        }
        p->next = t;
        t->next = NULL;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}

void Display(struct Node *p)
{
    
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    int A[] = {6, 13, 22, 1989, 2002};
    Create(A, 5);
    Display(first);
    Insert(first, 3, 15);
    printf("\n");
    Display(first);
    return 0;
}