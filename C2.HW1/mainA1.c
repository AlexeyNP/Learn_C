#include <stdio.h>

int main() {
    int n, current, max, count;

    // Читаем количество чисел
    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }
    // Читаем первое число и инициализируем максимум
    scanf("%d", &current);
    max = current;
    count = 1;
    for (int i = 1; i < n; i++) {
        scanf("%d", &current);

        if (current > max) {
            max = current;
            count = 1;
        } else if (current == max) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
