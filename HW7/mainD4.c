#include <stdio.h>

//Функция рекурсии суммы цифр числа
void print_num(int num)
{
    //int b = 0;
    if (num > 9)
    print_num(num / 10);
    printf("%d ", (num % 10));
    return;
}

int main ()
{
    int num;
    scanf("%d", &num);
    print_num (num);
    //printf("%d", rec(a));
    return 0;
}
