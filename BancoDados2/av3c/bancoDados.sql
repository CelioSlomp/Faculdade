/*
 * Ao INSERIR um registro, verificar se o IDENTIFICADOR já existe 
 * (por exemplo, CPF; se já existir, adicionar novamente o registro 
 * usando (v+1), tal que v é a última versão existente do dado
 * OK ^^^^^^^^^^^^^^^^^^^

Ao MODIFICAR um registro, inserir novamente o registro novo com (v+1)

Ao EXCLUIR um registro, apagar todas as ocorrências com o IDENTIFICADOR.
 * */

-- tabela aluno versionado
CREATE TABLE Aluno_versionado(
	matricula integer,
	cpf integer,
	nome varchar(255),
	dataNasci date,
	email varchar(255),
	numContato varchar(255),
	versao integer
);

-- Cria a view de aluno, que pega a ultima versao de Aluno_versionado
CREATE VIEW Aluno AS SELECT * FROM Aluno_versionado av WHERE (av.versao, av.cpf) IN (SELECT max(av2.versao) AS v, av2.cpf FROM Aluno_versionado av2 GROUP BY cpf);

-- Da select na view Aluno ou na tabela Aluno_versionado
select * from Aluno;
select * from Aluno_versionado av;
DELETE from Aluno_versionado where numContato='a';

-- Cria o trigger do insert
CREATE trigger insereAluno before insert on Aluno_versionado
for each row
BEGIN 
set new.versao = (select a.versao from Aluno a where a.matricula=new.matricula) + 1;
end;

-- Cria o trigger do update
-- Não consegui até agora :(
create trigger updateAluno before update on Aluno_versionado
for each ROW 
BEGIN 
	insert into Aluno_versionado (matricula, cpf, nome, dataNasci, email, numContato)
	values (new.matricula, new.cpf, new.nome, new.dataNasci, new.email, new.numContato);
END;
UPDATE Aluno_versionado set numContato='bla' where numContato = 'a';



-- Cria o trigger do delete
-- Não consegui até agora :(
create trigger deleteAluno after delete on Aluno_versionado
for each row
begin
	CALL deleteAlunos(old.matricula); 
end;



drop trigger deleteAluno;




