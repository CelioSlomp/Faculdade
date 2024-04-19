public class Casa {
    private Porta porta1;
    private Porta porta2;
    private Porta porta3;
    private String cor;

    public Casa(Porta p1, Porta p2, Porta p3, String cor) {
        this.porta1 = p1;
        this.porta2 = p2;
        this.porta3 = p3;
        this.cor = cor;
    }

    public void pinta(String cor) {
        this.cor = cor;
        System.out.println("Casa pintada.");
    }

    public int quantasPortasEstaoAbertas() {
        int abertas = 0;
        if (porta1.estaAberta())
            abertas++;

        if (porta2.estaAberta())
            abertas++;

        if (porta3.estaAberta())
            abertas++;

        return abertas;
    }

    public String getCor() {
        return this.cor;
    }

    public Porta getPorta1() {
        return this.porta1;
    }

    public Porta getPorta2() {
        return this.porta2;
    }

    public Porta getPorta3() {
        return this.porta3;
    }

}
