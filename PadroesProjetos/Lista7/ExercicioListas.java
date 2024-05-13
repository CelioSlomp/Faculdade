public class ExercicioListas {
    public static void main(String[] args) {
        ListaDuplaInteiros lista = new ListaDuplaInteiros();

        lista.inserirFim(1);
        Iterator ite = lista.createIterator(); // Precisa ser instanciado com a lista não nula
        lista.inserirFim(2);
        lista.inserirFim(3);
        lista.inserirFim(4);
        lista.inserirFim(5);

        ite.first();
        while (ite.hasNext()) {
            System.out.println(ite.next());
        }

        ite.last();
        while (ite.hasPrevious()) {
            System.out.println(ite.previous());
        }

        System.out.println(lista.toString());
    }
}
