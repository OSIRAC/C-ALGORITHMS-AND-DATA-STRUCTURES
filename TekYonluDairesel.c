#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;

};

struct node* start = NULL;
struct node* temp = NULL;
struct node* prev = NULL;
struct node* last = NULL;

void basaekle(int sayi)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman -> data = sayi;

    if(start == NULL)
    {
        start = eleman;
        start -> next = start; 
    }
    else
    {
        temp = start;
        while(temp->next!=start)
        {
            temp  = temp -> next;
        }
        temp->next = eleman;
        eleman->next = start;
        start = eleman;
    }
}
void sonaekle(int sayi)

{
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman -> data = sayi;

    if(start == NULL)
    {
        start = eleman;
        start -> next = start; 
    }
    else
    {
        temp = start;
        while(temp->next!=start)
        {
            temp  = temp -> next;
        }
        temp->next = eleman;
        eleman->next = start;
    }
}
void listele()
{
    system("clear");
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

void bastanSil()
{
    if(start == NULL)
    {
        printf("Listede silinecek eleman yok");
    }
    else
    {
        if(start->next==start)
        {
            free(start);
            start = NULL;
        }
        else
        {
            last = start;
            while(last->next!=start)
            {
                last = last -> next;
            }
            temp = start ->next;
            free(start);
            last->next =temp;
            start = temp;
        }
    }
}

void sondanSil()
{
    if(start == NULL)
    {
        printf("Listede silinecek eleman yok");
    }
    else
    {
        if(start->next==start)
        {
            free(start);
            start = NULL;
        }
        else
        {
            last = start;
            while(last->next->next!=start)
            {
                last = last -> next;
            }
            temp = last;
            free(last->next);
            last->next =start;
        }
    }
}


int main()
{
    while(1)
    {
    int secim, sayi;

    printf("\n1-> basa eleman eklemek icin \n");
    printf("2-> sona eleman eklemek icin \n");
    printf("3-> bastan eleman silmel icin \n");
    printf("4-> sondan eleman silmel icin \n");
    printf("5-> listele \n");
    printf("seciminizi yapin : ");
    scanf("%d",&secim );
    switch (secim)
    {
        case 1: printf("basa eklenecek sayi: ");
        scanf("%d",&sayi);
        basaekle(sayi);
        break;

        case 2: printf("sona eklenecek sayi: ");
        scanf("%d",&sayi);
        sonaekle(sayi);
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
