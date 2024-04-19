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
        if ((!anoBissexto(a) && m == 2 && d > 28) || (m == 2 && d > 29)) {
            throw new RuntimeException("dia acima de 28 de fev. em ano nao bissexto.");
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
            this.dia++;
        } else if (this.mes == 12 && this.dia == 31) {
            this.ano++;
            this.mes = 1;
            this.dia = 1;
        } else if ((this.mes == 4 || this.mes == 6 || this.mes == 9 || this.mes == 11) && this.dia == 30) {
            this.dia = 1;
            this.mes++;
        } else if (!(this.mes == 4 || this.mes == 6 || this.mes == 9 || this.mes == 11) && this.dia == 31) {
            this.dia = 1;
            this.mes++;
        } else if (this.mes == 2 && this.dia == 29) {
            this.mes++;
            this.dia = 1;
        } else {
            this.dia++;
        }
    }

    public void printData() {
        System.out.println(String.valueOf(dia) + "/" + String.valueOf(mes) + "/" + String.valueOf(ano));
    }

}
