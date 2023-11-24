class Grafo:
    def __init__(self, nome):
        self.nome = nome
        self.vertices = {}
        self.arestas = {}

    def adicionarVertice(self, nome):
        if nome in self.vertices:
            return False
        tmp = Vertice(nome)
        self.vertices[nome] = tmp
        return tmp
    
    def acharVertice(self, nome):
        if nome in self.vertices:
            return self.vertices[nome]
        return False
    
    def adicionarAresta(self,nome, v1, v2):
        if nome in self.arestas:
            return False
        tmp = Aresta(nome, v1, v2)
        self.arestas[nome] = tmp
        return tmp

    def getOrdem(self):
        return len(self.vertices)
    
    def getTamanho(self):
        return len(self.arestas)
    
    def getVertices(self):
        return self.vertices
    
    def getArestas(self):
        return self.arestas
    
    def removeAresta(self, nome):
        if nome in self.arestas:
            tmp = self.arestas[nome]
            if tmp.v1 == tmp.v2:
                tmp.v1.arestas.pop(nome)
            else:
                tmp.v1.arestas.pop(nome)
                tmp.v2.arestas.pop(nome)
            self.arestas.pop(nome)
    
    def removeVertice(self, nome):
        nomeArestas = []
        if nome not in self.vertices:
            return False
        tmp = self.vertices[nome]
        x = []
        for i in tmp.arestas:
            x.append(i)

        for i in x:
            self.removeAresta(i)
        self.vertices.pop(nome)        
        return True

    def getA(self, v1, v2):
        for i in self.arestas:
            # d é um objeto aresta
            d = self.arestas[i]
            if (d.v1 == v1 and d.v2 == v2) or \
               (d.v1 == v2 and d.v2 == v1):
                return d
        return None

    def verticesA(self, nome):
        if nome in self.arestas:
            aresta = self.arestas[nome]
            return (aresta.v1, aresta.v2)
        return None

    def oposto(self, nomVert, nomArest):
        if nomVert in self.vertices:
            vert = self.vertices[nomVert]

        if nomArest in self.arestas:
            ares = self.arestas[nomArest]
        if ares.v1 == vert:
            return ares.v2
        return ares.v1


class Vertice:
    def __init__(self, nome):
        self.nome = nome
        self.arestas = {}
        self.estado = ""
        self.predec = None
        self.dist = -1
        self.tempoAbertura = 0
        self.tempoFechamento = 0

    def adj(self):
        verts = []

        for i in self.arestas:
            i = self.arestas[i]
            if i.v1 == self:
                verts.append(i.v2)
            else:
                verts.append(i.v1)
        return verts

    def grau(self):
        grau = 0
        for i in self.arestas:
            i = self.arestas[i]
            if (i.v1 == self and i.v2 == self):
                grau += 2
            else:
                grau += 1
        return grau


class Aresta:
    def __init__(self, nome, v1: Vertice, v2: Vertice):
        self.v1 = v1
        self.v2 = v2
        self.nome = nome
        self.vertices = (v1, v2)
        if v1!=v2:
            v1.arestas[nome] = self
            v2.arestas[nome] = self
        else:
            v1.arestas[nome] = self


def main():
    grafo = Grafo("g1")
    v1 = grafo.adicionarVertice("v1")
    v2 = grafo.adicionarVertice("v2")
    v3 = grafo.adicionarVertice("v3")
    
    a1 = grafo.adicionarAresta("a1", v1, v2)
    a2 = grafo.adicionarAresta("a2", v2, v3)

    # grafo.removeVertice('v2')
    # print(v1.arestas)

    print(v2.grau())

if __name__ == "__main__":
    main()