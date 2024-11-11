#include<stdio.h>
#include<stdlib.h>
#define BOY 10

struct yigin
{
    int dizi[BOY];
    int indis; //top
};

struct yigin Yigin;

void elemanEkle(int sayi) // push()
{
    if(Yigin.indis==BOY-1)
    {
        printf("yiğin doludur\n");
    }
    else
    {
        Yigin.indis++;
        Yigin.dizi[Yigin.indis]=sayi;
    }
}

void yazdir()
{
    system("cls");
    if(Yigin.indis==-1)
    {
        printf("yigin bostur\n");
    }
    else
    {
        int i;
        for(i=Yigin.indis;i>-1;i--)
        {
            printf("%d\n",Yigin.dizi[i]);
        }
    }
}

void elemanCikar()
{
    if(Yigin.indis==-1)
    {
        printf("yigin bostur\n");
    }
    else
    {
        int cikansayi = Yigin.dizi[Yigin.indis];
        Yigin.indis--;
        printf("%d sayisis çikti\n",cikansayi);
    }
}
int main()
{
    Yigin.indis=-1; //boş anlamında şu an
    int secim,sayi;
    while(1)
    {
        printf("YIGIN (STACK)\n");
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