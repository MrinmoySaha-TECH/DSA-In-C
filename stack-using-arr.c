#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("stack overflow , can't push element %d", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack underflow , can't pop element from stack\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *p, int i)
{
    int arr = p->top - i + 1;
    if (arr < 0)
    {
        printf("Not a valid Position");
    }
    else
    {
        return p->arr[arr];
    }
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // printf("stack created\n\n");
    // printf("Stack before update \n");
    // printf("Stack is empty(1) or not(0) : %d\n", isEmpty(s));
    // printf("Stack is full(1) or not(0) : %d\n\n", isFull(s));

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11);
    // printf("Stack after update :\n");
    // printf("Stack is empty(1) or not(0) : %d\n", isEmpty(s));
    // printf("Stack is full(1) or not(0) : %d\n", isFull(s));

    // printf("%d\n", peek(s, 1));

    printf("bottom element of stack : %d\n", stackBottom(s));
    printf("top element of stack : %d", stackTop(s));

    return 0;
}