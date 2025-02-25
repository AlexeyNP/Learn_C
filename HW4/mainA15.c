#include <stdio.h>

int main(void)
{
    float x1, y1, x2, y2;
    float m, b;
    scanf ("%f%f%f%f", &x1, &y1, &x2, &y2);
    m = (y2 - y1) / (x2 - x1);
    b = y1 - (m * x1);
    printf ("%.2f %.2f\n", m, b);
}
