#include <stdio.h>
#define SIZE 20

int main()
{
    FILE *f;
    FILE *of;
    int n;
    unsigned int digit;
    //char s;
    f = fopen("inputg2.txt", "r"); // режим чтения
    of = fopen("outputg2.txt", "w"); // режим записи
    fscanf(f, "%d", digit);
    while (digit < 27)
    {
        for(int i = 1; i < digit; i++)
        {
            if((i % 2) != 0)
            {
                fprintf (of, "%d", n);
                n++;
            }
            else
            fprintf (of, "%c", 65);
        }
    }
    fclose (f);
    fclose (of);
}
