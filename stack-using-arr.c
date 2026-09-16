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
    if (ptr->top == 10)
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
    if(isFull(ptr))
    {
        printf("stack overflow , can't push element %d", value);
    } else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop (struct stack *ptr)
{
     if(isEmpty(ptr))
    {
        printf("stack underflow , can't pop element from stack");
    } else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{

    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("stack created\n");

    push(s,1);
    push(s,2);
    push(s,44);
    push(s,4);

    push(s,51);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    push(s,10);
    push(s,11);
    if (isEmpty(s))
    {
        printf("Stack is empty");
    }
    else
    {
        printf("stack is not empty");
    }

    

    return 0;
}