#include <stdio.h>
#define SIZE 26

int main()
{
    FILE *in_f;
    FILE *out_f = fopen("output.txt", "w"); // режим записи;
    int n = 65;
    //int d = 9;
    int schet = 2;
    int digit;
    if ( ( in_f = fopen("input.txt", "r") ) == NULL)
    {
        puts ( "NULL");
    }
    else
    {
        fscanf ( in_f, "%d", &digit );
        for(int i = 1; i <= digit; i++)
        {
            if((i % 2) != 0)
            {
                fprintf (out_f, "%c", n);
                n++;
            }
            else if ( schet < 9 )
            {
                fprintf (out_f, "%d", schet);
                schet += 2;
            }
            else
            {
                schet = 2;
                fprintf (out_f, "%d", schet);
                schet += 2;
            }
        }
    }
    fclose (in_f);
    fclose (out_f);
}
