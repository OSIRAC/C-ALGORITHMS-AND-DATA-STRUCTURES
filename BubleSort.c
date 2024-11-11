#include<stdio.h>
#include<stdlib.h>

void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void BubleSort(int *array,int n)  // bublesort en büyüğü sağa atar onunla ilgilenmez
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j = 0;j < n - i - 1;j++)
        {
            if(array[j]<array[j+1])
            {
                Swap(&array[j],&array[j+1]);
            }
        }
    }
}
int main()
{
    int array[]={1,4,7,3,9,0,5};
    int n = sizeof(array)/sizeof(array[0]);

    BubleSort(array,n);

    return 0;
}