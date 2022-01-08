#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *N;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\n Elements are \n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d\n", arr.N[i]);
    }
}
int main()
{
    struct Array arr;
    int n, i;
    printf("Enter size of an Array\n");
    scanf("%d", &arr.size);
    arr.N = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter how many numbers");
    scanf("%d", &n);

    printf("Enter all the elements");
    for (i = 0; i < n; i++)
        scanf("%d", &arr.N[i]);
    arr.length = n;
    Display(arr);
    return 0;
}