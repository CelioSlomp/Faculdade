from Grafos import Grafo, Vertice, Aresta

class OperacoesGrafo:
    def __init__(self, grafo: Grafo):
        self.grafo = grafo
        self.nome = grafo.nome

    def buscaProfundidade(self, vertIn: str):
        if not vertIn in self.grafo.vertices:
            return None
        vertIn = self.grafo.vertices[vertIn]
        for v in self.grafo.vertices:
            self.grafo.vertices[v].estado = "NV"
            self.grafo.vertices[v].predec = None
        
        tempo = 0
        self.visitaVertice(vertIn, tempo)

    def visitaVertice(self, vertIn: Vertice, tempo: int):
        vertIn.estado = "V"
        tempo = tempo + 1
        vertIn.tempoAbertura = tempo
        for i in vertIn.adj():
            if i.estado == "NV":
                i.predec = vertIn
                tempo = self.visitaVertice(i, tempo)
        vertIn.estado = "E"
        tempo = tempo + 1
        vertIn.tempoFechamento = tempo
        print(vertIn.nome, vertIn.tempoAbertura, vertIn.tempoFechamento)
        return tempo

    def buscaLargura(self, vertIn: str):
        if not vertIn in self.grafo.vertices:
            return None
        vertIn = self.grafo.vertices[vertIn]
        for v in self.grafo.vertices:
            self.grafo.vertices[v].estado = "NV"
            self.grafo.vertices[v].predec = None
            self.grafo.vertices[v].dist = 0

        vertIn.dist = 0
        vertIn.estado = "V"
        f = []
        f.append(vertIn)
        while len(f) != 0:
            adjacentes = f[0].adj()
            for i in adjacentes:
                if i.estado == "NV":
                    f.append(i)
                    i.estado = "V"
                    i.predec = f[0]
                    i.dist = f[0].dist + 1
            f[0].estado = "E"
            f.remove(f[0])

    def conexidade(self):
        for v in self.grafo.vertices:
            self.grafo.vertices[v].estado = "NV"
            self.grafo.vertices[v].predec = None

        tempo = 0
        Ncc = 0

        for v in self.grafo.vertices:
            v = self.grafo.vertices[v]
            if v.estado == "NV":
                Ncc += 1
                tempo += self.visitaVertice(v, tempo)
        
        if Ncc > 1:
            print("O grafo não é conexo.")
        else:
            print("Grafo conexo")


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
    # Instancia um grafo e um objeto
    # para poder operar esse grafo.
    grafo = criarGrafo("g1")
    opgrafo = OperacoesGrafo(grafo)
    
    # Busca em largura
    # opgrafo.buscaLargura('h')
    
    # Busca em profundidade
    # opgrafo.buscaProfundidade('a')
    
    # Testa a conexidade do grafo
    # opgrafo.conexidade()

if __name__ == "__main__":
    main()