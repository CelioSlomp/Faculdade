#include <stdio.h>

int fibonacci(int n1, int n2)
{
    if (n1 > 10000)
        return 0;
    printf("%d\n", n2);

    return fibonacci(n2, n1 + n2);
}

int main()
{
    fibonacci(0, 1);
    return 0;
}