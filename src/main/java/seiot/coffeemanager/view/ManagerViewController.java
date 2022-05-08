package seiot.coffeemanager.view;

import javafx.fxml.FXML;
import javafx.scene.chart.BarChart;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import seiot.coffeemanager.utils.AbstractEventPublisher;
import seiot.coffeemanager.utils.RecoverEvent;
import seiot.coffeemanager.utils.RefillEvent;

public class ManagerViewController extends AbstractEventPublisher {

    @FXML
    private Button refillBtn;

    @FXML
    private Button recoverBtn;

    @FXML
    private Label machineStatusLabel;

    @FXML
    private Label selfTestsNumLabel;

    @FXML
    private BarChart<String, Integer> productsChart;

    private void setLabel(Label label, String labelMsg) {
        label.setText(labelMsg);
    }

    public void setMachineStatusLabel(String labelMsg) {
        setLabel(machineStatusLabel, labelMsg);
    }

    public void setSelfTestsNumLabel(String labelMsg) {
        setLabel(selfTestsNumLabel, labelMsg);
    }

    @FXML
    public void refillBtnPressed() {
        System.out.println("REFILL BTN PRESSED");
        this.post(new RefillEvent());
    }

    @FXML
    public void recoverBtnPressed() {
        System.out.println("RECOVER BTN PRESSED");
        this.post(new RecoverEvent());
    }

}
