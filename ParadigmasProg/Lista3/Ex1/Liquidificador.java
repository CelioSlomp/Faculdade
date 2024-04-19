public class Liquidificador implements Eletronico {
    private String modelo;
    private boolean ligado;
    private boolean guardado;

    public Liquidificador(String modelo) {
        this.modelo = modelo;
        this.guardado = true;
        this.ligado = false;
    }

    @Override
    public void ligar() {
        if (!this.guardado) {
            this.ligado = true;
            System.out.println("Liquidificador ligado.");
        } else {
            System.out.println("Liquidificador está guardado.");
        }
    }

    @Override
    public void desligar() {
        if (!this.guardado) {
            this.ligado = false;
            System.out.println("Liquidificador desligado.");
        } else {
            System.out.println("Liquidificador está guardado.");
        }
    }

    @Override
    public void guardar() {
        if (this.guardado) {
            System.out.println("Liquidificador já está guardado.");
        } else {
            this.desligar();
            this.guardado = true;
            System.out.println("Liquidificador guardado.");
        }
    }

    @Override
    public void pegar() {
        this.guardado = false;
        System.out.println("Liquidificador pego.");
    }
}
