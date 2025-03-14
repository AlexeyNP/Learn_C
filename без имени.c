#include <stdio.h>
#include <conio.h>

int middle(int x)
{
    int f=0;
    printf("1. %d ", x);
    //printf("2 %d ", f);
    if((x >= -2) && (x < 2))
        f=x*x;
    else if (x>=2)
        f=(x*x)+(4*x)+5;

        else f=4;
    //printf("2. %d ", f);
    return f;
}

int main (){
    char x;
    int max=0, f=0;
    //puts("Exit('.'):");
    do{
        x = _getch(); // считать введённый со стандартного потока ввода символ
        if(x>='a' && x<='z') //все символы лежат подряд ‘a’=97, ‘b’=98, ‘c’=99, …
        f = middle(x);
        }
        while (x != '0'); // пока введенный символ не ноль
        max = max > f ? max : f;
        putchar("%d ", max);
        //printf("3. %d ", max);
        return 0;
}
