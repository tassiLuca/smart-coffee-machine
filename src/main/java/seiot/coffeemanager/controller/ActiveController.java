package seiot.coffeemanager.controller;

import seiot.coffeemanager.utils.EventSubscriber;
import seiot.coffeemanager.utils.SerialCommChannel;
import seiot.coffeemanager.view.ManagerView;
import com.jayway.jsonpath.JsonPath;

public class ActiveController extends Thread implements EventSubscriber {

    private SerialCommChannel channel;
    private ManagerView view;

    public ActiveController(SerialCommChannel channel, ManagerView view) {
        this.channel = channel;
        this.view = view;
        this.view.setController(this);
    }

    public void run() {
        while(true) {
            String msg = null;
            try {
                msg = this.channel.receiveMsg();
                extractInfos(msg);
            } catch (Exception e) {
                System.out.println("Not useful info");
            }
        }
    }

    public void extractInfos(String info) {
        String status = Integer.toString(JsonPath.read(info, "$.status"));
        int testsNum = JsonPath.read(info, "$.tests");
        this.view.displayMachineStatus(status);
        this.view.displaySelfTestsNum(testsNum);
        // var productsWithCount = new HashMap<String, Integer>();
        // Integer products = JsonPath.read(info, "$.products.length()");
    }


    @Override
    public void notifyEvent() {
        System.out.println("[CONTROLLER] EVENT RECEIVED");
    }
}
