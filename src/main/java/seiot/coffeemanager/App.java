package seiot.coffeemanager;

import seiot.coffeemanager.controller.ActiveController;
import seiot.coffeemanager.utils.SerialCommChannel;
import seiot.coffeemanager.view.ManagerView;
import seiot.coffeemanager.view.ManagerViewImpl;

/** Main application entry-point. */
public final class App {

    private final static String DEFAULT_PORT = "/dev/tty.usbmodem1301";
    private final static int RATE = 9600;

    private App() { }

    public static void main(String[] args) throws Exception {
        String port;
        if (args.length != 0) {
            port = args[0];
        } else {
            port = DEFAULT_PORT;
        }
        SerialCommChannel channel = new SerialCommChannel(port, RATE);
        System.out.println("Waiting Arduino for rebooting");
        Thread.sleep(10000);
        System.out.println("Ready");

        final ManagerView view = new ManagerViewImpl();
        new ActiveController(channel, view).start();
        view.run();
    }
}
