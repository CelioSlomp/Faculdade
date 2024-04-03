public class CeilingFanHighCommand implements Command {
    CeilingFan ceilingFan;

    public CeilingFanHighCommand(CeilingFan ceilingFan) {
        this.ceilingFan = ceilingFan;
    }

    @Override
    public String toString() {
        return ceilingFan.lugar + " CeilingFanHighCommand";
    }

    @Override
    public void execute() {
        if (this.ceilingFan.getSpeed() == 1)
            this.ceilingFan.mediumSpeed();
        else if (this.ceilingFan.getSpeed() == 2)
            this.ceilingFan.highSpeed();
        else
            this.ceilingFan.lowSpeed();

        System.out.println(
                this.ceilingFan.lugar + " A velocidade do ventilador é de: " + String.valueOf(ceilingFan.getSpeed()));
    }
}