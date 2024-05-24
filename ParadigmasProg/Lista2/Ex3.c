#include <stdio.h>
int main()
{
    int n1, n2, tmp;
    n1 = 0;
    n2 = 1;

    int num;
    printf("Digite um n-esimo termo: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Valor menor que 0.");
    else
    {
        while (num--)
        {
            tmp = n1;
            n1 = n2;
            n2 = tmp + n2;
            printf("%d\n", n1);
        }
    }

    return 0;
}