// Testar com 100000000 (100 milhões)

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{

    int i;
    int casos = atoi(argv[1]);
    double a;

    for (i = 0; i < casos; i++)
    {
        a = 100000000.0;
        a *= 0.5;
    }

    printf("%lf\n", a);

    return 0;
}