#include <stdio.h>
#define SIZE 10

//сортируем массив на четные и не четные, печатаем все значения
void sort_even_odd(int n, int a[])
{
    _Bool flag;
    int j=0;
    int m=n-1;
    int b[n];
    //перебираем массив
    //_Bool flag;
    for (int v = 0; v < n; v++)
    {
        if (*(a + v) % 2 == 0)
        {
            *(b + j) = *(a + v);
            j++;
        }
        else
        {
            *(b + m) = *(a + v);
            m--;
        }
    }
//Цикл для расстановки четных по убыванию 
    int v = 0;
    int *q = &v;
    do
    {
        flag = 0;
        //int v;
        for (*q = 0; *q < (j - 1); v++)
        {
            if (*(b + *q) < *(b + *q + 1))
            {
                int t = *(b + *q);
                *(b + *q) = *(b + *q + 1);
                *(b + *q + 1) = t;
                flag = 1;
            }
        }
    }
    while (flag);
//Цикл для расстановки не четных по возрастанию
    do
    {
        flag = 0;
        for (*q = 5; *q >= (j -1) && *q < (n); v++)
        {
            /*if (*(b + *q) > *(b + *q + 1))
            {
                int t = *(b + *q);
                *(b + *q) = *(b + *q + 1);
                *(b + v + 1) = t;
                flag = 1;
            }*/
            if (*(b + *q + 1) > *(b + *q))
            {
                int t = *(b + *q);
                *(b + *q) = *(b + *q + 1);
                *(b + *q + 1) = t;
                flag = 1;
            }
        }
    }
    while (flag);
//выводим массив на экран
    for(int i = 0; i < n; i++)
    printf("%d ",b[i]);
    printf("\n");
}

int main() /* считываем входящий поток данных в массив и передаем в sort_array*/
{
    //int i;
    //int arr[SIZE] = {28, 12, 23, 2, 7, 9, 8, 15, 14, 24};
    int arr[SIZE];
    for(int i = 0; scanf("%d", &arr[i]);i++)
    ;
    sort_even_odd(SIZE, arr);
    //return 0;
}
