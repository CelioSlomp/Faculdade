public class GarageDownCommand implements Command {
    GarageDoor garageDoor;

    public GarageDownCommand(GarageDoor garageDoor) {
        this.garageDoor = garageDoor;
    }

    @Override
    public String toString() {
        return this.garageDoor.lugar + " GarageDownCommand";
    }

    @Override
    public void execute() {
        this.garageDoor.down();
        System.out.println(this.garageDoor.lugar + " Garagem está fechada");
    }
}