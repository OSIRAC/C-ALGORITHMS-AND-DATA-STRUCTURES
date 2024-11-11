#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;

}node;

void write_linkedlist(struct Node*n)
{
    node* iter = n;
    while (iter!=NULL)
    {
        printf("%d\n",iter->data);
        iter  = iter -> next;
    }
    
}


int main()
{
    node * n = malloc(sizeof(node));
    n->data=2;
    n->next=NULL;

    n->next = malloc(sizeof(node));
    n->next->data=3;
    n->next->next= NULL;

    write_linkedlist(n);

}