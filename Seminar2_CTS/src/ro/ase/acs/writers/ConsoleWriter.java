package ro.ase.acs.writers;

public class ConsoleWriter implements Writable {
    public void write(String message){
        System.out.println(message);
    }
}