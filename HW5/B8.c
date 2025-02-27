#include <stdio.h>

int main()
{
	int a, b, c, d, e, f, g = 0;
	scanf("%d", &a);
	b = (a / 1000) / 10;
	if(b==9) g++;
	c = (a / 1000) % 10;
	if(c==9) g++;
	d = (a / 100) % 10;
	if(d==9) g++;
	e = (a / 10) % 10;
	if(e==9) g++;
	f = a % 10;
	if(f==9) g++;
	if(a == 0 || g > 1) printf("NO");
	else printf("YES");
}
