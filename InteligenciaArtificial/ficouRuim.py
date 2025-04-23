'''
Criar um jogo de Sudoku usando restrições CSP

'''

def matrizTeste():
    jogo = []
    for i in range(0, 9):
        a = []
        for j in range(0, 9):
            a.append(j)
        jogo.append(a)
    return jogo

def desenhar(jogo: list):
    '''
    recebe uma matriz
    [
    [valores da linha 1],
    .
    .
    .
    [valores da linha 9]
    ]
    '''
    contador = 1
    print("   ", end="")
    for letra in "ABCDEFGHI":
        print(f" {letra} ", end="")
    print("")
    for linha in jogo:
        print(f" {contador} ", end="")
        for valor in linha:
            print(f" {valor} ", end="")
        print("")
        contador += 1

def comparaLinhasColunas(tabela):
    pass

def tabelaDominios(jogo: list):
    dominios = [[set(range(1,10)) for _ in range(0,9)] for _ in range(0,9) ]
    
    # Verificar das linhas
    for i in range(0,9):
        valoresTirarLinha = []
        for j in range(0,9):
            if jogo[i][j]:
                dominios[i][j] = {jogo[i][j]}
                valoresTirarLinha.append(jogo[i][j])
        for j in range(0,9):
            for valor in valoresTirarLinha:
                if dominios[i][j] != {jogo[i][j]}:
                    dominios[i][j].discard(valor)

    # Verificar colunas
    for j in range(0,9):
        valoresTirarLinha = []
        for i in range(0,9):
            if jogo[i][j]:
                dominios[i][j] = {jogo[i][j]}
                valoresTirarLinha.append(jogo[i][j])
        for i in range(0,9):
            for valor in valoresTirarLinha:
                if dominios[i][j] != {jogo[i][j]}:
                    dominios[i][j].discard(valor)

    # Verificar blocos
    for i in range(0,9,3):
        for j in range(0,9,3):
            valoresTirarBloco = []
            for bi in range(0,3):
                for bj in range(0,3):
                    if jogo[i + bi][j + bj]:
                        dominios[bi + i][bj + j] = {jogo[bi + i][bj + j]}
                        valoresTirarBloco.append(jogo[bi + i][bj + j])

            for bi in range(0,3):
                for bj in range(0,3):
                    for valor in valoresTirarBloco:
                        if dominios[i+ bi][bj + j] != {jogo[bi + i][bj + j]}:
                            dominios[i + bi][j + bj].discard(valor)

    return dominios
    #for i in dominios:
    #    for j in i:
    #        print(i, end="")
    #    print("")        

def allDiff(linha):
    if len(set(linha)) != 9:
        return False
    return True

def ac3(jogo: list):
    dominios = tabelaDominios(jogo)

    '''
    AC3 funciona com pares, ou seja, precisa ser adaptado o domínio para 
    conseguir usar o pseudocódigo de Russel.

    O pseudocódigo de Russel adota outra coisa:
    se A = [1,2] e B = [2], se A se tornar [2], então B não vai poder virar nada.
    O AC3 trata isso, enquanto que a minha função tabelaDominios nao.

    '''






def revisao(dominios, xi, xj):
    revisado = False


def backtrack():
    pass

def jogoAtualizado(tabela, jogo):

    for i in range(0,9):
        for j in range(0,9):
            if len(tabela[i][j]) == 1:
                jogo[i][j] = tabela[i][j].pop()
    
    return jogo

    

def main(jogo):

    jogo = jogoAtualizado(tabelaDominios(jogo), jogo)
    desenhar(jogo)
    jogo = jogoAtualizado(tabelaDominios(jogo), jogo)
    desenhar(jogo)
    jogo = jogoAtualizado(tabelaDominios(jogo), jogo)
    desenhar(jogo)
    jogo = jogoAtualizado(tabelaDominios(jogo), jogo)
    desenhar(jogo)

if __name__ == "__main__":
    
    sudoku = [
        [8, 1, 3, 9, 0, 5, 7, 0, 6],
        [0, 5, 0, 0, 0, 0, 0, 0, 0],
        [4, 7, 2, 3, 6, 1, 8, 0, 5],
        [6, 0, 4, 0, 1, 0, 5, 0, 0],
        [0, 9, 5, 0, 3, 8, 0, 2, 1],
        [0, 0, 0, 0, 0, 2, 0, 0, 0],
        [0, 3, 0, 0, 7, 4, 0, 0, 9],
        [5, 4, 0, 0, 8, 0, 1, 0, 3],
        [0, 6, 7, 5, 9, 0, 0, 0, 4]
    ]
    #tabelaDominios(sudoku)
    main(sudoku)