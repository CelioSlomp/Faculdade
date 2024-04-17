public class ComCredito implements State {
    Maquina maquina;

    public ComCredito(Maquina maquina) {
        this.maquina = maquina;
    }

    public void inserirMoeda() {
        System.out.println("Já possui moeda, não pode inserir outra.");
    }

    public void ejetarMoeda() {
        System.out.println("Moeda devolvida");
        maquina.setState(maquina.getSemCredito());
    }

    public void virarManivela() {
        System.out.println("Manivela virada.");
        maquina.setState(maquina.getVendido());
    }

    public void entregar() {
        System.out.println("Não foi possível entregar a bola, vire a manivela.");
    }

}