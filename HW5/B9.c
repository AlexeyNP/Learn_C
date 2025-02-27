#include <stdio.h>

int main()
{
	int a, b, c, d, e, f;
	scanf("%d", &a);
	b = (a / 1000) / 10;
	b %= 2;
	c = (a / 1000) % 10;
	c %= 2;
	d = (a / 100) % 10;
	d %= 2;
	e = (a / 10) % 10;
	e %= 2;
	f = a % 10;
	f %= 2;
	if(a != 0 && b==0 && c==0 && d==0 && e==0 && f==0) printf("YES");
	else printf("NO");
}
