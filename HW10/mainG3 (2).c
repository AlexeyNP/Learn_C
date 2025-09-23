#include <stdio.h>
#include <string.h>
#define SIZE 1000

int main()
{
    FILE *input = input = fopen("input.txt", "r"); // режим чтения;
    FILE *output = fopen("output.txt", "w"); // режим записи;
    char str[SIZE];
    fgets( str, SIZE, input );
    size_t len = strlen(str);
    char last_char = str[len-1];
    int first = 1;
    for ( int i = 0; i < len - 1; i++ )
    {
        if ( str[i] == last_char )
        {
            if (!first) fprintf(output, " ");
            fprintf(output, "%d", i);
            first = 0;
        }
    }
    fclose (input);
    fclose (output);
}
