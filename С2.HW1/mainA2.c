#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    char c;
    // Пропускаем пробел после числа
    scanf(" ");

    while (1)
    {
        scanf("%c", &c);

        if (c == '.')
        {
            printf(".");
            break;
        }

        if (c == ' ')
        {
            printf(" ");
            continue;
        }

        // Для строчных букв
        if (c >= 'a' && c <= 'z')
        {
            int n = c - 'a';
            int p = (n + N) % 26;
            printf("%c", 'a' + p);
        }
        // Для заглавных букв
        else if (c >= 'A' && c <= 'Z')
        {
            int n = c - 'A';
            int p = (n + N) % 26;
            printf("%c", 'A' + p);
        }
    }

    return 0;
}
