public class RemoteLoader {

    public static void main(String[] args) {
        RemoteControl remoteControl = new RemoteControl();

        Light luz = new Light("cozinha");
        CeilingFan vent = new CeilingFan("quarto");
        GarageDoor portaGar = new GarageDoor("garagem");
        Light luz2 = new Light("banheiro");

        remoteControl.setCommand(0, new LightOnCommand(luz), new LightOffCommand(luz));
        remoteControl.setCommand(1, new CeilingFanHighCommand(vent), new CeilingFanOffCommand(vent));
        remoteControl.setCommand(2, new GarageUpCommand(portaGar), new GarageDownCommand(portaGar));
        remoteControl.setCommand(3, new LightOnCommand(luz2), new LightOffCommand(luz2));

        System.out.println(remoteControl.toString());

        remoteControl.onButtonWasPushed(0);
        remoteControl.offButtonWasPushed(0);
        remoteControl.onButtonWasPushed(1);
        remoteControl.offButtonWasPushed(1);
        remoteControl.onButtonWasPushed(2);
        remoteControl.offButtonWasPushed(2);
        remoteControl.onButtonWasPushed(3);
        remoteControl.offButtonWasPushed(3);

    }
}
