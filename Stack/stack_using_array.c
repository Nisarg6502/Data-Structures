#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st)
{
    printf("Enter Size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void Push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int Pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int Peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
    {
        printf("Invalid index\n");
    }
    x = st.S[st.top - index + 1];
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

int StackTop(struct Stack st)
{
    if (!isEmpty(st))
    {
        return st.S[st.top];
    }
    return -1;
}

int isFull(struct Stack st)
{
    return st.top == st.size - 1 ? 1 : 0;
}

int main()
{
    struct Stack st;
    Create(&st);
    Push(&st, 10);
    Display(st);
    Push(&st, 20);
    Display(st);
    Push(&st, 30);
    Display(st);
    Push(&st, 40);
    Display(st);
    Push(&st, 50);
    Display(st);
    Pop(&st);
    Display(st);
    Pop(&st);
    Display(st);
    Pop(&st);
    Display(st);
    Pop(&st);
    Display(st);
    return 0;
}