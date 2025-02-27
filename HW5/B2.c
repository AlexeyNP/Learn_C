#include <stdio.h>

int main()
{
	int a, b, i;
	scanf("%d%d", &a, &b);
	for(i = a; i <= b; i++)
	{
		int kvadr;
		kvadr = i * i;
		printf("%d\t", kvadr);
	}
}
