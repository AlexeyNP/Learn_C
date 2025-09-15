#include <stdio.h>
#define SIZE 21

//сортируем массив на четные и не четные, печатаем все значения
void sort_even_odd(int n, int a[])
{
    _Bool flag;
    int j=0;
    int m=n-1;
    int b[n];
//обнуление массива b
    for(int i = 0; i < n; i++)
    b[i] = 0;
    int v = 0;
//перебираем массив, расставляем четные справа, не четные слева
    for (v = 0; v < n; v++)
    {
        if (a[v] % 2 == 0)
        {
            b[j] = a[v];
            j++;
        }
        else
        {
            b[m] = a[v];
            m--;
        }
    }
//Цикл для расстановки четных по убыванию 
    v = 0;
    do
    {
        flag = 0;
        for (v = 0; v < (j - 1); v++)
        {
            if (b[v] < b[v + 1])
            {
                int t = b[v];
                b[v] = b[v + 1];
                b[v + 1] = t;
                flag = 1;
            }
        }
    }
    while (flag);
/*
 * //выводим массив на экран
    for(int i = 0; i < n; i++)
    printf("%d ", b[i]);
    printf("\n");
    printf("%d ", v);
    printf("\n");
    printf("%d ", j);
    printf("\n");
*/
    
//Цикл для расстановки не четных по убыванию
    do
    {
        flag = 0;
        //for (v = (j - 1); v <= (n); v++)
        for (v = j; v < (n - 1); v++)
        {
            if (b[v + 1] > b[v])
            {
                int t = b[v];
                b[v] = b[v + 1];
                b[v + 1] = t;
                //printf("%d ", b[v]);
				//printf("\n");
				//printf("%d ", b[v + 1]);
				//printf("\n");
                flag = 1;
            }
            //printf("\n");
        }
    }
    while (flag);
//выводим массив на экран
//    for(int i = 0; i < n; i++)
//    printf("%d ",b[i]);
//    printf("\n");
//перегружаем из массива a в массив b
	for(int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
//выводим массив на экран
    for(int i = 0; i < n; i++)
    printf("%d ",a[i]);
}

int main() /* считываем входящий поток данных в массив и передаем в sort_array*/
{
    //int i;
    int arr[SIZE] = {20, 11, 25, 5, -48, -15, -16, 27, 43, -22, -1, -39, -16, -28, 28, -31, -36, 17, 17, -39, -50};
    //int arr[SIZE];
    //for(int i = 0; scanf("%d", &arr[i]);i++)
    //;
    sort_even_odd(SIZE, arr);
    //return 0;
}
