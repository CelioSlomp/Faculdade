#include <stdio.h>

int multiplicacao(int n1, int n2)
{
    int tmp;
    if (n1 < 0 && n2 < 0)
    {
        int tmp = n1;
        n1 -= tmp;
        n1 -= tmp;

        tmp = n2;
        n2 -= tmp;
        n2 -= tmp;
    }

    if (n1 && n2)
    {
        if (n2 > 0)
            return (n1 + multiplicacao(n1, n2 - 1));
        return (n2 + multiplicacao(n1 - 1, n2));
    }
    else
        return 0;
}

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    printf("%d * %d resulta em: %d", n1, n2, multiplicacao(n1, n2));

    return 0;
}