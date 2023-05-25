from Pessoa import Pessoa

class Jogador(Pessoa):
    def __init__(self, nome, dataNas, altura, equipe, posicao):
        super().__init__(nome, dataNas, altura)
        self.equipe = equipe
        self.posicao = posicao

    def trocarEquipe(self, equipe):
        self.equipe = equipe

    def seApresentar(self):
        print(f"Salve, sou {self.nome}, jogo pela {self.equipe} e tenho {self.altura} cm de altura")