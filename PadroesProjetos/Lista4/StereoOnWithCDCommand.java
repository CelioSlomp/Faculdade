public class StereoOnWithCDCommand implements Command {
    Stereo stereo;

    public StereoOnWithCDCommand(Stereo stereo) {
        this.stereo = stereo;
    }

    @Override
    public String toString() {
        return stereo.lugar + " StereoOnWithCDCommand";
    }

    @Override
    public void execute() {
        stereo.on();
        stereo.setCD();

        System.out.println(stereo.lugar + " Stereo está ligado e com CD");
    }
}