package seiot.coffeemanager.controller;

import seiot.coffeemanager.utils.EventSubscriber;
import seiot.coffeemanager.utils.RecoverEvent;
import seiot.coffeemanager.utils.RefillEvent;
import seiot.coffeemanager.utils.SerialCommChannel;
import seiot.coffeemanager.view.ManagerView;
import com.jayway.jsonpath.JsonPath;
import com.google.common.eventbus.Subscribe;

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
        System.out.println(info);
        // var productsWithCount = new HashMap<String, Integer>();
        // Integer products = JsonPath.read(info, "$.products.length()");
    }


    @Subscribe
    public void notifyEvent(RefillEvent event) {
        this.channel.sendMsg("REFILL");
    }

    @Subscribe
    public void notifyEvent(RecoverEvent event) {
        this.channel.sendMsg("RECOVER");
    }

}
