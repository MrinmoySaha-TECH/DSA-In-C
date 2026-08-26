#include <stdio.h>

void arrTraversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void arrDeletion(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {1, 4, 2, 3, 6};
    int size = 5, index = 2;
    printf("Array Before Deletion : \n");
    arrTraversal(arr, 5);
    printf("Array After Deletion : \n");
    arrDeletion(arr, size, index);
    return 0;
}