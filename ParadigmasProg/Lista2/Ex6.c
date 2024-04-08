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
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    if (somaDivisores(n1) == n2 && somaDivisores(n2) == n1)
    {
        printf("Sao amigos");
    }
    else
    {
        printf("Nao sao amigos");
    }
    return 0;
}