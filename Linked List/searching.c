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

void Search(struct Node *p, int key)
{
    int ch = key;
    while (p)
    {
        if (p->data == ch)
        {
            printf("Element found");
        }
        p = p->next;
    }
}

struct Node *LSearch(struct Node *p, int key)
{
    struct Node *q;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
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
    Search(first, 11);
    struct Node *temp;
    temp = LSearch(first, 1989);
    printf("\n\n%dFound", temp->data);
    return 0;
}