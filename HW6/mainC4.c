#include <stdio.h>

//Функция вычисляет f(x)
int middle(int x)
{
    int f=0;
    //printf("1. %d ", x);
    //printf("2 %d ", f);
    if((x >= -2) && (x < 2)) //условие 1
        f=x*x;
    else if (x>=2) //условие 2
        f=(x*x)+(4*x)+5;

        else f=4; //условие 3
    //printf("2. %d ", f);
    return f;
}

int main ()
{
    int max=0, x=0, f=0;
    //scanf("%d %d %d %d %d ", &a, &b, &c, &d, &e);
    do
    {
        //x=getchar(); //считываем со стандартного потока символ
        scanf("%d", &x);
        //if(x != " ")
        //{
            //x=x-0x30; //преобразуем из символа в числовое значение
            f = middle(x); //отправляем на вычисление по условию
        //}
        max = max > f ? max : f; //ищем максимальное число после вычислений

    } while (x !=0 );//завершаем если встречается 0
    printf("%d ", max);//выводим результат
    return 0;
}
