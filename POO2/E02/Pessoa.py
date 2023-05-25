class Pessoa:
    def __init__(self, nome, dataNas, altura):
        self.nome = nome
        self.dataNas = dataNas
        self.altura = altura

    def falar(self, mensagem):
        print(f"{self.nome} disse: '{mensagem}'")