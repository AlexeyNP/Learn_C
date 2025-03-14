#include <stdio.h>

//Функция вычисляет f(x)
int summa(int a)
{
    int s=1, i;
    for(i=2; i <= a; i++)
        s += i;
    //printf("1. %d ",s);//выводим результат
    return s;
}

int main ()
{
    int a;
    scanf("%d", &a);
    if(a >2)
    //summ(a);
    printf("%d ", summa(a));//выводим результат
    else if (a == 1 ) printf("%d ", 1);//выводим результат
    else printf("%d ", 3);//выводим результат
    return 0;
}
