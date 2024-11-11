#include<stdio.h>

int var = 5;//GLOBAL TANIMLAMA


void Yaz();  //DERLEYİCİ YUKARIDAN AŞŞAĞIYA OKUR YA FONKSİYON ÇAĞIRIMINDNA SONRA YAPCAN YA DA DİCENKİ PROTOTİP VAR BUNU ARA BİR BİLGİ VERMEDEN ARAYAMAZ DERLEYİCİ.
            // YA DA ARATMİCAN ÖNCE TANIMLİCAN DİREKT BELLEĞE ATICAK.DERLEYİCİ OKUMADAN RAM E ATAMAZ OKUYUP ATAR
int main()
{
    int var = 3;
    int x = 5;
    //int var = 5;  AYNI SCOPTA AYNI ADDA DEĞİŞKEN OLMAZ!!!!!
    {
        int var = 4;
        printf("%d\n",var); //FARKLI SCOPLARDA OLUR AMA || LOCAL OLAN TERCİH EDİLİR DİĞERİ BLOCKA GÖRE GLOBAL
        printf("%d",x);
    }
    printf("%d\n",var); //İÇİNDEKİ NE ERİŞEMEZ 4 E YANİ DAHA İÇTEKİNİ TERCİH EDER KENDİSİNE LOCAL OLANI
    Yaz();
    return 0;
}

void Yaz()
{
    printf("%d",var);  // GLOBALİ YAZAR BUDA DİĞERLERİNE ERİŞEMEZ ÇÜNKÜ
}

