package seiot.coffeemanager.view;

import java.util.Map.Entry;
import java.util.Set;
import com.google.gson.*;

import seiot.coffeemanager.utils.EventSubscriber;

public interface ManagerView {

    /**
     * Launch the execution of the view.
     */
    void run();

    /**
     * Set the controller of the system.
     * @param controller the {@link EventSubscriber} to associate to the view.
     */
    void setController(EventSubscriber controller);

    /**
     * Display on the view the status of the machine.
     * @param status a string representing the state of the machine.
     */
    void displayMachineStatus(int status);

    /**
     * Display on the view the number of self tests executed by the machine
     * @param selfTestsNum an integer describing the number of self tests
     */
    void displaySelfTestsNum(int selfTestsNum);

    /**
     * Graph the left quantity of the products.
     * @param itemsNumber a set of entries product - quantity
     */
    void displayItemsNumber(Set<Entry<String, JsonElement>> itemsNumber);

}
