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

void MissingElement(struct Array arr)
{
    int h = arr.A[arr.size - 1], l = arr.A[0];
    int diff = l - 0;
    for (int i = 0; i < arr.size; i++)
    {
        if (arr.A[i] - i != diff)
        {
            while (diff < arr.A[i] - i)
            {
                printf("The missing element is: %d", diff + i);
                diff++;
            }
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
    printf("\nEnter elements");
    for (int i = 0; i < arr.size; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    Display(arr);
    MissingElement(arr);
    return 0;
}