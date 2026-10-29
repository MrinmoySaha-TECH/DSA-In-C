#include <stdio.h>
void traverseArr(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void adaptivebubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    //int A[] = {2, 3, 5, 7, 9, 8, 4};
    int A[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Array before sorting : ");
    traverseArr(A, n);
    //bubbleSort(A, n);
    adaptivebubbleSort(A, n);
    printf("Array after sorting : ");
    traverseArr(A, n);
    return 0;
}