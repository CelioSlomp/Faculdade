#include <stdio.h>

int qtdDigitos(int num)
{
    if (num / 10 == 0)
        return 1;
    return 1 + qtdDigitos(num / 10);
}

int main()
{

    int num;
    scanf("%d", &num);

    printf("O numero %d possui %d digitos.", num, qtdDigitos(num));

    return 0;
}