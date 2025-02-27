#include <stdio.h>

int main()
{
	int a, b, c, d, e, f;
	scanf("%d", &a);
	b = (a / 1000) / 10;
	c = (a / 1000) % 10;
	d = (a / 100) % 10;
	e = (a / 10) % 10;
	f = a % 10;
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);
	printf("%d\n", f);
	if(a>0 && b>0 && c>0 && d>0 && e>0 && f>0) printf("%d%d%d%d%d", f, e, d, c, b);
	else if (a>0 && c>0 && (d>0 || e>0 || f>0)) printf("%d%d%d%d", f, e, d, c);
	else if (a>0 && d>0 && (e>0 || f>0)) printf("%d%d%d", f, e, d);
	else if (a>0 && e>0 && f>0) printf("%d%d", f, e);
	else if (a>0 && e>0 && f==0) printf("%d", e);
	else if (a>0 && f>0) printf("%d", f);
	else printf("%d", a);
}
