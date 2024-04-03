#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    int r = rand() % 100 + 1;
    printf("%d", r);

    return 0;
}