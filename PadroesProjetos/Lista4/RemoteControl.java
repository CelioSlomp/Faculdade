import java.util.HashMap;
import java.util.ArrayList;

public class RemoteControl {
    ArrayList<Command> onCommands = new ArrayList<Command>();
    ArrayList<Command> offCommands = new ArrayList<Command>();

    Command onCommand;
    Command offCommand;

    ArrayList<Command> num;
    HashMap<Integer, ArrayList<Command>> nums;

    RemoteControl() {
        this.nums = new HashMap<Integer, ArrayList<Command>>();
        num = new ArrayList<Command>();
        num.add(new NoCommand());
        num.add(new NoCommand());
        for (int i = 0; i < 7; i++) {

            nums.put(i, num);
        }

    }

    public void setCommand(int slot, Command onCommand, Command offCommand) {
        num = new ArrayList<Command>();
        onCommands.add(onCommand);
        offCommands.add(offCommand);
        num.add(onCommand);
        num.add(offCommand);

        nums.put(slot, num);
    }

    public void onButtonWasPushed(int slot) {
        nums.get(slot).get(0).execute();
    }

    public void offButtonWasPushed(int slot) {
        nums.get(slot).get(1).execute();
    }

    public String toString() {
        String texto = "";

        for (Integer i : nums.keySet()) {
            texto += "[slot " + String.valueOf(i) + "] " + nums.get(i).get(0) + " " + nums.get(i).get(1) + "\n";
        }

        return texto;
    }

}
