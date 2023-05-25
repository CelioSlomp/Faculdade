from Jogador import Jogador

class Equipe:
    def __init__(self, nome, dataFund, j):
        self.nome = nome
        self.dataFund = dataFund;
        self.jogadores = j

    def trocarJ1(self, jogador):
        self.jogadores[0] = jogador
    
    def trocarJ2(self, jogador):
        self.jogadores[1] = jogador

    def mostrarJog(self):
        a = 0
        for i in self.jogadores:
            a+=1
            print(f"Jogador {a}: {i.nome}, posicao: {i.posicao}")