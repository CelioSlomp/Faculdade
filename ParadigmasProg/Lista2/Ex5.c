#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int verifPrimo(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    int numPrimos = 0;
    int contador = 0;
    int r;

    while (numPrimos < 25)
    {
        r = rand() % 100 + 1;
        if (verifPrimo(r))
        {
            numPrimos++;
        }
        contador++;
    }

    printf("Numeros gerados: %d\n", contador);

    return 0;
}