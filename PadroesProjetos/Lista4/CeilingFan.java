public class CeilingFan {
    private int girando = 0;
    public String lugar;

    public CeilingFan(String lugar) {
        this.girando = 0;
        this.lugar = lugar;
    }

    public void highSpeed() {
        this.girando = 3;
    }

    public void mediumSpeed() {
        this.girando = 2;
    }

    public void lowSpeed() {
        this.girando = 1;
    }

    public int getSpeed() {
        return this.girando;
    }

    public void off() {
        this.girando = 0;
    }
}