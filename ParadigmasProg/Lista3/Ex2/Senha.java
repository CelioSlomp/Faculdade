public class Senha {
    private String senha;
    private int tentativas;

    public Senha(String senha) {
        this.senha = senha;
        this.tentativas = 3;
    }

    public void entraSenha(String senha) {
        if (tentativas > 0) {
            if (this.senha == senha) {
                this.tentativas = 3;
                System.out.println("Senha correta.");
            } else {
                this.tentativas--;
                System.out.println("Senha incorreta.");
            }
        } else {
            System.out.println("Senha bloqueada.");
        }
    }

    public void trocarSenha(String senhaAntiga, String senhaNova) {
        if (tentativas > 0) {
            if (this.senha == senhaAntiga) {
                this.senha = senhaNova;
                this.tentativas = 3;
                System.out.println("Senha alterada.");
            } else {
                this.tentativas--;
                System.out.println("Senha incorreta.");
            }
        } else {
            System.out.println("Senha bloqueada.");
        }
    }
}
