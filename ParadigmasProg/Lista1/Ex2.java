public class Ex2 {
    public static void main(String[] args) {

        loop1: for (int i = 0; i < 10; i++) {
            loop2: for (int j = 0; j < 10; j++) {
                System.out.println(String.valueOf(i) + " " + String.valueOf(j));
                if (i == 4 && j == 6)
                    break loop1; // Para o loop1, que é o principal.
            } // loop2
        } // loop1
    } // main
} // class