#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode (int data)
{
    struct node *p;
    p = (struct node *)malloc (sizeof(struct node));
    
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}

int main(){
    struct node *p = createNode(1);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(3);

    p->left = p1;
    p->right = p2;
    return 0;
}