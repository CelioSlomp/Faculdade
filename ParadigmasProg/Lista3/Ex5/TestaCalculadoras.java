public class TestaCalculadoras {
    public static void main(String[] args) {
        Calculadora cal = new Calculadora();
        CalculadoraCientifica calcie = new CalculadoraCientifica();

        System.out.println(cal.somar(1, 2));
        System.out.println(cal.dividir(5, 2));
        System.out.println(cal.dividir(8, 0)); // div por 0
        System.out.println(cal.subtrair(5, 8));
        System.out.println(cal.multiplicar(4, 5));

        System.out.println(calcie.potencia(5, 0));
    }
}
