package ro.ase.acs.services;

import ro.ase.acs.container.IocContainer;
import ro.ase.acs.readers.ConsoleReader;
import ro.ase.acs.readers.Readable;
import ro.ase.acs.writers.ConsoleWriter;
import ro.ase.acs.writers.Writable;

public class Orchestrator {
    private Readable reader;
    private Writable writer;
    private IocContainer container = new IocContainer();

    public Orchestrator() {
        this.container.register(Readable.class, ConsoleReader.class);
        this.container.register(Writable.class, ConsoleWriter.class);
        this.reader = this.container.resolve(Readable.class);
        this.writer = this.container.resolve(Writable.class);
    }

    public void execute() {
        writer.write(reader.read());
    }
}
