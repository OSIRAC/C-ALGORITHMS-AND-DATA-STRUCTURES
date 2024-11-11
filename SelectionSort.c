#include<stdio.h>
#include<stdlib.h>

void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void SelectionSort(int *array,int n)  // selectionda en küçüğü ararız teker teker başa atarız seçme var yani en başa dokunmayız gene
{            //   2,0,5,1,9,4
    int i,j,min;
    for(i = 0;i < n ;i ++)
    {
        min = i;
        for(j = i + 1;j < n ;j++)
        {
            if(array[min]<array[j])
            {
                min = j;
            }
        }
        Swap(&array[min],&array[i]);
    }
}
int main()
{
    int array[]={1,4,7,3,9,0,5};
    int n = sizeof(array)/sizeof(array[0]);

    SelectionSort(array,n);

    return 0;
}