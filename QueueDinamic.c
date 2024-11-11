#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * temp = NULL;
struct node * front = NULL;
struct node * rear = NULL;

void elemanEkle(int veri)
{
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman ->data = veri;
    if(front==NULL)
    {
        front=eleman;
        front->next=front;
        rear=eleman;
        rear->next=NULL;
    }
    else if(front->next==front)
    {
        rear->next = eleman;
        rear = eleman;
        rear->next=NULL;
        front ->next = rear;
    }
    else
    {
        rear->next=eleman;
        rear = eleman;
        rear->next=NULL;
    }
}

void elemanCikar()
{
    if(front==NULL)
    {
        printf("kuyruk bostur");
    }
    else
    {
        temp = front->next;
        free(front);
        front=temp;
    }
}

void yazdir()
{
    if(front==NULL)
    {
        printf("kuyruk bostur\n");
    }
    else
    {
        temp = front;
        while (temp->next!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

int main()
{
    int secim,sayi;
    while(1)
    {
        printf("KUYRUK (Queue)\n");
        printf("1------> eleman ekleme \n");
        printf("2------> eleman cikar \n");
        printf("3------> eleman yazdir \n");
        printf("4------->CIKIS\n");
        printf("secimicinizi yapin\n");
        scanf("%d",&secim);
        switch (secim)
        {
            case 1:
                printf("eklenecek sayi\n");
                scanf("%d",&sayi);
                elemanEkle(sayi);
            break;
            case 2:
                elemanCikar();
            break;
            case 3:
                yazdir();
            break;    
            case 4:
                printf("programdan cikis\n");
            return 0;
        }   
    }
    return 0;
}