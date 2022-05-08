package seiot.coffeemanager.view;

import seiot.coffeemanager.controller.ActiveController;
import seiot.coffeemanager.utils.EventSubscriber;

import java.util.Map;
import java.util.Set;

import com.google.gson.*;

public interface ManagerView {

    void run();

    void setController(EventSubscriber controller);

    void displayMachineStatus(String status);

    void displaySelfTestsNum(int selfTestsNum);

    void displayItemsNumber(Set<Map.Entry<String, JsonElement>> itemsNumber);

}
