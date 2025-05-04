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

void SwapArr(int *arr,int i,int j)
{
 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
}

void BubbleSort(int* arr, int n)
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
    }
    printf("%d\n", arr[2] + arr[3]);
    //if(noSwap)
    //break;
}

int main()
{
    int arr[SIZE];
    Input(&arr[0], SIZE);
    BubbleSort(arr, SIZE);
    //printf("%d\n",BubbleSort(arr,SIZE));
}
