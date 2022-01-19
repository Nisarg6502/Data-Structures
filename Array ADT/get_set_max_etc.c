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

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int RbinSearch(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            RbinSearch(a, l, mid - 1, key);
        }
        else
        {
            RbinSearch(a, mid + 1, h, key);
        }
    }
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < (*arr).length) //coz we are modifying values
    {
        arr->A[index] = x;
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
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
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    printf("\nGet: %d\n", Get(arr, 0));
    Set(&arr, 0, 13);
    Display(arr);
    printf("Max:%d\n", Max(arr));
    printf("Min:%d\n", Min(arr));
    printf("Sum:%d\n", Sum(arr));
    printf("Avg:%f\n", Avg(arr));
    return 0;
}