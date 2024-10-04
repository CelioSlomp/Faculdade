#include <stdio.h>
#include <omp.h>

int main() {
    unsigned int n = 12, factorial = 1;

    #pragma omp parallel for reduction(*: factorial)
    for (unsigned int i = 1; i <= n; i++)
        factorial *= i;

    printf("O fatorial de %u é %u\n", n, factorial);

    return 0;
}