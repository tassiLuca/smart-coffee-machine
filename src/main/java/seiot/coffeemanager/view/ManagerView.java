package seiot.coffeemanager.view;

import seiot.coffeemanager.controller.ActiveController;
import seiot.coffeemanager.utils.EventSubscriber;

import java.util.Map;

public interface ManagerView {

    void run();

    void setController(EventSubscriber controller);

    void displayMachineStatus(String status);

    void displaySelfTestsNum(int selfTestsNum);

    void displayItemsNumber(Map<String, Integer> itemsNumber);

}
