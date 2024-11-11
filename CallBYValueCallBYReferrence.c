#include<stdio.h>

void Yazdir(int x,int y) // FONKSİYON BİTİNCE YIKILIR DEĞERLER KAYBOLUR
{
    x = 20;
    y = 10;
}

void Yaz(int *x,int *y) // FONKSİYON BİTİNCE YIKILIR DEĞERLER KAYBOLUR  C DE FUNCTİON OVERLOAD YOKTUR
{
    *x = 20;
    *y = 10;
}

int main()
{
    int x =10;
    int y = 20;

    //  Yazdir(10,20); // DEĞERLER GİDER SADECE 10 VE 20 O KADAR.
    Yaz(&x,&y);

    printf("x= %d  y= %d \n",x,y);
    
    return 0;
}