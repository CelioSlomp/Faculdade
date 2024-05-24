#include <stdio.h>

long int fatorial(int i)
{
    if (!i)
        return 1;
    return i * fatorial(i - 1);
}

int main()
{
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Valor negativo.");
    else
        printf("%ld", fatorial(num));

    return 0;
}
