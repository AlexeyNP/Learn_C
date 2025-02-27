#include <stdio.h>

int main()
{
	int a, sum;
	scanf("%d", &a);
	sum = (a / 1000) / 10;
	sum += (a / 1000) % 10;
	sum += (a / 100) % 10;
	sum += (a / 10) % 10;
	sum += a % 10;
	printf("%d", sum);
}
