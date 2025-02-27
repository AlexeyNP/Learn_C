#include <stdio.h>

int main()
{
	int a, b, c=1, max, min;
	scanf("%d", &a);
	if(a!=0)
	{
		do
		{
			b = a % 10;
			max = b > c ? b : c;
			
			min = b < c ? b : c;
			c = b;
			a /= 10;
		}
		while(a==0);
		printf("%d %d", min, max);
	}
	else printf("%d", a);
}
