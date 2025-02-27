#include <stdio.h>

int main()
{
	int a, b, i, kvadr = 0;
	scanf("%d%d", &a, &b);
	for(i = a; i <= b; i++)
	{
		kvadr += (i * i);
	}
	printf("%d\t", kvadr);
}
