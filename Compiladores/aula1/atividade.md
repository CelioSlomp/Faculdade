# Aula 1 - Introdução à compilação - 08/05/2024
---
## Atividade Sigaa
---
### Exercício 1

Utilizando uma linguagem de programação que disponha de implementação compilada, 
escolhida livremente um algoritmo e implemente-o (ex: Fatorial, Série de Fibonacci, 
Torre de Hanói, Insertion Sort etc.).

```C
#include <stdio.h>

    unsigned long long int fatorial(int num)
    {
        if (!num)
            return 1;
        return num * fatorial(num - 1);
    }

    int main()
    {
        int x = 21;

        printf("Fatorial de %d é: %llu\n", x, fatorial(x));

        return 0;
    }
```
---
### Exercício 2

Compile-o utilizando pelo menos dois compiladores diferentes. Por exemplo, 
caso faça em C, escolha entre GCC, CLang, VC, Turbo C etc. Repita o processo de 
compilação 20 vezes, armazene o tempo necessário para cada compilação e anote-os 
em uma tabela. Anote também a média de tempo necessário e o desvio padrão.

Resposta: Eu coloquei um for no bash para rodar a execução e armazenei o tempo do for.
Para pegar as medias eu dividi o tempo do for na compilação por 20.

CLang :

    real	0m0,742s 
    user	0m0,364s
    sys	    0m0,369s

medias (dividi por 20 as acima) :

    real    0,037
    user    0,018
    sys     0,018

GCC :

    real	0m0,402s
    user	0m0,292s
    sys	    0m0,101s

medias (dividi por 20 as acima) :

    real 0,020
    user 0,014
    sys 0,005
---
### Exercício 3
Estipule um tempo máximo de parada (ex: 1 hora) e indique qual é o maior 
valor de n para o qual o seu algoritmo fornece resultado, utilizando as soluções 
geradas pelos dois compiladores. Houve alguma diferença?

Resposta: <br>
Pelo fato de eu ter usado c e 'unsigned long long int', o limite não é tempo, e sim o tipo das variáveis.

GCC: valor 20.
CLang: valor 20.
---
### Exercício 4
Execute 20 vezes o programa para o valor encontrado na questão anterior, 
para cada compilador, e armazene os tempos em uma tabela. Anote também a média 
de tempo necessário e o desvio padrão.

Clang : 

    real	0m0,023s
    user	0m0,016s
    sys	0m0,007s

medias :

    real    0,001
    user    0,001
    sys     0,0003

GCC :

    real	0m0,022s
    user	0m0,013s
    sys	    0m0,010s

medias :

    real    0,001
    user    0,0006
    sys     0,0005
---
### Exercício 5
Os códigos gerados pelos compiladores escolhidos são iguais? Justifique.

Não são iguais

```bash
diff -y a b
    Binary files a and b differ

    strings a | tail
        .fini
        .rodata
        .eh_frame_hdr
        .eh_frame
        .init_array
        .fini_array
        .dynamic
        .data
        .bss
        .comment

    strings b | tail
        .rodata
        .eh_frame_hdr
        .eh_frame
        .init_array
        .fini_array
        .dynamic
        .got.plt
        .data
        .bss
        .comment
```