#include <stdio.h>

int main ()
{
    int c, i, ndigit[10];
    for (i = 0; i < 10; i++)
    ndigit[i] = 0;

    while ((c = getchar()) != '\n')
    {
        switch (c)
        {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            ndigit[c - '0']++;
            break;
        }
    }
    for(i = 0; i < 10; i++)
    {
        if(ndigit[i] > 0)
        printf("%d %d ", i, ndigit[i]);
    }
}
