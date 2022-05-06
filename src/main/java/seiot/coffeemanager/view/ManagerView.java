package seiot.coffeemanager.view;

import java.util.Map;

public interface ManagerView {

    void run();

    void displayMachineStatus(String status);

    void displaySelfTestsNum(int selfTestsNum);

    void displayItemsNumber(Map<String, Integer> itemsNumber);

}
