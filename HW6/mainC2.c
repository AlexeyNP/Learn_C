#include <stdio.h>

int power(int n, int p)
{
	int i, s=1;
	for(i=1; i<=p; i++)
		s *= n;
	return s;
}

int main ()
{
    int n, p;
    scanf("%d%d", &n, &p);
    printf("%d", power(n, p));
    return 0;
}
