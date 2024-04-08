#include <stdio.h>
#include <string.h>

int validarCPF(char *cpf)
{
    char dezena, unidade;

    if (strlen(cpf) != 11)
        return 0;
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) ||
             (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) ||
             (strcmp(cpf, "99999999999") == 0))
        return 0;

    int soma = 0;
    for (int i = 0, j = 10; i < 9; i++, j--)
    {
        soma += (cpf[i] - '0') * j;
    }
    if (soma % 11 == 0 || soma % 11 == 1)
        dezena = '0';
    else
        dezena = 11 - (soma % 11) + '0';

    soma = 0;

    for (int i = 0, j = 11; i < 10; i++, j--)
    {
        soma += (cpf[i] - '0') * j;
    }

    if (soma % 11 == 0 || soma % 11 == 1)
        unidade = '0';
    else
        unidade = 11 - (soma % 11) + '0';

    if (cpf[9] == dezena && cpf[10] == unidade)
        return 1;

    return 0;
}

int main()
{
    char cpf[11];

    scanf("%s", &cpf);

    if (validarCPF(cpf))
        printf("CPF valido.");
    else
        printf("CPF invalido.");

    return 0;
}