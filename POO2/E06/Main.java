package E06;

import java.lang.reflect.Method;
import java.net.URL;
import java.net.URLClassLoader;

public class Main {
    public static void main(String[] args) {
        
        try {
            URLClassLoader classLoader = URLClassLoader.newInstance(new URL[]{new URL("file:./a.jar")});
            Class<?> classe = Class.forName("Classe", true, classLoader);

            // Criando uma instância da classe Exemplo
            Object instancia = classe.getDeclaredConstructor(int.class, int.class).newInstance(1, 2);

            // Acessando atributos
            Method getAtributo1 = classe.getDeclaredMethod("var1");
            Method getAtributo2 = classe.getDeclaredMethod("var2");
            int var1 = (int) getAtributo1.invoke(instancia);
            int var2 = (int) getAtributo2.invoke(instancia);

            System.out.println("Atributo1: " + var1);
            System.out.println("Atributo2: " + var2);

            // Chamando o método
            Method metodo = classe.getDeclaredMethod("metodo");
            metodo.invoke(instancia);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
