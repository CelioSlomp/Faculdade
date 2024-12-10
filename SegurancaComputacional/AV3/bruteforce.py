import time

numeros = "0123456789"

inicio="561"

def quebra(inicio):
    for a in numeros:
        for b in numeros:
            for c in numeros:
                for d in numeros:
                    for e in numeros:
                        print(a+b+c+d+e)
                        if inicio+a+b+c+d+e == "56132470":
                            return
tempo = time.time()               
quebra(inicio)
print(time.time()-tempo)