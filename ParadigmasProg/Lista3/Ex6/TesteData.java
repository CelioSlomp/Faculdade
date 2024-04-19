import java.util.Scanner;

public class TesteData {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int d, m, a;
        while (true) {
            System.out.print("Digite a data em formato DD MM AAAA: ");
            d = input.nextInt();
            m = input.nextInt();
            a = input.nextInt();

            Data data = new Data(d, m, a);
            data.printData();
            System.out.println("Proximo dia: ");
            data.proximoDia();
            data.printData();
        }

    }
}
