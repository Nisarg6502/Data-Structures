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
    printf("1");
    for (int i = 0; i < arr.size; i++)
    {
        int count = 1;
        if (arr.A[i] != -1)
        {
            for (int j = i + 1; j < arr.size; j++)
            {
                if (arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
            if (count > 1)
            {
                printf("The duplicated element: %d\nRepetitions: %d\n", arr.A[i], count);
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
    printf("\nEnter elements\n");
    for (int i = 0; i < arr.size; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    Display(arr);
    Duplicate(arr);
    return 0;
}