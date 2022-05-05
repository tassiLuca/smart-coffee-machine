package seiot.coffeemanager;

import seiot.coffeemanager.view.MainGui;
import jssc.*;

/** Main application entry-point. */
public final class App {
    private App() { }

    public static void main(final String[] args) {
        /* detect serial ports */
        String[] portNames = SerialPortList.getPortNames();
        for (int i = 0; i < portNames.length; i++){
            System.out.println(portNames[i]);
        }
        MainGui.run(args);
    }
}
