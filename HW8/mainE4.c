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

void print(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
}


void SwapArr(int arr[],int i,int j)
{
 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
}

void BubbleSort(int arr[], int n)
{
    int noSwap;
    for(int i=n-1; i>=0; i--)
    {
        noSwap = 1;
        for(int j=0; j<i; j++)
        {
            if(arr[j]>arr[j+1])
                {
                    SwapArr(arr,i,j);
                    noSwap = 0;
                }
        }
        if(noSwap)
        break;
    }
}

int main()
{
    int arr[SIZE] = {4, -5, 3, 10, -4, -6, 8, -10, 1, 0};
    //Input(&arr[0], SIZE);
    BubbleSort(arr, SIZE);
    print(arr, SIZE);
    //printf("%d\n", arr[SIZE]);
    printf("%d\n", arr[8]);
    printf("%d\n", arr[9]);
    printf("%d", arr[8]+arr[9]);
}
