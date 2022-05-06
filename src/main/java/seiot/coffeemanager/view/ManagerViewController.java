package seiot.coffeemanager.view;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

import java.util.Map;

public class ManagerViewController {

    @FXML
    private Button refillBtn;

    @FXML
    private Button recoverBtn;

    @FXML
    private Label machineStatusLabel;

    @FXML
    private Label selfTestsNumLabel;

    private void setLabel(Label label, String labelMsg) {
        label.setText(labelMsg);
    }

    public void setMachineStatusLabel(String labelMsg) {
        setLabel(machineStatusLabel, labelMsg);
    }

    public void setSelfTestsNumLabel(String labelMsg) {
        setLabel(selfTestsNumLabel, labelMsg);
    }

}
