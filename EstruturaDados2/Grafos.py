'''
Funcoes para adicionar:

X   getOrdem
X   getTamanho
X   Vertices
X   Arestas
X   insereV
X   removeV(v)
X   insereA(u, v)
X   removeA(e)
X   adj(v)
X   getA(u, v)
X   grau(v)
X   verticesA(e)
X   oposto(v,e)

'''

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
        for i in self.arestas:
            if i.nome == nome:
                return "Ja existe essa aresta"
        self.arestas.append(Aresta(nome, v1, v2))
        return "Adicionado com sucesso"

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
                if i.v1 == i.v2:
                    v1 = i.v1
                    v1.arestas.remove(i)
                else:
                    v1 = i.v1
                    v2 = i.v2
                    v1.arestas.remove(i)
                    v2.arestas.remove(i)
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

    def getA(self, v1, v2):
        for i in self.arestas:
            if (i.v1 == v1 and i.v2 == v2) or \
               (i.v1 == v2 and i.v2 == v1):
                return i
        return None

    def verticesA(self, nome):
        for i in self.arestas:
            if i.nome == nome:
                return (i.v1, i.v2)
        return None

    def oposto(self, nomVert, nomArest):
        for i in self.arestas:
            if i.nome == nomArest:
                ares = i
        for i in self.vertices:
            if i.nome == nomVert:
                vert = i
        
        if ares.v1 == vert:
            return ares.v2
        return ares.v1


class Vertice:
    def __init__(self, nome):
        self.nome = nome
        self.arestas = []

    def adj(self):
        verts = []
        for i in self.arestas:
            if i.v1 == self:
                verts.append(i.v1)
            else:
                verts.append(i.v2)
        print("Vertices adjacentes a", self.nome)
        for i in verts:
            print(i.nome, end=" ")
        print("")
        return verts

    def grau(self):
        grau = 0
        print(self.arestas)
        for i in self.arestas:
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
            v1.arestas.append(self)
            v2.arestas.append(self)
        else:
            v1.arestas.append(self)


def main():
    grafo = Grafo()
    grafo.adicionarVertice("v1")
    grafo.adicionarVertice("v2")
    grafo.adicionarVertice("v3")
    
    v1 = grafo.vertices[0]
    v2 = grafo.vertices[1]
    v3 = grafo.vertices[2]

    grafo.adicionarAresta("a1", v2, v1)
    grafo.adicionarAresta("a2", v2, v3)
    print(len(v2.arestas))
    #grafo.removeVertice("v1")
    #grafo.removeAresta("a1")
    print(len(v2.arestas))

    print(v2.adj())

    #print(v3.grau())
    #print(grafo.verticesA("a2"))
    #print(v1)
    #print(grafo.oposto("v2", "a1"))

if __name__ == "__main__":
    main()