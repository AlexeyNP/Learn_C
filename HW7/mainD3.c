#include <stdio.h>

//Функция рекурсии суммы цифр числа
unsigned int rec(unsigned int a)
{
    int b = 0;
    //if (a < 2)
    //{
    //    printf ("%d ", a);
    //    return 0;
    //}
    b = a % 10;
    printf ("%d ", b);
    if (a > 9)
    rec (a / 10);
    return 0;
}

int main ()
{
    int a;
    scanf("%d", &a);
    rec (a);
    //printf("%d", rec(a));
    return 0;
}
