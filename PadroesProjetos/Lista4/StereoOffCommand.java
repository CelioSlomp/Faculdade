public class StereoOffCommand implements Command {
    Stereo stereo;
    String nome = "StereoOffCommand";

    public StereoOffCommand(Stereo stereo) {
        this.stereo = stereo;
    }

    @Override
    public String toString() {
        return stereo.lugar + " StereoOffCommand";
    }

    @Override
    public void execute() {
        stereo.off();

        System.out.println(stereo.lugar + " Stereo está desligado");
    }
}