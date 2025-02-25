#include <stdio.h>

int main(void)
{
    int a;
    scanf ("%d", &a);
    if (a==12 || a==1 || a==2)
		{
			printf("winter");
		}
		else if (a>2 && a<6)
		{
			printf("spring");
		}
		else if (a>5 && a<9)
		{
			printf("summer");
		}
    else printf ("autumn");
}
