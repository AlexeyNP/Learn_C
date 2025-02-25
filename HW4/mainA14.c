#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    scanf ("%d", &a);
    b = a%10; // единицы
    c = (a/10)%10; //десятки
    d = (a/100)%10; //сотки
    a = b > c ? b : c;
    a = a > d ? a : d;
    printf ("%d\n", a);
}
