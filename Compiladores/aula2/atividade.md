# Aula 2 - Fases da Compilação - 15/05/2024
---
## Atividade PDF
---
### Exercício 1
Explique como uma otimização bem-sucedida pode impactar um código gerado.

Como uma boa otimização reduz os espaços de memória, contas que precisam
ser feitas, e etc. ele pode reduzir o tempo de execução do programa. Com um exemplo
fica melhor, pense um código que faz 10 iterações, após a otimização ele faz 5, levando
em conta de que cada iteração leve 1 segundo, sem a otimização, o programa iria levar
10 segundos para executar, enquanto que com a otimização ele leva 5 segundos.

---
### Exercício 2
Quais são as diferenças entre os modelos de compilação de duas e três fases? Quais
são as vantagens e desvantagens de cada abordagem?

O modelo de compilação de duas fases não possui a parte de otimização, o que
pela otimização. A principal vantagem de um de duas fases é a de que o código será compilado
faz com que o código que vai ser compilado, seja o código 'cru'. Já o de três fases passa
de forma mais rápida, enquanto que o de três fases não. E as desvantagens são as que 
a de duas fases, sem a otimização, irá passar por todo o código da forma que foi escrita.
Enquanto que a de três fases irá executar o código que tinha sido otimizado pelo compilador.

---
## Atividade Sigaa
---
### Exercício 1
Pesquise e responda:

#### Exercício 1.1
O que são compiladores de passagem única e de duas passagens?

Um compilador de passagem única é um compilador que passa por cada parte da compilação
apenas uma vez, ou seja, análise -> Otimização -> síntese apenas uma vez. Já o de duas passagens
processa o código duas vezes, a primeira faz a parte da análise e a segunda faz a parte da 
otimização e síntese. Fica mais ou menos assim:
1ª análise ->
2ª otimização -> síntese

    Fonte: https://www.geeksforgeeks.org/single-pass-two-pass-and-multi-pass-compilers/

#### Exercício 1.2
Quais são as vantagens e desvantagens dos compiladores de passagem única e de duas passagens?

O de passagem única compila mais rápido, enquanto que o de duas passagens não. O de uma 
passagem não possui tanta otimização como o de duas passagens.

---
### Exercício 2
Que otimização pode ser feita no código abaixo? Mostre o código resultante e justifique sua resposta.

```c
while (i < 10*j) {
    a[i] = i + 2*j;
    ++i;
}
```

---
### Exercício 3
Observe e execute os códigos aula-2-divisao-por-2.c e aula-2-multiplicacao-por-0.5.c.
Compile e execute cinco vezes:
> gcc aula-2-multiplicacao-por-0.5.c; for i in $(seq 5); do time ./a.out 1000000000; done
> gcc aula-2-divisao-por-2.c; for i in $(seq 5); do time ./a.out 1000000000; done


#### Exercício 3.1
O que fazem os códigos?

Ambos dividem por 2 o valor da variável 'a'.

#### Exercício 3.2
Existem diferenças entre eles?

Segundo a lógica matemática não pois ambos geram o mesmo resultado. 
#### Exercício 3.3
Os resultados da execução acima foram diferentes? Por que isso acontece? 

Os resultados não foram diferentes, mas o tempo de execução de cada um foi de
cerca de 0,2 segundos de diferença. <br>

Multiplicando por 0.5:  real    0m1.370s <br>
Dividindo por 2:        real    0m1.574s