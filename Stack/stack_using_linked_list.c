#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void Push(struct Node *m, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
    {
        printf("Stack is Full\n");
    }
    t->data = x;
    t->next = top;
    top = t;
}

int Pop(struct Node *m)
{
    int x = -1;
    struct Node *t;
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display(struct Node *m)
{
    struct Node *p;
    p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Node *st;
    Push(st, 10);
    Display(st);
    Push(st, 20);
    Display(st);
    Push(st, 30);
    Display(st);
    Push(st, 40);
    Display(st);
    Push(st, 50);
    Display(st);
    Pop(st);
    Display(st);
    Pop(st);
    Display(st);
    Pop(st);
    Display(st);
    Pop(st);
    Display(st);
    return 0;
}