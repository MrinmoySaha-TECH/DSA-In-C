#include <stdio.h>

void printArr (int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort (int *A, int n)
{
    int temp, minIndex;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = 0; j < n; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
            temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
        
    }
    
}
int main(){
    int A[] = {2,3,34,5,565,4,3,3};
    int n = sizeof(A) / sizeof(A[0]);
    printArr(A, n);
    selectionSort(A, n);
    printArr(A, n);
    return 0;
}