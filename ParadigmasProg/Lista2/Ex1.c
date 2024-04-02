#include <stdio.h>
int main()
{
    int num;
    long int fatorial = 1;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    for (int i = 1; i < num + 1; i++)
    {
        fatorial = fatorial * i;
    }

    printf("%d", fatorial);

    return 0;
}