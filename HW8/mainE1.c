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

void Print(int *arr,int len)
{
    int i;
    for (i = 0; i < len; i++)
    printf("%d ",arr[i]);
    printf("\n");
}

void Arithmitic_mean(int arr[],int len)
{
    float k = 0;
    for (int i = 0; i < len; i++)
    k += arr[i];
    k /=len;
    printf ("%.2f ", k);
}

int main()
{
    int arr[SIZE];
    Input(&arr[0], SIZE);
    Arithmitic_mean(arr,SIZE);
    //Print (arr, SIZE);
}
