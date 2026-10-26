#include <stdio.h>
#include <stdlib.h>

struct DEqueue
{
    int f;
    int r;
    int size;
    int *arr;
    int count;
};

int isempty(struct DEqueue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct DEqueue *q)
{
    if (q->count == q->size)
    {
        return 1;
    }
    return 0;
}

void insertFront(struct DEqueue *q, int val)
{
    if (isFull(q))
    {
        printf("can't insert from front , queue is full\n");
        return;
    }
    else
    {
        if (q->count == 0)
        {
            q->f = 0;
            q->r = 0;
        }
        else
        {
            q->f = (q->f - 1 + q->size) % q->size;
        }
        q->arr[q->f] = val;
        q->count++;
        printf("element inserted at front : %d\n", q->arr[q->f]);
    }
}

void insertRear(struct DEqueue *q, int val)
{
    if (isFull(q))
    {
        printf("queue is full, can't insert from rear\n");
        return;
    }
    else
    {
        if (q->count == 0)
        {
            q->f = 0;
            q->r = 0;
        }
        else
        {
            q->r = (q->r + 1) % q->size;
        }
        q->arr[q->r] = val;
        q->count++;
        printf("element inserted at rear : %d\n", q->arr[q->r]);
    }
}

int deleteFront(struct DEqueue *q)
{
    if (isempty(q))
    {
        printf("queue is  empty\n");
        return -1;
    }
    else
    {
        int a = q->arr[q->f];
        if (q->count == 1)
        {
            q->f = q->r = -1;
        }
        else
        {
            q->f = (q->f + 1) % q->size;
        }
        q->count--;
        printf("element deleted from front : %d\n", a);
        return a;
    }
}

int deleteRear(struct DEqueue *q)
{
    if (isempty(q))
    {
        printf("queue is empty , can't delete from rear\n");
        return -1;
    }
    else
    {
        int a = q->arr[q->r];
        if (q->count == 1)
        {
            q->f = q->r = -1;
        }
        else
        {
            q->r = (q->r - 1 + q->size) % q->size;
        }
        q->count--;
        printf("element deleted from rear : %d\n", a);
        return a;
    }
}

int main()
{
    struct DEqueue q;
    q.size = 5;
    q.f = q.r = -1;
    q.count = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    if (q.arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    insertRear(&q, 10);
    insertRear(&q, 20);
    insertFront(&q, 5);

    deleteFront(&q);
    deleteRear(&q);

    free(q.arr);

    return 0;
}