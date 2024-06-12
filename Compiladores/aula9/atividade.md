# Aula 9 - Anlálise Sintática - 10/06/2024

---

## Anotações

* Ocorre um erro quando há falha na geração da árvore sintática.
* Quando acontecer algum erro, o compilados deve falar o problema e tentar corrigir ele.
* Modo pânico: o parser ignora as entradas até chegar em um token aceito.
  - Exemplo: a = bc a + d;
  - O erro acontece entre b e c, no qual falta um operador.
  - O modo pânico ignora o 'c' e o 'a', e considera o '+' em diante.

---