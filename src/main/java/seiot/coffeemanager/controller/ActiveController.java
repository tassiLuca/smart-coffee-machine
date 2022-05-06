package seiot.coffeemanager.controller;

import javafx.application.Platform;
import seiot.coffeemanager.utils.SerialCommChannel;
import seiot.coffeemanager.view.ManagerView;
import com.jayway.jsonpath.JsonPath;

public class ActiveController extends Thread {

    private SerialCommChannel channel;
    private ManagerView view;

    public ActiveController(SerialCommChannel channel, ManagerView view) {
        this.channel = channel;
        this.view = view;
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
        this.view.displayMachineStatus(status);
    }

}
