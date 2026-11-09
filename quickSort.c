#include <stdio.h>
void printArr(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partion(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (i < high && A[i] <= pivot)
        {
            i++;
        }
        while (j > low && A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int *A, int low, int high)
{
    if (low < high)
    {
        int p = partion(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    } 
}


int main()
{
    int A[] = {2, 3, 2, 3, 24, 55, 44, 3, 2, 33, 4, 4};
    int n = sizeof(A) / sizeof(A[0]);
    printArr(A, n);
    quickSort(A, 0, n - 1);
    printArr(A, n);

    return 0;
}