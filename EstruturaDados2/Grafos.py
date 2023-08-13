class Grafo:
    def __init__(self):
        self.vertices = []
        self.arestas = []

    def adicionarVertice(self, nome):
        for i in self.vertices:
            if i.nome == nome:
                return "Ja existe esse nome"
        self.vertices.append(Vertice(nome))
        return "Adicionado com sucesso"
    
    def acharVertice(self, nome):
        for i in self.vertices:
            if i.nome == nome:
                return i
        return "Vertice nao encontrado"
    
    def adicionarAresta(self,nome, v1, v2):
        self.arestas.append(Aresta(nome, v1, v2))

    def getOrdem(self):
        return len(self.vertices)
    
    def getTamanho(self):
        return len(self.arestas)
    
    def getVertices(self):
        return self.vertices
    
    def getArestas(self):
        return self.arestas
    
    def removeAresta(self, nome):
        for i in self.arestas:
            if i.nome == nome:
                self.arestas.remove(i)
                return "Aresta removida"
        return "Aresta não encontrada"
    
    def removeVertice(self, nome):
        nomeArestas = []
        
        for i in self.vertices:
            if i.nome == nome:
                vertice = i
                for j in i.arestas:
                    nomeArestas.append(j.nome)
        for i in nomeArestas:
            self.removeAresta(i)
        self.vertices.remove(vertice)




class Vertice:
    def __init__(self, nome):
        self.nome = nome
        self.arestas = []


class Aresta:
    def __init__(self, nome, v1: Vertice, v2: Vertice):
        self.nome = nome
        self.vertices = (v1, v2)
        v1.arestas.append(self)
        v2.arestas.append(self)


def main():
    grafo = Grafo()
    grafo.adicionarVertice("v1")
    grafo.adicionarVertice("v2")
    v1 = grafo.vertices[0]
    v2 = grafo.vertices[1]
    grafo.adicionarAresta("a1", v1, v2)
    grafo.adicionarAresta("a2", v1, v2)
    print(len(grafo.arestas))
    grafo.removeVertice("v1")
    print(len(grafo.arestas))

if __name__ == "__main__":
    main()