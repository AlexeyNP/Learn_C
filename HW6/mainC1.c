#include <stdio.h>

int main(void)
{
   int c;
   while ((c=getchar()) != '\n')
       if(c <= 0)
           putchar(c);
   return 0;
}
