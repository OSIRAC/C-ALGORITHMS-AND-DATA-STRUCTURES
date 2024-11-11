#include<stdio.h>

int i=0;

void Yazdir()
{
    if(i<3)
    {
        printf("Merhaba Dunya\n");  // RETURN SÜZ FONKSİYONU BİTİREBİLİRSİN 
        i++;                       //  RECURSİVE BELLİ BİR FONKSİYON ÖRÜNTÜSÜNÜ TEKRAR EDER 
        Yazdir();
    }
    printf("Tosun Pasa\n");
}

int Factoriyel(int x)
{
    if(x==1)       // İF KOŞULUNA BİTECEĞİ YERİ ELSE RECURSİVİ YAZARSIN
    {
        return 1;
    }
    else
    {
        return (x*Factoriyel(x-1));  // KENDİSİ BİR EKSİĞİ FAKTÖRİYEL ÖRÜNTÜ BÖYLE
    }
}

int main()
{
    Yazdir();
    printf("%d",Factoriyel(5));

    return 0;
}