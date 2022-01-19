#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("Elements are: \n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d\t", arr.A[i]);
    }
}

void Reverse(struct Array *arr)
{
    int *B;
    B = (int *)malloc(arr->length * sizeof(int));
    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr)
{
    int temp;
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    Reverse(&arr);
    Display(arr);
    Reverse2(&arr);
    Display(arr);
    return 0;
}