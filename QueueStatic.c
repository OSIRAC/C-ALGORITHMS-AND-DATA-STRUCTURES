#include<stdio.h>
#include<stdlib.h>
#define BOY 5

int dizi[BOY];
int bas=-1,son=-1; //front,rear; bas: ilk indistir son en sonki indistir onunla veri eklenir


void elemanEkle(int veri)
{
    if(son==BOY-1)
    {
        printf("kuyruk doludur\n");
    }
    else
    {
        if(bas==-1)
        {
            bas=0;
        }
        son++;
        dizi[son]=veri;
    }
}

void elemanCikar()
{
    if(bas==-1 || bas > son)
    {
        printf("kuyruk bostur\n");
        bas=-1;
        son=-1;
    }
    else
    {
        bas=bas+1;
    }
}

void yazdir()
{
    if(bas==-1)
    {
        printf("kuyruk bostur XD\n");
    }
    else
    {
        int i;
        if(bas<=son)
        {
        for(i=bas;i<=son;i++)
        {
            printf("%d\n",dizi[i]);
        }
        }
        else
        {
            printf("dizi bostur\n");
        }
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