#include <stdio.h>
#define SIZE 20

void sort_array(int size, int a[]) /*сортируем массив по возврастанию и печатаем все значения*/
{
    int i = 0;
    _Bool flag;
    do {
        flag = 0; // сбросить флаг
        for (int j = size-2; j >= i ; j-- )
            if ( a[j] > a[j+1] ) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                flag = 1; // поднять флаг если есть обмен
            }
        i++;
    }
    while ( flag ); // выход при flag = 0
    for(i = 0; i < size; i++)
    printf("%d ",a[i]);
    printf("\n");
}

int main() /* считываем входящий поток данных в массив и передаем в sort_array*/
{
    //int i;
    //int arr[SIZE] = {4, -5, 3, 10, -4, -6, 8, -10, 1, 0};
    int arr[SIZE];
    for(int i = 0; scanf("%d", &arr[i]);i++)
    ;
    sort_array(SIZE, arr);
    //return 0;
}
