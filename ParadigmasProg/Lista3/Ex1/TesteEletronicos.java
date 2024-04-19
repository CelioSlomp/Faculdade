public class TesteEletronicos {
    public static void main(String[] args) {
        Celular cel = new Celular("c1", "Dono1");
        Liquidificador liq = new Liquidificador("Potente");

        cel.pegar();
        cel.ligar();
        cel.guardar();

        liq.ligar();
        liq.desligar();
        liq.guardar();
    }
}
