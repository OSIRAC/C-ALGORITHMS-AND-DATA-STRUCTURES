#include<stdio.h>
#include<stdlib.h>

void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void InsertionSort(int *array,int n)  // Insertion sort sagdakilerden soldakileri dener sola gelir yer değiştirir
{
    int i,j;
    for(i=1;i<n;i++)
    {
        int key = array[i];
        j = i - 1 ;
        while(j>=0 && key < array[j])
        {
            array[j + 1] = array[j];
            j--;  
        }
        array[j + 1] = key;  
    }
}

void Print(int *array,int n)
{
    for(int i = 0;i < n; i++)
    {              
        printf("%d",array[i]);
    }
}

int main()
{
    int array[]={1,4,7,3,9,0,5};
    int n = sizeof(array)/sizeof(array[0]);

    InsertionSort(array,n);
    Print(array,n);

    return 0;
}