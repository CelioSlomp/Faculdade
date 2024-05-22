#include <stdio.h>

int fibonacci(int n1, int n2, int n)
{
    if (!n)
        return 0;
    if (n1 > 10000)
        return 0;
    printf("%d\n", n2);

    return fibonacci(n2, n1 + n2, --n);
}

int main()
{
    int num;
    printf("Digite um n-esimo termo: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Valor menor que 0.");
    else
    {
        fibonacci(0, 1, num);
    }
    return 0;
}