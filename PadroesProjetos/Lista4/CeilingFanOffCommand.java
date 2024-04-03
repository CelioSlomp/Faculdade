public class CeilingFanOffCommand implements Command {
    CeilingFan ceilingFan;

    public CeilingFanOffCommand(CeilingFan ceilingFan) {
        this.ceilingFan = ceilingFan;
    }

    @Override
    public String toString() {
        return ceilingFan.lugar + " CeilingFanOffCommand";
    }

    @Override
    public void execute() {
        this.ceilingFan.off();
        System.out.println(ceilingFan.lugar + " Ventilador está desligado");
    }
}