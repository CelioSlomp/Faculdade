public class Vencedor implements State {
    Maquina maquina;

    public Vencedor(Maquina maquina) {
        this.maquina = maquina;
    }

    public void inserirMoeda() {
        System.out.println("Não precisa inserir moeda.");
    }

    public void ejetarMoeda() {
        System.out.println("Não tem moeda para ejetar.");
    }

    public void virarManivela() {
        System.out.println("Entregando bolinha.");
    }

    public void entregar() {
        maquina.soltarBolinha();
        if (maquina.getCount() > 0) {
            maquina.setState(maquina.getSemCredito());
        } else {
            maquina.setState(maquina.getEsgotado());
        }
    }
}