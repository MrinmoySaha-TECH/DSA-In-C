#include <stdio.h>

void printArr(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int main()
{
    int A[] = {2, 3, 45, 67, 8, 9, 6, 54, 3};
    int n = sizeof(A) / sizeof(A[0]);
    printf("array before sorting : ");
    printArr(A, n);
    insertionSort(A, n);
    printf("array after sorting : ");
    printArr(A, n);
    return 0;
}