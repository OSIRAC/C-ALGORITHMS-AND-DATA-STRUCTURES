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
	eleman->prev=NULL;
	eleman->data=sayi;

	if(start==NULL)
	{
		start = eleman;
		start->next=NULL;
	}
	else
	{
		eleman->next = start;
		start->prev = eleman;
		start = eleman;
	}
}

void sonaEkle(int sayi)
{
	struct node *eleman = (struct node *)malloc(sizeof(struct node));
	eleman->next=NULL;
	eleman->data=sayi;
	
	if(start==NULL)
	{
		start = eleman;
		start->next=NULL;
		start->prev=NULL;
	}
	else
	{
		if(start->next==NULL)
		{
			start->next = eleman;
			eleman->prev = start;
		}
		else
		{
			temp = start;
			while(temp->next!=NULL)
			{
				temp= temp->next;
			}
		}
		temp->next = eleman;
		eleman->prev= temp;
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
        while(temp->next!=NULL)
        {
            printf("%d\n",temp->data);
            temp  = temp -> next;
        }
        printf("%d",temp->data);
    }
}

void bastanSil()
{
	if(start==NULL)
	{
		printf("Liste bos");
	}
	else
	{
		if(start->next==NULL)
		{
			free(start);
			start=NULL;
			
		}
		else
		{
			temp = start->next;
			free(start);
			temp->prev=NULL;
			start= temp;
		}
	}
}

void sondanSil()
{
	if(start==NULL)
	{
		printf("Liste bos");
	}
	else
	{
		if(start->next==NULL)
		{
			free(start);
			start=NULL;
			
		}
		else
		{
			temp = start;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			temp2 = temp;
			free(temp->next);
			temp2->next = NULL;
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