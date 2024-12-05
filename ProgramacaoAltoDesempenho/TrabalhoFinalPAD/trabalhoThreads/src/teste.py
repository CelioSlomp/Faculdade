import threading as th

class Teste():
    x = 2
    y = 5
    def salve(self, z):
        return z*self.x*self.y
    
x = Teste()

saida = th.Thread(target=x.salve, args=(5,))
a = saida.start()
saida.join()

print(a)