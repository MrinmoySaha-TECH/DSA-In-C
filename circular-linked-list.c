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
    head = insertAtFirst(head, 7);
    linkedListTraversal(head);
    return 0;
}