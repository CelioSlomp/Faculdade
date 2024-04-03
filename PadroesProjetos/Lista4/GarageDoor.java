public class GarageDoor {
    private boolean aberta;
    public String lugar;

    public GarageDoor(String lugar) {
        this.aberta = false;
        this.lugar = lugar;
    }

    public void up() {
        this.aberta = true;
    }

    public void down() {
        this.aberta = false;
    }
}