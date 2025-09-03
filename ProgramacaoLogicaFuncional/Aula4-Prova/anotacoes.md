# Anotacoes para a prova sobre paradigma lógico

### Conceitos gerais
* É do paradigma declarativo: Descreve o que o programa faz e não o seu fluxo;
* É utilizado a hipótese de mundo fechado, ou seja, se não foi declarado, é considerado falso;


---

Ele utiliza fatos, regras e inferências:
* Fato: sentença aceita como verdadeira. 
> "Brasil é um país."
* Regra: declaração estabelecendo relações entre predicados. 
> "João é pai de Otávio e Otávio é pai de Pedro, então João é avô de Pedro."
* Inferência: pergunta feita ao sistema lógico para deduzir as informações com base nos fatos e regras. 
> "Brasil é um país? -> True."

---
### Funcionamento (será utilizado "->" como consulta recursiva)

Usuário -> Interface -> Motor de Inferência -> Base de Conhecimento

---

### Sintaxe

* Fatos e regras são escritas em letra minúscula;
* Variáveis são escritas com letra maiúscula;
* É necessário o ponto final (.) no final da declaração;

--- 
### Tipos

* Átomos: é um único item de dados
