public class WmaPlay {
    private String file = "";
    private boolean aberto = false;
    private int location = 0;
    private boolean tocando = false;

    public void setFile(String arquivo) {
        this.file = arquivo;
        System.out.println("Arquivo selecionado.");
    }

    public void open() {
        if (file == "") {
            System.out.println("Nenhum arquivo selecionado.");
        } else if (aberto) {
            System.out.println("Arquivo já está aberto.");
        } else {
            System.out.println("Arquivo aberto.");
            this.aberto = true;
        }
        this.tocando = false;
    }

    public void setLocation(int location) {
        this.location = location;
        System.out.println("O tempo foi ajustado.");
    }

    public void play() {
        if (tocando)
            System.out.println("Player já está tocando.");
        else {
            this.tocando = true;
            System.out.println("O player está tocando.");
        }
    }

    public void stop() {
        if (!tocando)
            System.out.println("Player já está parado.");
        else {
            this.tocando = false;
            System.out.println("O player foi pausado.");
        }
    }
}
