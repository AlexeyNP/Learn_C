#include <stdio.h>
#define SIZE 20

int main()
{
    FILE *f;
    FILE *of;
    int n;
    char s[SIZE];
    f = fopen("input.txt", "r"); // режим чтения
    of = fopen("output.txt", "w"); // режим записи
    while ( !feof(f)) {
        fscanf( f, "%s", s );
        fprintf (of, "%s", s);
        for( n = 1; n < 3; n++ )
        fprintf (of, ", %s", s);
    }
    fprintf (of, " %d", n);
    fclose (f);
    fclose (of);
}
// После сканирования и записи в массив S нужно посчитать размер массива и 
// в качестве условия для FOR ипользовать этот размер.
