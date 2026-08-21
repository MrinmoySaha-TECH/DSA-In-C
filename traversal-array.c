#include <stdio.h>
void arrTraversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int main()
{
    int arr[20] = {1, 2, 3, 4, 5, 7, 8, 10};
    int size = 8;
    arrTraversal(arr, size);
    return 0;
}