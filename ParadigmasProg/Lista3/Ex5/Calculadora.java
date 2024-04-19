public class Calculadora {
    public double somar(double num1, double num2) {
        return num1 + num2;
    }

    public double subtrair(double minuendo, double subtraendo) {
        return minuendo - subtraendo;
    }

    public double dividir(double dividendo, double divisor) {
        if (divisor == 0) {
            return 0; // Divisao por 0 :/
        }

        return dividendo / divisor;
    }

    public double multiplicar(double num1, double num2) {
        return num1 * num2;
    }
}
