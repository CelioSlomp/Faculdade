public class Light {
    public boolean luz;
    public String lugar;

    public Light(String lugar) {
        this.luz = false;
        this.lugar = lugar;
    }

    public void on() {
        this.luz = true;
    }

    public void off() {
        this.luz = false;
    }
}