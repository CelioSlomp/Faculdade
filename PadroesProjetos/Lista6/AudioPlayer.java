public class AudioPlayer {
    public static void main(String[] args) {
        WmaPlay arquivo = new WmaPlay();

        WmaAdapter adaptador = new WmaAdapter(arquivo);

        adaptador.abrir("alguma_musica.wma");

        adaptador.reproduzir();

        adaptador.parar();

        adaptador.abrir("outra_musica.wma");
        adaptador.parar();
    }
}
