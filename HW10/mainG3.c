#include <stdio.h>
#include <string.h>
#define SIZE 1001

int main()
{
    FILE *input = input = fopen("input.txt", "r"); // режим чтения;
    FILE *output = fopen("output.txt", "w"); // режим записи;
    char str[SIZE];
    fgets( str, SIZE, input );
    
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') 
    {
        str[len - 1] = '\0';
        len--;
    }
    
    char last_char = str[len-1];
    int flag = 1;
    for ( int i = 0; i < len - 1; i++ )
    //for ( int i = 0; i < len; i++ )
    {
        if ( str[i] == last_char )
        {
            if (!flag) fprintf(output, " ");
            fprintf(output, "%d ", i);
            //printf("%d ", i);
            //printf("%d ", len);
            //printf("%d ", last_char);
            //printf("\n");
            flag = 0;
        }
    }
    fclose (input);
    fclose (output);
    return 0;
}
