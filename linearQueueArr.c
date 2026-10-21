#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("queue is full , can't insert new element\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;

        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("queue is empty , can't dequeue element\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];

        printf("Dequeued element: %d\n", a);
        return a;
    }
}

int main()
{

    struct queue q;
    q.size = 5;
    q.r = q.f = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    // enqueue(&q, 2);
    // enqueue(&q, 3);
    // enqueue(&q, 4);
    enqueue(&q, 5);
    dequeue(&q);

    return 0;
}