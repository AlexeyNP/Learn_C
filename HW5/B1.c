#include <stdio.h>

int main()
{
	int a, i;
	scanf("%d/n", &a);
	for(i = 1; i <= a; i++)
	{
		int kvadr, kub;
		kvadr = i * i;
		kub = i * i * i;
		printf("%d\t%d\t%d\n", i, kvadr, kub);
	}
}
