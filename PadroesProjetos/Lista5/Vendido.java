import java.util.Random;

public class Vendido implements State {
    Maquina maquina;
    Random numAleatorio = new Random();

    public Vendido(Maquina maquina) {
        this.maquina = maquina;
    }

    public void inserirMoeda() {
        System.out.println("Espera até receber a bolinha.");
    }

    public void ejetarMoeda() {
        System.out.println("Manivela já foi virada, não se pode mais devolver a moeda.");
    }

    public void virarManivela() {
        System.out.println("Manivela já foi virada.");
    }

    public void entregar() {
        int x = numAleatorio.nextInt(10);
        if (maquina.getCount() > 0) {
            System.out.println("Soltando bolinha.");
            maquina.soltarBolinha();

            if (maquina.getCount() > 0) {
                if (x == 5) {
                    System.out.println("Parabéns, você ganhou uma bolinha extra.");
                    maquina.setState(maquina.getVencedor());
                } else {
                    maquina.setState(maquina.getSemCredito());
                }

            } else {
                maquina.setState(maquina.getEsgotado());
            }
        }
    }
}