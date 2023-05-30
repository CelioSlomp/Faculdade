import com.somar.Soma;
import java.lang.reflect.*;

public class MainClass {

    public static void main(String[] args) {
        
        Soma s = new Soma(1,2);
        System.out.println("O a soma é: " + s.soma());
        System.out.println("O a soma de 10+10 é: " + s.somar2(10,10));
        
        Class<?> objeto = s.getClass();
        
        // Pegar nome da classe desse objeto
        System.out.println("Nome: " + objeto.getName());
        
        Method[] metodos = objeto.getDeclaredMethods();
        System.out.println("Métodos de " + objeto.getName());
        System.out.print(" - ");
        for(Method i : metodos){
            System.out.print(i.getName());
            System.out.print(" - ");
        }
    }
}
