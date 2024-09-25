#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    fork();
    fork();

    printf("Por que estou aparecendo quatro vezes?\n");

    return 0;
}