#include <stdio.h>

//Функция рекурсии суммы цифр
int rec(int a)
{
   if (a > 0)
   return a%10 + rec(a/10);
   else return 0;
}

int main ()
{
    int a;
    scanf("%d", &a);
    rec(a);
    printf("%d", a);
    return 0;
}
