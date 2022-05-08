package seiot.coffeemanager.view;

import javafx.fxml.FXML;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import seiot.coffeemanager.utils.AbstractEventPublisher;
import seiot.coffeemanager.utils.RecoverEvent;
import seiot.coffeemanager.utils.RefillEvent;
import com.google.gson.*;


import java.util.Map;
import java.util.Set;

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

    public void setChart(Set<Map.Entry<String, JsonElement>> products) {


        this.productsChart.getData().clear();
        final var dataset = new XYChart.Series<String, Integer>();

        products.forEach(e -> dataset.getData().add(new XYChart.Data<>(e.getKey(), e.getValue().getAsInt())));

        this.productsChart.getData().add(dataset);
    }

    @FXML
    public void refillBtnPressed() {
        this.post(new RefillEvent());
    }

    @FXML
    public void recoverBtnPressed() {
        this.post(new RecoverEvent());
    }

}
