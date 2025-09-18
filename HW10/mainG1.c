#include <stdio.h>
#include <string.h>
#define SIZE 110

int main()
{
    FILE *f = fopen("input.txt", "r"); // режим чтения;
    FILE *of = fopen("output.txt", "w"); // режим записи;
    char s[SIZE];
    //while ( !feof(f)) {
        fgets( s, SIZE, f );
        //fprintf (of, "%s, %s, %s", s, s, s);
    //}
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }
    fprintf (of, "%s, %s, %s", s, s, s);
    fprintf (of, " %d", len);
    fclose (f);
    fclose (of);
}
