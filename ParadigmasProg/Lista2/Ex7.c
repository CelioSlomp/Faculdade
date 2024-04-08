#include <stdio.h>

int somaDivisores(int num)
{
    int soma = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
            soma += i;
    }
    return soma;
}

int main()
{
    int n1;
    scanf("%d", &n1);

    if (somaDivisores(n1) == n1)
        printf("E perfeito.");
    else
        printf("Nao e perfeito");

    return 0;
}