public class LightOffCommand implements Command {
    Light light;

    public LightOffCommand(Light light) {
        this.light = light;
    }

    @Override
    public String toString() {
        return light.lugar + " LightOffCommand";
    }

    @Override
    public void execute() {
        this.light.off();

        System.out.println(light.lugar + " luz está apagado");
    }
}