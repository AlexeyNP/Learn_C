#include <stdio.h>

int main()
{
    unsigned int N, K;
    scanf("%u %u", &N, &K);

    unsigned int result = (N >> K) | (N << (32 - K));

    printf("%u\n", result);

    return 0;
}
