public class ListaDuplaIterator implements Iterator {

    private NoListaDupla atual = null;
    private ListaDuplaInteiros lista = null;
    private int indice = 0;

    public ListaDuplaIterator(ListaDuplaInteiros atual) {
        this.lista = atual;
        this.atual = this.lista.getHead();
    }

    @Override
    public void first() {
        while (this.atual.getAnt() != null) {
            this.atual = this.atual.getAnt();
        }
        this.indice = 0;
    }

    @Override
    public void last() {
        while (this.atual.getProx() != null) {
            this.atual = this.atual.getProx();
            this.indice++;
        }
    }

    @Override
    public boolean hasNext() {
        return this.atual.getProx() != null;
    }

    @Override
    public boolean hasPrevious() {
        return this.atual.getAnt() != null;
    }

    @Override
    public int next() {
        if (!(this.atual.getProx() == null)) {
            NoListaDupla tmp = this.atual;
            this.atual = this.atual.getProx();
            this.indice++;
        }
        return this.atual.getInfo();
    }

    @Override
    public int nextIndex() {
        if (!(this.atual.getProx() == null)) {
            this.atual = this.atual.getProx();
            this.indice++;
        }
        return this.indice;
    }

    @Override
    public int previous() {
        if (!(this.atual.getAnt() == null)) {
            this.atual = this.atual.getAnt();
            this.indice--;
        }
        return this.atual.getInfo();
    }

    @Override
    public int previousIndex() {
        if (!(this.atual.getAnt() == null)) {
            this.atual = this.atual.getAnt();
            this.indice--;
        }
        return this.indice;
    }
}