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

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.size; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

void MissingElement(struct Array arr)
{
    int H[Max(arr)];
    int l = Min(arr);
    printf("%d", Max(arr));
    for (int i = 0; i < Max(arr); i++)
    {
        H[i] = 0;
    }
    printf("chal raha hai");
    for (int i = 0; i < arr.size; i++)
    {
        H[arr.A[i]]++;
    }
    printf("Ye bhi chal raha hai");
    for (int i = l; i <= Max(arr); i++)
    {
        if (H[i] == 0)
        {
            printf("%d\n", i);
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
    printf("%d", Min(arr));
    MissingElement(arr);
    return 0;
}