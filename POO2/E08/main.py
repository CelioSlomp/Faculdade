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

    # Adicionar
    p1 = Mecanico(nome="Pablo", dataNas=date(2000,10,10), altura=1, peso=60, areaTrab="montador", confiab="Muita", empresa="Honda")
    db.session.add(p1)
    p2 = Mecanico(nome="Everton", dataNas=date(2000,10,10), altura=1, peso=60, areaTrab="montador", confiab="Pouca", empresa="Honda")
    db.session.add(p2)
    
    # Adicionar
    carro = p1.construirCarro("Civic", 2014, 200)
    carro.construtor_id = p1.id
    db.session.add(carro)

    # Consultar 
    for p in db.session.query(Pessoa).all():
        print(p.nome)

    # Alterar
    for p in db.session.query(Pessoa).filter(Pessoa.id == 2).all():
        p.nome = "Joel"

    for p in db.session.query(Pessoa).all():
        print(p.nome)

    # Excluir
    db.session.query(Pessoa).filter(Pessoa.id == 1).delete()

    db.session.commit()

if __name__ == '__main__':
    main()