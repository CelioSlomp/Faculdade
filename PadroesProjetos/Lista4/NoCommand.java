public class NoCommand implements Command {
    @Override
    public void execute() {
        // Execute vazio porque não faz nada.
    }

    @Override
    public String toString() {
        return "NoCommand";
    }
}