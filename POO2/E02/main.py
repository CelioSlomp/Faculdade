from Pessoa import Pessoa
from Jogador import Jogador
from Equipe import Equipe

def main():
    j1 = Jogador("Joao", "12/12/12", 123, "Flamengo", "goleiro")
    j2 = Jogador("Pablo", "11/11/11", 123, "Flamengo", "goleiro")

    eq = Equipe("Flamengo", "10/10/10", [j1,j2])

    j1.seApresentar()
    j2.seApresentar()

    eq.mostrarJog()
    j1.falar("O Pablo é muito ruim.")
    j2 = Jogador("Robson", "10/10/10", 132, "Flamengo", "goleiro")
    j2.seApresentar()

    eq.trocarJ2(j2)
    eq.mostrarJog()

    print("")
    print("")
    metodos = [a for a in dir(Jogador) if callable(getattr(Jogador, a)) and not a.startswith("__")]
    print(f"Metodos: {str(Jogador)}:\n{metodos}")
    print("")
    metodos = [a for a in dir(Pessoa) if callable(getattr(Pessoa, a)) and not a.startswith("__")]
    print(f"Metodos: {str(Pessoa)}:\n{metodos}")
    print("")
    metodos = [a for a in dir(Equipe) if callable(getattr(Equipe, a)) and not a.startswith("__")]
    print(f"Metodos: {str(Equipe)}:\n{metodos}")

if __name__ == "__main__":
    main()