
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
        printf("%d",iter->data);
        iter  = iter -> next;
    }
}

struct Node* create_linkedlist(int data)
{
    node * n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    return n;
}

void add_node_head_of_linkedlist(struct Node** linkedlist,int data)
{
    node* new_linkedlist = create_linkedlist(data);
    new_linkedlist->next = *linkedlist;
    *linkedlist = new_linkedlist;

}

void add_node_end_of_linkedlist(struct Node**linkdelist,int data)
{

    node* iter = *linkdelist;

    if(*linkdelist == NULL)
    {
        *linkdelist = create_linkedlist(data);
    }
    else
    { 
    while(iter->next!=NULL)
    {
        iter = iter->next;
    }
    iter->next = create_linkedlist(data);
    }
}

void delete_node_from_linkedlist(struct Node**linkedlist,int data)
{
    node*temp;
    node*iter = *linkedlist;

    if(*linkedlist==NULL)
    {
        printf("Linked list is empty");
    }
    else if ((*linkedlist)->data==data)
    {
        temp = (*linkedlist)->next;
        free(*linkedlist);
        *linkedlist = temp;
    }
    else
    {
        while(iter!=NULL && iter->data!=data)
        {
            temp=iter;
            iter=iter->next;
        }
        if(iter==NULL)
        {
            printf("Data is not found");
        }
        else
        {
            temp->next = iter->next;
            free(iter);

        }
    }
}

void reverse_linkedlist(struct Node**linkedlist)
{
    node* prev = NULL;
    node*curr = *linkedlist;
    node *next = NULL;
    while (curr!=NULL)
    {
        next =curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    *linkedlist = prev;
}

void add_node_inside_of_linkedlist(struct Node**linkedlist,int dataprev,int datachose)
{
    node*temp;
    node*iter = *linkedlist;
    node* new_linkedlist = create_linkedlist(datachose);
    if((*linkedlist==NULL) && (*linkedlist)->data==dataprev)
    {
        new_linkedlist->next = *linkedlist;
        *linkedlist = new_linkedlist;
    }
    else
    {
        while(iter!=NULL && iter->data!=dataprev)
        {
            temp=iter;
            iter=iter->next;
        }
        if(iter==NULL)
        {
            printf("Data is not found");
        }
        else
        {
            temp->next = new_linkedlist;
            new_linkedlist -> next = iter;             
        }
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

    //write_linkedlist(n);
    node* root = create_linkedlist(5);
    //write_linkedlist(root);

    add_node_head_of_linkedlist(&root,4);
    //write_linkedlist(root);

    add_node_end_of_linkedlist(&root,6);
    //write_linkedlist(root);

    //reverse_linkedlist(&root);
    //write_linkedlist(root);

    add_node_inside_of_linkedlist(&root,5,3);
    write_linkedlist(root);
}