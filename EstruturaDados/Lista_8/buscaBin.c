#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *criarVetorOrdenado(int n)
{
    int *lista = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        lista[i] = i;

    return lista;
}

int *criarVetorEmbaralhado(int n)
{
    // n = Número de elementos do array
    // Aloca a memoria para a lista
    int *lista = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        lista[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int r = rand() % n;
        int tmp = lista[i];
        lista[i] = lista[r];
        lista[r] = tmp;
    }

    return lista;
} // criarVetorEmbaralhado

// BubbleSort
int *bubbleSort(int lista[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (lista[j] > lista[i])
            {
                int tmp = lista[i];
                lista[i] = lista[j];
                lista[j] = tmp;
            } // if
        }     // for j
    }         // for i

    return lista;
} // bubbleSort

int buscaLinear(int *lista, int tam, int v)
{
    for (int i = 0; i < tam; i++)
    {
        if (lista[i] == v)
            return i;
    }
    return -1;
}

int buscaBinaria(int *lista, int tam, int v)
{
    int inicio = 0;
    int fim = tam - 1;
    int meio;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (lista[meio] > v)
            fim = meio - 1;
        else
        {
            if (lista[meio] < v)
                inicio = meio + 1;
            else
                return meio;
        }
    }
    return -1;
}

int minhaPot(int b, int n)
{
    int num = b;
    for (int i = 0; i < n - 1; i++)
        num *= b;
    return num;
}

int main()
{
    // faz o rand funcionar direito
    srand(time(NULL));

    clock_t start, end;
    double cpu_time_used;
    for (int i = 1; i < 6; i++)
    {
        int tamLis = minhaPot(10, i);
        int *lista = criarVetorEmbaralhado(tamLis);

        start = clock();
        int busLin = buscaLinear(lista, tamLis, tamLis - 3);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Busca Linear com %d elementos: %f segundos\n", tamLis, cpu_time_used);
        start = clock();
        int busBin = buscaBinaria(bubbleSort(lista, tamLis), tamLis, tamLis - 3);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Busca Binaria com bubblesort de  %d elementos: %f segundos\n", tamLis, cpu_time_used);
    }
    return 0;
}