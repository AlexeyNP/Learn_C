#include <stdio.h>
#define SIZE 20

//сортируем массив на четные и не четные, печатаем все значения
void sort_even_odd(int n, int a[])
{
    int j = 0;
    int b[n];
//обнуление массива b
    for(int i = 0; i < n; i++)
    b[i] = 0;
    int v = 0;
//перебираем массив, расставляем четные справа
    int m;
    for (v = 0; v < n; v++)
    {
        if (a[v] % 2 == 0)
        {
            b[j] = a[v];
            j++;
        }
    }
//перебираем массив, расставляем не четные слева
    for (v = 0; v < n; v++)
    {
        if (a[v] % 2 != 0)
        {
            b[j] = a[v];
            m = j;
            j++;
        }
    }
//перегружаем из массива a в массив b
    for(int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

int main() /* считываем входящий поток данных в массив и передаем в sort_array*/
{
    //int i;
    int arr[SIZE] = {11, 25, 5, -48, -15, -16, 27, 43, -22, -1, -39, -16, -28, 28, -31, -36, 17, 17, -39, -50};
    //int arr[SIZE];
    //for(int i = 0; scanf("%d", &arr[i]);i++)
    //;
    sort_even_odd(SIZE, arr);
    //return 0;
}
