#include<stdio.h>
#include<stdlib.h>

void Merge(int *array,int sol,int orta,int sag)
{
    int i,j,k;

    int solboyut = orta - sol + 1; // Sol alt dizinin boyutu
    int sagboyut = sag - orta;    // Sağ alt dizinin boyutu

    int *SolDizi = (int *)malloc(solboyut * sizeof(int));
    int *SagDizi = (int *)malloc(sagboyut * sizeof(int));

    for (i = 0; i < solboyut; i++)
    {
        SolDizi[i] = array[sol + i];
    }

    for (j = 0; j < sagboyut; j++)
    {
        SagDizi[j] = array[orta + 1 + j];
    }
    i = 0;
    j = 0;
    k = sol;
    while (i < solboyut && j < sagboyut) 
    {
        if (SolDizi[i] <= SagDizi[j]) 
        {
            array[k] = SolDizi[i];
            i++;
        } 
        else 
        {
            array[k] = SagDizi[j];
            j++;
        }
        k++;
    }
     while (i < solboyut) 
    {
        array[k] = SolDizi[i];
        i++;
        k++;
    }

    // Sağ alt dizinin kalan elemanları kopyalanıyor
    while (j < sagboyut) 
    {
        array[k] = SagDizi[j];
        j++;
        k++;
    }

    // Bellek temizleniyor
    free(SolDizi);
    free(SagDizi);
}

void Merge_Sort(int *array,int sol,int sag)
{
    if(sol < sag)
    {
        int orta = sol + (sag - sol)/2;
        Merge_Sort(array,sol,orta);
        Merge_Sort(array,orta + 1 ,sag);

        Merge(array,sol,orta,sag);

    }
}


void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }    
    printf("\n");
}

int main() {
    int array[] = {2, 5, 3, 7, 1};
    int arr_size = sizeof(array) / sizeof(array[0]);

    printf("Verilen dizi: \n");
    printArray(array, arr_size);

    Merge_Sort(array, 0, arr_size - 1);

    printf("\nSiralanmiş dizi: \n");
    printArray(array, arr_size);
    return 0;
}