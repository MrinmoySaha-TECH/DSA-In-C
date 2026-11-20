#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArr(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int findMaxNum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int n)
{
    int i, j;
    int max = findMaxNum(A, n);

    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    i = 0;
    j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    free(count);
}

int main()
{
    int A[] = {3, 2, 3, 4, 4, 23, 12};
    int n = 7;
    printArr(A, n);
    countSort(A, n);
    printArr(A, n);
    return 0;
}