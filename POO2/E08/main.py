from classes import *

'''
PRECISA TERMINAR
PRECISA TERMINAR
PRECISA TERMINAR
PRECISA TERMINAR
PRECISA TERMINAR
PRECISA TERMINAR
PRECISA TERMINAR
PRECISA TERMINAR
'''

def main():
    if os.path.exists(arquivobd):
        os.remove(arquivobd)

    db.create_all()

    p1 = Construtor(nome="Pablo", dataNas="123", altura=1, peso=60, areaTrab="montador", confiab="Muita", empresa="Honda")
    p1.seApresentar()
    #carro = p1.construirCarro("Civic", 2014, 200)
    #carro.construtor_id = p1.id

    db.session.add(p1)
    #db.session.add(carro)
    db.session.commit()

    for p in db.session.query(Pessoa).all():
        print(p.nome)


if __name__ == '__main__':
    main()