#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *linkedListTraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("Element Is : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *insertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node *insertAtLsast(struct node *head, int data)
{
    struct node *p = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next == head;
    p->next = ptr;
    ptr->next = head;

    return head;
}

struct node *insertAtIndex(struct node *head, int index, int data)
{
    struct node *p = head;
    struct node *q = head->next;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = ptr;
    ptr->next = q;

    return head;
}

struct node *insertAfterNode(struct node *head, int value, int data)
{
    struct node *p = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    do
    {
        p = p->next;
    } while (p != head);
    
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *deleteAtFirst(struct node *head)
{
    struct node *p = head;
    while (p->next != head)
    {
        p = p->next;
    } 
    p->next = head->next;
    struct node *temp = head;
    head = head->next;
    free (temp);
    return head;
}

struct node *deleteAtEnd (struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    p->next = head;
    free(q);
    return head;
}

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;

    int i = 0;
    while(i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // connect node
    head->data = 8;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 10;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = head;

    printf("Node Before Update : \n");
    linkedListTraversal(head);
    printf("Node After Update : \n");
    head = deleteAtIndex(head, 2);
    linkedListTraversal(head);
    return 0;

}