#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d\t", arr.A[i]);
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.size; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

void Duplicate(struct Array arr)
{
    int max = Max(arr);
    int hashArr[max + 1];
    for (int i = 0; i <= max; i++)
    {
        hashArr[i] = 0;
    }
    for (int i = 0; i < arr.size; i++)
    {
        hashArr[arr.A[i]]++;
    }
    for (int i = 0; i <= max; i++)
    {
        if (hashArr[i] > 1)
        {
            printf("Duplicate element: %d\n Repetition: %d\n", i, hashArr[i]);
        }
    }
}

int main()
{
    struct Array arr;
    printf("Enter number of elements");
    scanf("%d", &arr.size);
    printf("\nnumber of elements %d", arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("\nEnter elements\n");
    for (int i = 0; i < arr.size; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    Display(arr);
    printf("\n%d\n", Max(arr));
    Duplicate(arr);
    return 0;
}