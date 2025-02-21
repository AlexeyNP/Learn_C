#include <stdio.h>

int main(void)
{
    int a, proizv;
    scanf ("%d", &a);
    proizv = a%10; // единицы
    proizv *= (a/10)%10; //десятки
    proizv *= (a/100)%10; //сотки
    printf ("%d\n", proizv);
}
