from Grafos import Grafo, Vertice, Aresta

def buscaProfundidade():
    pass

def buscaLargura(grafo: Grafo, vertIn: Vertice):
    for v in grafo.vertices:
        v.estado = "NV"
        v.predec = None
        v.dist = -1

    vertIn.dist = 0
    vertIn.estado = "V"
    f = []
    f.append(vertIn)
    while len(f) != 0:
        pass

def criarGrafo(nome):
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
        vert[i.nome] = i

    grafo.adicionarAresta('a1', vert['a'], vert['b'])
    grafo.adicionarAresta('a2', vert['c'], vert['b'])
    grafo.adicionarAresta('a3', vert['c'], vert['d'])
    grafo.adicionarAresta('a4', vert['e'], vert['d'])
    grafo.adicionarAresta('a5', vert['e'], vert['c'])
    grafo.adicionarAresta('a6', vert['c'], vert['f'])
    grafo.adicionarAresta('a7', vert['f'], vert['e'])
    grafo.adicionarAresta('a8', vert['f'], vert['g'])

    grafo.adicionarAresta('a9', vert['i'], vert['j'])
    grafo.adicionarAresta('a10', vert['i'], vert['k'])
    grafo.adicionarAresta('a11', vert['i'], vert['h'])
    

    return grafo

def main():
    grafo = criarGrafo("g1")

    verti = {}
    arest = {}

    for i in grafo.vertices:
        verti[i.nome] = i
    for i in grafo.arestas:
        arest[i.nome] = i

    


if __name__ == "__main__":
    main()