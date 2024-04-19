import java.time.LocalDate;

public class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data(int d, int m, int a) {
        if (d < 0 || m < 1 || d > 31 || m > 12) {
            throw new RuntimeException("dia ou mes invalido.");
        }
        if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
            throw new RuntimeException("dia 31 em mes de 30.");
        }
        if (!anoBissexto(a) && d > 28 && m == 2) {
            throw new RuntimeException("dia 29 em fev. em ano nao bissexto.");
        }
        this.dia = d;
        this.mes = m;
        this.ano = a;
    }

    public boolean anoBissexto(int a) {
        if ((double) a % 100.0 == 0)
            return false;
        if ((double) a % 4.0 == 0)
            return true;
        return false;
    }

    public void proximoDia() {
        if (anoBissexto(this.ano) && this.mes == 2 && this.dia == 28) {
            this.dia = 29;
        } else if (){
            
        }
    }

}
