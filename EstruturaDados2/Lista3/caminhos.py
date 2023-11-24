from Grafos import Grafo, Vertice, Aresta

class OperacoesGrafo:
    def __init__(self, grafo: Grafo):
        self.grafo = grafo
        self.nome = grafo.nome

    def algorDijkstra(self, vertIn: Vertice, vertFinal: Vertice):
        q = []
        for i in self.grafo.vertices:
            i = self.grafo.vertices[i]
            q.append(i)
            i.dist = 2**32
            i.predec = None
        vertIn.dist = 0
        Excluid = []

        while len(q):
            for v in q[0].adj():
                if v in q and (v.dist > (q[0].dist + self.grafo.getA(q[0], v).custo)):
                    v.predec = q[0]
                    v.dist = q[0].dist + self.grafo.getA(q[0], v).custo
            Excluid.append(q[0])
            q.remove(q[0])
        
        if input(f"Deseja imprimir o caminho de cada vertice até {vertIn.nome}? (S/N)").lower()=="s":
            for i in Excluid:
                print(f"O Vertice {i.nome} tem distância de {i.dist} de {vertIn.nome}")
        
        print(f"o caminho de {vertIn.nome} até {vertFinal.nome} é {vertFinal.dist}.")

    def criarMatrizCusto(self):
        listaVert = []
        for i in self.grafo.getVertices():
            i = self.grafo.vertices[i]
            listaVert.append(i)
        matriz = []
        for i in range(0, len(listaVert)):
            matriz.append([])
        contador = 0
        for i in listaVert:
            for j in listaVert:
                are = self.grafo.getA(i,j)
                if i==j:
                    matriz[contador].append(0)
                elif are==None:
                    matriz[contador].append(None)
                else:
                    matriz[contador].append(are.custo)
            print(matriz[contador])
            contador += 1

    def bubbleSort(self, lista:list, Vi : Vertice):
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
                    lista[iInd], lista[jInd] = lista[jInd], lista[iInd]

                jInd += 1
            iInd += 1

        for i in lista:
            listaPronta.append(i)

        return listaPronta

    def algoritmoPrim(self, vertIn: Vertice):
        vertices = []
        vertices.append(vertIn)
        for i in self.grafo.getVertices():
            i = self.grafo.vertices[i]
            i.predec = None
            i.dist = 2**32
            if i!= vertIn:
                vertices.append(i)

        vertIn.dist = 0
        while len(vertices) != 0:
            vertices = self.bubbleSort(vertices, vertIn)
            u = vertices[0]
            for i in u.adj():
                if (i in vertices) and (self.grafo.getA(u,i).custo < i.dist):
                    i.predec = u
                    i.dist = self.grafo.getA(u,i).custo + u.dist
            
            ## Arrumar valores maiores de 2**32
            vertices.remove(u)


        for i in self.grafo.vertices:
            i = self.grafo.vertices[i]
            print(f"Vertice '{i.nome}' e distancia: '{i.dist}'")
            if i.predec != None:
                print(i.predec.nome)

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

    a = grafo.acharVertice("a")
    g = grafo.acharVertice("g")

    # opgrafo.algorDijkstra(a, g)
    # opgrafo.criarMatrizCusto()
    opgrafo.algoritmoPrim(a)

if __name__ == "__main__":
    main()