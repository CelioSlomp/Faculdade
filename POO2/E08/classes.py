from config import *

class Pessoa(db.Model):
    __tablename__ = 'pessoa'
    id = db.Column(db.Integer, primary_key=True)
    nome = db.Column(db.String(254))
    dataNas = db.Column(db.Date)
    altura = db.Column(db.Integer)
    peso = db.Column(db.Integer)
    type = db.Column(db.String(50))
    __mapper_args__ = {'polymorphic_identity':'pessoa',
                       'polymorphic_on':type}

    def seApresentar(self):
        print(f"Olá, sou {self.nome} e nasci em {self.dataNas}.")


class Mecanico(Pessoa):
    __mapper_args__ = {'polymorphic_identity':'mecanico'}
    areaTrab = db.Column(db.String(254))
    confiab = db.Column(db.String(254))
    empresa = db.Column(db.String(254))

    def construirCarro(self, nomeC, anoC, velmaxC):
        return Carro(nome=nomeC, ano=anoC, velMax=velmaxC, marca=self.empresa, mecanico=self)


class Carro(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    nome = db.Column(db.String(254))
    ano = db.Column(db.Integer)
    velMax = db.Column(db.Integer)
    marca = db.Column(db.String(254))
    mecanico_id = db.Column(db.Integer, db.ForeignKey(Mecanico.id), nullable=False)
    mecanico = db.relationship("Mecanico")
    type = db.Column(db.String(50))
    __mapper_args__ = {'polymorphic_identity':'carro',
                       'polymorphic_on':type}
    
    def ano(self):
        print(f"Carro de {self.ano}.")

