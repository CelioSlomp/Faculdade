public class GarageUpCommand implements Command {
    GarageDoor garageDoor;

    public GarageUpCommand(GarageDoor garageDoor) {
        this.garageDoor = garageDoor;
    }

    @Override
    public String toString() {
        return garageDoor.lugar + " GarageUpCommand";
    }

    @Override
    public void execute() {
        this.garageDoor.up();
        System.out.println(garageDoor.lugar + " Garagem está aberta");
    }
}