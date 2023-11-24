from Grafos import Grafo, Vertice, Aresta

class OperacoesGrafo:
    def __init__(self, grafo: Grafo):
        self.grafo = grafo
        self.nome = grafo.nome

    def algorDijkstra(self, vertIn: Vertice):
        # Cria uma lista vazia para adicionar todos os vertuces
        # e é atribuido o valor infinito para todos os vertices do grafo.
        q = []
        for i in self.grafo.vertices:
            i = self.grafo.vertices[i]
            q.append(i)
            i.dist = 2**32
            i.predec = None
        vertIn.dist = 0
        Excluid = []
        # Enquanto a lista q ainda tiver itens:
        while len(q):
            # os adjacentes do primeiro item da fila
            for v in q[0].adj():
                if v in q and (v.dist > (q[0].dist + self.grafo.getA(q[0], v).custo)):
                    v.predec = q[0]
                    v.dist = q[0].dist + self.grafo.getA(q[0], v).custo
            Excluid.append(q[0])
            q.remove(q[0])

    def criarMatrizCusto(self):
        listaVert = []
        # adiciona todos os vertices na lista de vertices
        for i in self.grafo.getVertices():
            i = self.grafo.vertices[i]
            listaVert.append(i)
        matriz = []
        # adiciona o total de linhas na matriz
        for i in range(0, len(listaVert)):
            matriz.append([])
        # contador para saber qual linha da matriz
        contador = 0
        for i in listaVert:
            for j in listaVert:
                are = self.grafo.getA(i,j)
                # se i for j, coloca 0, ja que a distancia é 0
                if i==j:
                    matriz[contador].append(0)
                # caso não exista aresta entre os dois vertices
                elif are==None:
                    matriz[contador].append(None)
                else:
                    matriz[contador].append(are.custo)
            # imprime a matriz
            print(matriz[contador])
            contador += 1
        return matriz

    def filaPrioridade(self, lista:list, Vi : Vertice):
        # Vi é o vertice inicial dado pelo usuario
        if Vi in lista:
            listaPronta = [Vi]
            lista.remove(Vi)
        else:
            listaPronta = []
        iInd = 0
        for i in lista:
            jInd = 0
            for j in lista:
                if i.dist < j.dist:
                    # da swap nos dois itens
                    lista[iInd], lista[jInd] = lista[jInd], lista[iInd]

                jInd += 1
            iInd += 1

        # Junta tudo na lista final
        for i in lista:
            listaPronta.append(i)

        return listaPronta

    def algoritmoPrim(self, vertIn: Vertice):
        # Cria uma lista vazia com todos os vertices
        vertices = []
        vertices.append(vertIn)
        for i in self.grafo.getVertices():
            i = self.grafo.vertices[i]
            # Coloca valor nulo para os predecessores e 
            # valor infinito para as distancias
            i.predec = None
            i.dist = 2**32
            if i!= vertIn:
                vertices.append(i)

        # distancia 0 para o vertice inicial
        vertIn.dist = 0
        while len(vertices):
            # Metodo filaPrioridade, que é um bubblesort
            # para as menores distancias de vertices
            vertices = self.filaPrioridade(vertices, vertIn)
            # Primeiro da lista
            u = vertices[0]
            # caso a distancia de u ainda seja infinito, será
            # atribuído valor 'Não conexo'
            if u.dist == 2**32:
                u.dist = "Não conexo"
            else:
                # pega todos os adjacentes do primeiro vertice
                # da lista de prioridades
                for i in u.adj():
                    # caso o custo da aresta seja menor que a distancia,
                    # pega ela e a salva, somando com as distâncias ja
                    # percorridas
                    if (i in vertices) and (self.grafo.getA(u,i).custo < i.dist):
                        i.predec = u
                        i.dist = self.grafo.getA(u,i).custo + u.dist
            # Remove da fila de prioridade
            vertices.remove(u)

    def imprimeCaminhos(self):
        lista = []
        listaExc = []
        for i in self.grafo.vertices:
            i = self.grafo.vertices[i]
            if i.dist != 2**32:
                lista.append(i)
            else:
                listaExc.append(i)

        for i in lista:
            print(f"Distancia de {i.nome}: {i.dist}")
            if i.predec != None or i.dist == 0:
                # cria uma linha de caminho até o vertice inicial
                while i.dist:
                    print(f"'{i.nome}'", end=f" - {self.grafo.getA(i, i.predec).custo} > ")
                    i = i.predec
                print(f"'{i.nome}'")

        for i in listaExc:
            print(f"O vertice '{i.nome}' não é conexo.")


def criarGrafo(nome):

    '''
    Funcao criada para criar um grafo
    '''

    grafo = Grafo(nome)
    grafo.adicionarVertice("a")
    grafo.adicionarVertice("b")
    grafo.adicionarVertice("c")
    grafo.adicionarVertice("d")
    grafo.adicionarVertice("e")
    grafo.adicionarVertice("f")
    grafo.adicionarVertice("g")
    grafo.adicionarVertice("h")
    grafo.adicionarVertice("i")
    grafo.adicionarVertice("j")
    grafo.adicionarVertice("k")

    vert = {}

    for i in grafo.vertices:
        vert[i] = grafo.vertices[i]

    grafo.adicionarAresta('a1', vert['a'], vert['b'], 5)
    grafo.adicionarAresta('a2', vert['c'], vert['b'], 7)
    grafo.adicionarAresta('a3', vert['c'], vert['d'], 20)
    grafo.adicionarAresta('a4', vert['e'], vert['d'], 2)
    grafo.adicionarAresta('a5', vert['e'], vert['c'], 8)
    grafo.adicionarAresta('a6', vert['c'], vert['f'], 20)
    grafo.adicionarAresta('a7', vert['f'], vert['e'], 10)
    grafo.adicionarAresta('a8', vert['f'], vert['g'], 5)

    grafo.adicionarAresta('a9', vert['i'], vert['j'], 10)
    grafo.adicionarAresta('a10', vert['i'], vert['k'], 10)
    grafo.adicionarAresta('a11', vert['i'], vert['h'], 10)
    
    return grafo

def main():
    # Instancia um grafo e um objeto
    # para poder operar esse grafo.
    grafo = criarGrafo("g1")
    opgrafo = OperacoesGrafo(grafo)

    # Pega os vertices a (apenas troque o nome do vertice, vai de 'a' até 'k')
    a = grafo.acharVertice("a")

    # chama o algoritmo de Dijkstra (tirar o comentario da linha abaixo)
    # opgrafo.algorDijkstra(a)

    # Chama o algoritmo de Prim (tirar o comentario da linha abaixo)
    # opgrafo.algoritmoPrim(a)
    
    # Cria uma matriz de custo
    # opgrafo.criarMatrizCusto()

    # Executará os caminhos possíveis
    x = input("Deseja imprimir os caminhos do ultimo algoritmo executado? (S/N)")
    if x.lower() == "s" or x == "":
        opgrafo.imprimeCaminhos()

if __name__ == "__main__":
    main()