#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exercicio 2, cria um vetor embaralhado para ser ordenado.
int *criarVetorEmbaralhado(int n)
{
    // n = Número de elementos do array

    // Aloca a memoria para a lista
    int *lista = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        lista[i] = rand() % n;
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

// QuickSort em troca(), particiona() e quicksort()
void troca(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int particiona(int lista[], int a, int b)
{
    int x = lista[b];

    int i = (a - 1);

    for (int j = a; j < b; j++)
    {
        if (lista[j] <= x)
        {

            troca(&lista[a], &lista[j]);
            a++;
        }
    }
    troca(&lista[a], &lista[b]);

    return (a);
}

void quickSort(int lista[], int a, int b)
{
    if (a < b)
    {
        int indicePivo = particiona(lista, a, b);
        quickSort(lista, a, indicePivo - 1);
        quickSort(lista, indicePivo + 1, b);
    } // If a<b
} // quickSort

// MergeSort em Merge() e mergeSort()
void merge(int lista[], int a, int q, int b)
{
    int const n1 = q - a + 1;
    int const n2 = b - q;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = lista[a + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = lista[q + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = a;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            lista[k] = L[i];
            i++;
        }
        else
        {
            lista[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        lista[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        lista[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int lista[], int a, int b)
{
    if (a < b)
    {
        int q = (a + b - 1) / 2;
        mergeSort(lista, a, q);
        mergeSort(lista, q + 1, b);
        merge(lista, a, q, b);
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;
    // Pega o tempo para o rand funcionar certo
    srand(time(NULL));
    int array[] = {2, 1};

    int *teste = bubbleSort(array, 2);

    // Executa o bubbleSort e calcula o seu tempo
    start = clock();

    teste = bubbleSort(criarVetorEmbaralhado(10), 10);
    teste = bubbleSort(criarVetorEmbaralhado(100), 100);
    teste = bubbleSort(criarVetorEmbaralhado(1000), 1000);
    teste = bubbleSort(criarVetorEmbaralhado(10000), 10000);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("BubbleSort: %f segundos\n", cpu_time_used);

    // Executa o quickSort e calcula o seu tempo
    start = clock();

    quickSort(criarVetorEmbaralhado(10), 0, 10 - 1);
    quickSort(criarVetorEmbaralhado(100), 0, 100 - 1);
    quickSort(criarVetorEmbaralhado(1000), 0, 1000 - 1);
    quickSort(criarVetorEmbaralhado(10000), 0, 10000 - 1);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("QuickSort: %f segundos\n", cpu_time_used);

    // Executa o mergeSort e calcula o seu tempo
    start = clock();

    mergeSort(criarVetorEmbaralhado(10), 0, 10);
    mergeSort(criarVetorEmbaralhado(100), 0, 100);
    mergeSort(criarVetorEmbaralhado(1000), 0, 1000);
    mergeSort(criarVetorEmbaralhado(10000), 0, 10000);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("MergeSort: %f segundos\n", cpu_time_used);

    return 0;
} // main