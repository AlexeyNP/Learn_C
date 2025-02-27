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
	if(a > 9 && (b == c || c == d || d == e || e == f)) printf("YES");
	else printf("NO");
}
