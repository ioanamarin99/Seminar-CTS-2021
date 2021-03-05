package ro.ase.acs.main;

import ro.ase.acs.services.Orchestrator;


public class Main {
    public static void main(String[] args) {
        Orchestrator orchestrator = new Orchestrator();
        orchestrator.execute();
    }
}