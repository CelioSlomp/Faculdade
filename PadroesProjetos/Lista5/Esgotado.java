public class Esgotado implements State {
    Maquina maquina;

    public Esgotado(Maquina maquina) {
        this.maquina = maquina;
    }

    public void inserirMoeda() {
        System.out.println("Maquina esgotada.");
    }

    public void ejetarMoeda() {
        System.out.println("Nenhuma moeda foi inserida.");
    }

    public void virarManivela() {
        System.out.println("Maquina esgotada.");
    }

    public void entregar() {
        System.out.println("Nenhuma bolinha foi entregue.");
    }
}