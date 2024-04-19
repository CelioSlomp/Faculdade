public class CalculadoraCientifica extends Calculadora {
    public double potencia(double num1, int pot) {
        if (pot == 0) {
            return 1;
        }
        double tmp = num1;
        while (pot > 1) {
            num1 = this.multiplicar(num1, tmp);
            pot--;
        }

        return num1;
    }
}
