package seiot.coffeemanager.controller;

import net.minidev.json.JSONObject;
import net.minidev.json.parser.JSONParser;
import seiot.coffeemanager.utils.EventSubscriber;
import seiot.coffeemanager.utils.RecoverEvent;
import seiot.coffeemanager.utils.RefillEvent;
import seiot.coffeemanager.utils.SerialCommChannel;
import seiot.coffeemanager.view.ManagerView;
import com.jayway.jsonpath.JsonPath;
import com.google.common.eventbus.Subscribe;
import com.google.gson.*;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class ActiveController extends Thread implements EventSubscriber {

    private SerialCommChannel channel;
    private ManagerView view;

    public ActiveController(final SerialCommChannel channel, final ManagerView view) {
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
                e.printStackTrace();
            }
        }
    }

    public void extractInfos(final String info) {
        final int status = JsonPath.read(info, "$.status");
        final int testsNum = JsonPath.read(info, "$.tests");
        this.view.displayMachineStatus(status);
        this.view.displaySelfTestsNum(testsNum);
        Set<Map.Entry<String, JsonElement>> prods = JsonParser.parseString(info)
                .getAsJsonObject()
                .get("products")
                .getAsJsonObject().entrySet();
        this.view.displayItemsNumber(prods);
    }


    @Subscribe
    public void notifyEvent(final RefillEvent event) {
        this.channel.sendMsg("REFILL");
    }

    @Subscribe
    public void notifyEvent(final RecoverEvent event) {
        this.channel.sendMsg("RECOVER");
    }

}
