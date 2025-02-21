#include <stdio.h>

int main(void)
{
    int a, sum;
    scanf ("%d", &a);
    sum = a%10; // единицы
    sum += (a/10)%10; //десятки
    sum += (a/100)%10; //сотки
    printf ("%d\n", sum);
}
