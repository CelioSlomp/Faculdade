public class Maquina {

    State esgotado;
    State semCredito;
    State comCredito;
    State vendido;
    State vencedor;

    State state = esgotado;
    int count = 0;

    public Maquina(int numBolinhas) {
        esgotado = new Esgotado(this);
        semCredito = new SemCredito(this);
        comCredito = new ComCredito(this);
        vendido = new Vendido(this);
        vencedor = new Vencedor(this);

        this.count = numBolinhas;
        if (numBolinhas > 0) {
            state = semCredito;
        } else {
            state = esgotado;
        }
    }

    public void encher(int numBolinhas) {
        count += numBolinhas;
        if (numBolinhas > 0) {
            state = semCredito;
        } else {
            state = esgotado;
        }
    }

    public void setState(State state) {
        this.state = state;
    }

    public int getCount() {
        return count;
    }

    public State getVencedor() {
        return vencedor;
    }

    public State getComCredito() {
        return comCredito;
    }

    public State getEsgotado() {
        return esgotado;
    }

    public State getSemCredito() {
        return semCredito;
    }

    public State getVendido() {
        return vendido;
    }

    public void soltarBolinha() {
        System.out.println("Bolinha entregue.");
        count -= 1;
    }

    public void inserirMoeda() {
        state.inserirMoeda();
    }

    public void ejetarMoeda() {
        state.ejetarMoeda();
    }

    public void virarManivela() {
        state.virarManivela();
        state.entregar();
    }

}
