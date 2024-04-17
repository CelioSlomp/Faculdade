public class SemCredito implements State {
    Maquina maquina;

    public SemCredito(Maquina maquina) {
        this.maquina = maquina;
    }

    public void inserirMoeda() {
        System.out.println("Moeda inserida!");
        maquina.setState(maquina.getComCredito());
    }

    public void ejetarMoeda() {
        System.out.println("Nenhuma moeda foi inserida.");
    }

    public void virarManivela() {
        System.out.println("Virou a manivela, mas não tinha moeda.");
    }

    public void entregar() {
        System.out.println("Virou a manivela, mas não tinha moeda.");
    }
}