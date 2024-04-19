public class Celular implements Eletronico {
    private String modelo;
    private String dono;
    private boolean ligado;
    private boolean guardado;

    public Celular(String modelo, String dono) {
        this.modelo = modelo;
        this.dono = dono;
        this.ligado = false;
        this.guardado = true;
    }

    @Override
    public void ligar() {
        if (!this.guardado) {
            this.ligado = true;
            System.out.println("Celular ligado.");
        } else {
            System.out.println("Celular está guardado.");
        }
    }

    @Override
    public void desligar() {
        if (!this.guardado) {
            this.ligado = false;
            System.out.println("Celular desligado.");
        } else {
            System.out.println("Celular está guardado.");
        }
    }

    @Override
    public void guardar() {
        if (this.guardado) {
            System.out.println("Celular já está guardado.");
        } else {
            this.desligar();
            this.guardado = true;
            System.out.println("Celular guardado.");
        }
    }

    @Override
    public void pegar() {
        this.guardado = false;
        System.out.println("Celular pego.");
    }
}