#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
};

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

void Display(struct Array arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d\t", arr.A[i]);
    }
}

void Duplicate(struct Array arr)
{
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

void DuplicateHash(struct Array arr)
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
            printf("Hash Duplicate element: %d\n Repetition: %d\n", i, hashArr[i]);
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
    DuplicateHash(arr);
    Duplicate(arr);
    return 0;
}