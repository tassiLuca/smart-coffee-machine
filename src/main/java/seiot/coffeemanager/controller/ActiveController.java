package seiot.coffeemanager.controller;

import com.jcabi.log.Logger;
import org.slf4j.LoggerFactory;
import seiot.coffeemanager.utils.EventSubscriber;
import seiot.coffeemanager.utils.RecoverEvent;
import seiot.coffeemanager.utils.RefillEvent;
import seiot.coffeemanager.utils.SerialCommChannel;
import seiot.coffeemanager.view.ManagerView;
import com.google.common.eventbus.Subscribe;
import com.google.gson.*;

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
                LoggerFactory.getLogger(this.getClass()).error("Malformed json");
            }
        }
    }

    public void extractInfos(final String info) {
        final int status = JsonParser.parseString(info)
                .getAsJsonObject()
                .get("status")
                .getAsInt();
        final int testsNum = JsonParser.parseString(info)
                .getAsJsonObject()
                .get("tests")
                .getAsInt();
        Set<Map.Entry<String, JsonElement>> prods = JsonParser.parseString(info)
                .getAsJsonObject()
                .get("products")
                .getAsJsonObject().entrySet();
        this.view.displayMachineStatus(status);
        this.view.displaySelfTestsNum(testsNum);
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
