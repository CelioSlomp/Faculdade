import java.util.Scanner;

public class TesteMaquina {

    public static void main(String[] args) {
        Maquina maquina = new Maquina(0);

        java.util.Scanner input = new Scanner(System.in);

        int x = 1;
        int qtdBolinhas = 0;
        loop1: while (x != 0) {
            imprimeTabela();
            System.out.print("Digite aqui a opção que deseja: ");
            x = input.nextInt();
            switch (x) {
                case 0:
                    break loop1;

                case 1:
                    maquina.inserirMoeda();
                    break;

                case 2:
                    maquina.ejetarMoeda();
                    break;

                case 3:
                    maquina.virarManivela();
                    break;

                case 4:
                    System.out.print("Digite a quantidade de bolinhas que irá colocar: ");
                    qtdBolinhas = input.nextInt();
                    maquina.encher(qtdBolinhas);
                    System.out.println("Bolinhas colocadas com sucesso.");
                    break;

                default:
                    break;
            }
        }

    }

    public static void imprimeTabela() {
        System.out.println("---------------------------------------");
        System.out.println("Opções:");
        System.out.println("1 - Inserir moeda.");
        System.out.println("2 - Ejetar moeda.");
        System.out.println("3 - Virar a manivela.");
        System.out.println("4 - Encher Maquina.");
        System.out.println("0 - Sair.");
    }
}