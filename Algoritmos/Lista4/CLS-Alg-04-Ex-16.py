from random import choice
media = 0
for i in range(0, 10):
    sorteios = 0
    pr = ""
    x = 0
    ultimo = ""
    while True:
        sorteio = choice(["O", "A"])
        if ultimo == "" or ultimo == sorteio:
            x += 1
        else:
            x = 1
        
        ultimo = sorteio
        pr += sorteio + " "
        sorteios += 1
        if x == 3:
            break
    print(pr + (str(sorteios) + " sorteios"))
    media += sorteios



print("Na média, foram necessários %.1f sorteios" % (media/10))
