#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * next = NULL;
struct node * temp = NULL;
struct node * prev = NULL;
struct node * temp2 = NULL;
struct node * start = NULL;

void basaEkle(int sayi)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman->data=sayi;

    if(start==NULL)
    {
        start = eleman;
        start->next=start;
        start->prev=start;
    }
    else
    {
        if(start->next==start)
        {
            start->next=eleman;
            start->prev=eleman;
            eleman->next=start;
            eleman->prev=start;
            start=eleman;
        }
        else
        {
            temp = start;
            while(temp->next!=start)
            {
                temp = temp->next;
            }
            temp->next = eleman;
            eleman->prev = temp;
            eleman->next=start;
            start->prev = eleman;
            start = eleman;
        }
    }
}

void sonaEkle(int sayi)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman->data=sayi;
    eleman->next=start;

    if(start==NULL)
    {
        start = eleman;
        start->next=start;
        start->prev=start;
    }
    else
    {
        if(start->next==start)
        {
            start->next=eleman;
            start->prev=eleman;
            eleman->next=start;
            eleman->prev=start;
        }
        else
        {
            temp = start;
            while(temp->next!=start)
            {
                temp = temp->next;
            }
            temp->next = eleman;
            eleman->prev = temp;
            eleman->next=start;
            start->prev = eleman;
        }
    }
}

void bastanSil()
{
    if(start==NULL)
    {
        printf("liste boş");
    }
    else
    {
        if(start->next=start)
        {
            free(start);
            start=NULL;
        }
        else
        {
            temp = start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            temp2=start->next;
            free(start);
            temp->next=temp2;
            temp2->prev=temp;
            start=temp2;
        }
    }
}

void sondanSil()
{
    if(start==NULL)
    {
        printf("liste boş");
    }
    else
    {
        if(start->next=start)
        {
            free(start);
            start=NULL;
        }
        else
        {
            temp = start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            temp2=temp->prev;
            free(temp);
            temp2->next=start;
            start->prev= temp2;
        }
    }
}

void listele()
{
    system("cls");
    if(start == NULL)
    {
        printf("liste boş");
    }
    else
    {
        temp = start;
        while(temp->next!=start)
        {
            printf("%d\n",temp->data);
            temp  = temp -> next;
        }
        printf("%d",temp->data);
    }
}

int main()
{
    while(1)
    {
    int secim, sayi;

    printf("\n1-> basa eleman eklemek icin \n");
    printf("2-> sona eleman eklemek icin \n");
    printf("3-> bastan eleman silmek icin \n");
    printf("4-> sondan eleman silmek icin \n");
    printf("5-> listele \n");
    printf("seciminizi yapin : ");
    scanf("%d",&secim );
    switch (secim)
    {
        case 1: printf("basa eklenecek sayi: ");
        scanf("%d",&sayi);
        basaEkle(sayi);
        break;

        case 2: printf("sona eklenecek sayi: ");
        scanf("%d",&sayi);
        sonaEkle(sayi);
        break;

        case 3: 
        bastanSil();       
        break;

        case 4:
        sondanSil();
        break;

        case 5: listele();
        break;

        default:
        break;
    }
}
    return 0;
}