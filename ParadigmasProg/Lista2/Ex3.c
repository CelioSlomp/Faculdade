#include <stdio.h>
int main()
{
    int n1, n2, tmp;
    n1 = 0;
    n2 = 1;

    while (n1 < 10000)
    {
        tmp = n1;
        n1 = n2;
        n2 = tmp + n2;
        printf("%d\n", n1);
    }

    return 0;
}