public class LightOnCommand implements Command {
    Light light;

    public LightOnCommand(Light light) {
        this.light = light;
    }

    @Override
    public String toString() {
        return light.lugar + " LightOnCommand";
    }

    @Override
    public void execute() {
        this.light.on();

        System.out.println(light.lugar + " Luz está ligada");
    }
}