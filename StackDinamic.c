#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * top = NULL;
struct node * temp = NULL;

void push(int veri)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman->data = veri;

    if(top == NULL)
    {
        top = eleman;
        top->next = NULL;
    }
    else
    {
        eleman->next=top;
        top=eleman;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("yigin bostur\n");
    }
    else
    {
        printf("%d elemani stack den cikarildi\n",top->data);
        temp = top->next;
        free(top);
        top=temp;
    }
}

void print()
{
    system("cls");
    if(top == NULL)
    {
        printf("stack bos\n");
    }
    else
    {
        temp = top;
        while(temp->next!=NULL)
        {
            printf("%d\n",temp->data);
            temp  = temp -> next;
        }
        printf("%d",temp->data);
    }
}

void peek()
{
    if(top==NULL)
    {
        printf("yigin bostur\n");
    }
    else
    {
        printf("%d elemani stack in en ust elemani\n",top->data);
    }
}

int main()
{
    while(1)
    {
    int secim, sayi;

    printf("\n1-> basa eleman eklemek icin \n");
    printf("2-> eleman cikarmak icin \n");
    printf("3-> elemani yazdirmak icin \n");
    printf("4-> ilk eleman göstermek icin \n");
    printf("seciminizi yapin : ");
    scanf("%d",&secim );
    switch (secim)
    {
        case 1: printf("basa eklenecek sayi: ");
        scanf("%d",&sayi);
        push(sayi);
        break;

        case 2:
        pop();
        break;

        case 3: 
        print();       
        break;

        case 4:
        peek();
        break;

        default:
        break;
    }
}
    return 0;
}
