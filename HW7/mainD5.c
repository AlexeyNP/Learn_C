#include <stdio.h>

//Функция рекурсии суммы цифр числа
void print_num(int digit)
{
    int r = (digit % 10) % 2;
    if (digit > 1)
    print_num(digit / 2);
    printf("%d", r);
    return;
}

int main ()
{
    int digit;
    scanf("%d", &digit);
    print_num (digit);
    return 0;
}
