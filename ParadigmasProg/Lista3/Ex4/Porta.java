public class Porta {
    private boolean aberta;
    private String cor;
    private double dimensaoX;
    private double dimensaoY;
    private double dimensaoZ;

    public Porta(String cor, double dimX, double dimY, double dimZ) {
        this.aberta = false;
        this.cor = cor;
        this.dimensaoX = dimX;
        this.dimensaoY = dimY;
        this.dimensaoZ = dimZ;
    }

    public void abre() {
        if (aberta) {
            System.out.println("Porta já está aberta");
        } else {
            this.aberta = true;
            System.out.println("Porta foi aberta.");
        }
    }

    public void fecha() {
        if (!aberta) {
            System.out.println("Porta já está fechada");
        } else {
            this.aberta = false;
            System.out.println("Porta foi fechada.");
        }
    }

    public void pinta(String cor) {
        this.cor = cor;
        System.out.println("A porta foi pintada de " + cor);
    }

    public boolean estaAberta() {
        return this.aberta;
    }
}
