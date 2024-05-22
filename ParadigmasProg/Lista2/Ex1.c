#include <stdio.h>
int main()
{
    int num;
    long int fatorial = 1;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Valor negativo\n");
    else
    {
        for (int i = 1; i < num + 1; i++)
        {
            fatorial = fatorial * i;
        }

        printf("%ld\n", fatorial);
    }
    return 0;
}