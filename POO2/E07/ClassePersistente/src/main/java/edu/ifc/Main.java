package edu.ifc;

import lombok.extern.log4j.Log4j2;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;

@Log4j2
public class Main {
    public static void main(String[] args) {
        Configuration configuration = new Configuration().configure();
        SessionFactory sessionFactory = configuration.buildSessionFactory();

        Usuario usuario = new Usuario();
        usuario.setNome("Zé Ninguém");
        usuario.setNomeUsuario("zenin");
        usuario.setSenha("senha");
        usuario.setEmail("zenin@teste.com");

        Session session = sessionFactory.openSession();
        Transaction transaction = session.beginTransaction();

        session.save(usuario);

        transaction.commit();
        session.close();

        log.info("Usuário inserido com sucesso");
    }
}