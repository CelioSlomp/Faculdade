#include <stdio.h>

unsigned long long int fatorial(int num)
{
    if (!num)
        return 1;
    return num * fatorial(num - 1);
}

int main()
{
    int x = 21;

    printf("Fatorial de %d é: %llu\n", x, fatorial(x));

    return 0;
}