#include <stdio.h>
#include <inttypes.h>

#define SIZE 5

int Input(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    return i;
}

int Min_value(int *arr,int len)
{
int min=arr[0],i;
 for (i = 1; i < len; i++)
 if (min > arr[i])
 min = arr[i];
 return min;
}

int main()
{
    int arr[SIZE];
    Input(&arr[0], SIZE);
    printf ("%d", Min_value(arr, SIZE));
}
