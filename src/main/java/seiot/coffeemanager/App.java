package seiot.coffeemanager;

import seiot.coffeemanager.controller.ActiveController;
import seiot.coffeemanager.utils.SerialCommChannel;
import seiot.coffeemanager.view.ManagerView;
import seiot.coffeemanager.view.ManagerViewImpl;

/** Main application entry-point. */
public final class App {

    private App() { }

    public static void main(String... args) throws Exception {
        /* /dev/tty.usbmodem21301 */
        SerialCommChannel channel = new SerialCommChannel("/dev/tty.usbmodem21301", 9600);
        System.out.println("Waiting Arduino for rebooting");
        Thread.sleep(10000);
        System.out.println("Ready");

        final ManagerView view = new ManagerViewImpl();
        new ActiveController(channel, view).start();
        view.run();
    }
}
