#include <stdio.h>
#include <inttypes.h>

#define SIZE 10

int Input(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    return i;
}

void PosMin(int arr[],int len)
{
    int min=arr[0],i,pos=0;
    for (i = 1; i < len; i++)
        if (min > arr[i])
        {
            min = arr[i];
            pos = i;
        }
    printf ("%d ", ++pos);
    printf ("%d ", arr[--pos]);
}

void PosMax(int arr[],int len)
{
    int max=arr[0],i,pos=0;
    for (i = 1; i < len; i++)
        if (max < arr[i])
        {
            max = arr[i];
            pos = i;
        }
    printf ("%d ", ++pos);
    printf ("%d ", arr[--pos]);
}

int main()
{
    int arr[SIZE];
    Input(&arr[0], SIZE);
    PosMax(arr, SIZE);
    PosMin(arr, SIZE);
}
