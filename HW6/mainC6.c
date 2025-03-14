#include <stdio.h>

//Функция вычисляет f(x)
long long int summa(long long int a)
{
    long long int s=2, i;
    for(i=2; i <= a; i++)
        s *= 2;
    //printf("1. %lld ",s);//выводим результат
    return s;
}

int main ()
{
    long long int a;
    scanf("%lld", &a);
    if(a >2)
    //summ(a);
    printf("%lld", summa(a));//выводим результат
    else if (a == 1 ) printf("%d", 1);//выводим результат
    else if (a == 2 ) printf("%d", 4);//выводим результат
    return 0;
}
