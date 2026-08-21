#include <stdio.h>
#include <stdio.h>

void arrTraversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void arrInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (index >= capacity)
    {
        printf("Can't Insert Array . ");
    }
    for (int i = size - 1; i <= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
}

int main()
{
    int element = 6, inedx = 5, size = 8, capacity = 20;
    int arr[20] = {1, 2, 3, 4, 5, 7, 8, 10};
    printf("Array Before Intersion: ");
    arrTraversal(arr, size);
    arrInsertion(arr, size, element, capacity, inedx);
    printf("\n");
    printf("Array After Intersion: ");
    arrTraversal(arr, size);
    return 0;
}