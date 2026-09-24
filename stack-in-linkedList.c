#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkListTraversal(struct node *p)
{
    while (p != NULL)
    {
        printf("element : %d\n", p->data);
        p = p->next;
    }
}

int isEmpty(struct node *top)
{
    return top == NULL;
}

int isFull(struct node *top)
{
    (void)top;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    free(p);
    return 0;
}

struct node *push(struct node *top, int x)
{
    if (isFull(top))
    {
        printf("stack overflow\n");
        return top;
    }

    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("memory allocation failed\n");
        return top;
    }

    n->data = x;
    n->next = top;
    top = n;
    return top;
}

int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("stack underflow\n");
        return -1;
    }

    struct node *n = *top;
    *top = (*top)->next;
    int x = n->data;
    free(n);
    return x;
}

int main()
{
    struct node *top = NULL;

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);

    linkListTraversal(top);

    printf("\nPopped: %d\n", pop(&top));
    printf("Popped: %d\n", pop(&top));

    linkListTraversal(top);

    return 0;
}