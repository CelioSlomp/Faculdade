SELECT * FROM actor a WHERE a.actor_id  in (SELECT actor_id from film_actor fa WHERE actor_id = 188);
-- Seleciona tudo de actor quando o film_actor possuir o id do ator num 188

SELECT * FROM actor a WHERE a.actor_id in (SELECT actor_id from film_actor fa WHERE a.first_name = 'ROCK');
-- Seleciona tudo de ator quando o actor_id estiver dentro de film_actor e o primeiro nome de actor for ROCK

SELECT * from actor a WHERE EXISTS (SELECT actor_id FROM film_actor fa WHERE a.actor_id = 188)
-- Seleciona tudo de actor quando existir o actor_id igual a 188 de film_actor

SELECT COUNT(DISTINCT a.first_name) as 'nomes diferentes' from actor a
-- Conta a quantidade de nomes distintos de actor

SELECT * from actor a natural join film_actor fa 
-- Não está funcionando

SELECT DISTINCT first_name FROM actor a left join film_actor fa on a.actor_id = fa.actor_id 
-- Seleciona todos os atores que fizeram algum filme

SELECT MAX(a.actor_id) from actor a
-- Seleciona o maior valor dos ids de actor

SELECT a.first_name, MAX(a.actor_id) from actor a group by a.first_name
-- Seleciona todos os nomes com o maior id






