package E06;

public class Classe {
    int var1;
    int var2;

    Classe(int v1, int v2){
        var1 = v1;
        var2 = v2;
    }

    void chamar(){
        System.out.println("A soma de v1 e v2 é: " + (var1+var2));
    }
}