from classes import *

for p in db.session.query(Pessoa).all():
    print(p.nome)