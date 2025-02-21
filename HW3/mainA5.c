#include <stdio.h>

int main(void)
{
    int a, b, c;
    float d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    d=((float) a+ (float) b+ (float) c)/3;
    printf("%.2f", d);
    return 0;
}
