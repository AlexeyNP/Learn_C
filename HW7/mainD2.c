#include <stdio.h>

//Функция рекурсии суммы цифр числа
unsigned int rec(unsigned int a)
{
   if (a <= 1)
   return 1;
   return a + rec(a-1);
}

int main ()
{
    int a;
    scanf("%d", &a);
    printf("%d", rec(a));
    return 0;
}
