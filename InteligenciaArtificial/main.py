'''
Gerar N dados de pontos (x_i, y_i) e ajustar um polinômio utilizando o método discutido no 
encontro anterior. Sugestão, comece com um N pequeno como, por exemplo, N = 3 e depois aumente. 
Faça o gráfico da função. Utilize um software como Octave, Matlab ou alguma linguagem como Julia ou Python.
'''

import random as r
import matplotlib.pyplot as mp
import numpy as np

def gerarPontos(numeroPontos):
    # considerar pontos de -10,10 (min. e max.)
    return [(r.randint(-10, 10), r.randint(-10, 10)) for i in range(0,numeroPontos)]

def desenharGrafico():
    pontos = gerarPontos(10)
    
    mp.plot(list(np.array(pontos[0])), list(np.array(pontos[1])), 'o')
    mp.show()

def main():
    desenharGrafico()

if __name__ == "__main__":
    main()