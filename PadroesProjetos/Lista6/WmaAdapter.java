public class WmaAdapter implements FormatoAudio {
    private WmaPlay wmaPlay;

    public WmaAdapter(WmaPlay wmaPlay) {
        this.wmaPlay = wmaPlay;
    }

    public void abrir(String arquivo) {
        System.out.println("----------------------------");
        wmaPlay.setFile(arquivo);
        wmaPlay.open();
        wmaPlay.setLocation(0);
    }

    public void reproduzir() {
        System.out.println("----------------------------");
        wmaPlay.play();
    }

    public void parar() {
        System.out.println("----------------------------");
        wmaPlay.stop();
    }
}
