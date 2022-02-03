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

void Duplicate(struct Array arr, int k)
{
    for (int i = 0; i < arr.size - 1; i++)
    {
        for (int j = i + 1; j < arr.size; j++)
        {
            if (arr.A[i] + arr.A[j] == k)
            {
                printf("Pair is: %d and %d", arr.A[i], arr.A[j]);
            }
        }
    }
}

void DuplicateHash(struct Array arr, int k)
{
    printf("chal rha hai");
    int max = Max(arr);
    int hashArr[max + 1];
    for (int i = 0; i <= max; i++)
    {
        hashArr[i] = 0;
    }
    for (int i = 0; i < arr.size; i++)
    {
        if (hashArr[abs(k - arr.A[i])] != 0 && abs(k - arr.A[i]) > 0)
        {
            printf("\n%d + %d = %d\n", arr.A[i], k - arr.A[i], k);
        }
        hashArr[arr.A[i]]++;
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
    int k;
    printf("Enter sum");
    scanf("%d", &k);
    DuplicateHash(arr, k);
    // Duplicate(arr, k);
    return 0;
}