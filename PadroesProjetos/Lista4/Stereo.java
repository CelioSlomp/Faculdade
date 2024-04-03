public class Stereo {
    public int volume;
    public boolean cdDvd;
    public boolean ligado;
    public String lugar;

    public Stereo(String lugar) {
        this.volume = 0;
        this.cdDvd = false;
        this.ligado = false;
        this.lugar = lugar;
    }

    public void on() {
        this.ligado = true;
    }

    public void off() {
        this.ligado = false;
    }

    public void setCD() {
        this.cdDvd = true;
    }

    public void setDVD() {
        this.cdDvd = true;
    }

    public void setRadio() {
        this.cdDvd = false;
    }

    public void setVolume(int vol) {
        this.volume = vol;
    }
}