public class ListaDuplaInteiros implements Iterable {
    private NoListaDupla head = null;
    private NoListaDupla tail = null;

    public ListaDuplaInteiros() {
        this.head = null;
        this.tail = null;
    }

    public NoListaDupla getHead() {
        return head;
    }

    public void inserirInicio(int valor) {
        NoListaDupla no = new NoListaDupla(valor);
        if (this.head != null)
            this.head.setAnt(no);
        else
            this.tail = no;
        no.setProx(this.head);
        this.head = no;
    }

    public void inserirFim(int valor) {
        NoListaDupla no = new NoListaDupla(valor);
        if (this.tail != null)
            this.tail.setProx(no);
        else
            this.head = no;
        no.setAnt(this.tail);
        this.tail = no;
    }

    public boolean isEmpty() {
        return this.head == null;
    }

    public void clear() {
        this.head = null;
        this.tail = null;
    }

    public int size() {
        NoListaDupla no = this.head;
        int tam = 0;
        while (no.getProx() != null) {
            tam++;
            no = no.getProx();
        }
        return tam;
    }

    public String toString() {
        String listaStr = "[";
        NoListaDupla no = this.head;
        while (no != null) {
            listaStr += String.valueOf(no.getInfo()) + ", ";
            no = no.getProx();
        }

        return listaStr.substring(0, listaStr.length() - 2) + "]";
    }

    public Iterator createIterator() {
        return new ListaDuplaIterator(this);
    }
}
