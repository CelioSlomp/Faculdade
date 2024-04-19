public class Main {
    public static void main(String[] args) {
        Senha s1 = new Senha("1234");

        s1.entraSenha("a1");
        s1.entraSenha("a1");
        s1.entraSenha("1234");
        s1.trocarSenha("1234", "1222");
        s1.entraSenha("1234");
        s1.entraSenha("1234");
        s1.entraSenha("1234");
        s1.entraSenha("1234");
    }
}
