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

void Duplicate(struct Array arr)
{
    for (int i = 0; i < arr.size - 1; i++)
    {
        int j;
        if (arr.A[i] == arr.A[i + 1])
        {
            j = i + 1;
            while (arr.A[j] == arr.A[i])
            {
                j++;
            }
            printf("Duplicate element: %d appears %d times\n", arr.A[i], j - i);
            i = j - 1;
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
    Duplicate(arr);
    return 0;
}