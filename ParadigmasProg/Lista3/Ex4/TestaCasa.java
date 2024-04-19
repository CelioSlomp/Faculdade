public class TestaCasa {
    public static void main(String[] args) {

        Porta p1 = new Porta("verde", 1, 2, 3);
        Porta p2 = new Porta("vermelho", 2, 3, 4);
        Porta p3 = new Porta("preto", 3, 4, 5);

        p1.abre();
        p2.abre();

        Casa c1 = new Casa(p1, p2, p3, "amarelo");
        int portasAbertas = c1.quantasPortasEstaoAbertas();
        String cor = c1.getCor();
        System.out.println(cor);
        Porta p_1 = c1.getPorta1();
        Porta p_2 = c1.getPorta2();
        Porta p_3 = c1.getPorta3();
        c1.pinta("azul");
        System.out.println(c1.getCor());
    }
}
