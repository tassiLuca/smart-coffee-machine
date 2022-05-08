package seiot.coffeemanager.view;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.stage.Stage;
import seiot.coffeemanager.controller.ActiveController;
import seiot.coffeemanager.utils.Event;
import seiot.coffeemanager.utils.EventSubscriber;

import java.util.Map;
import java.util.Set;
import com.google.gson.*;

public class ManagerViewImpl extends Application implements ManagerView {

    private static ManagerViewController viewController;
    private static EventSubscriber eventController;

    @Override
    public final void start(final Stage primaryStage) throws Exception {
        final FXMLLoader loader = new FXMLLoader(getClass().getResource("/layouts/SimpleGui.fxml"));
        final Parent root = loader.load();
        viewController = loader.getController();
        viewController.setMachineStatusLabel("Hello boys");

        try {
            viewController.register(eventController);
        } catch(Exception e) {
            System.out.println("CONTROLLER NULL");
        }

        final Scene scene = new Scene(root);
        primaryStage.setTitle("App FXML");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public void run() {
        launch();
    }

    @Override
    public void setController(EventSubscriber controller) {
        eventController = controller;
    }

    @Override
    public void displayMachineStatus(String status) {
        // TODO null pointer exception
        Platform.runLater(() -> viewController.setMachineStatusLabel(status));
    }

    @Override
    public void displaySelfTestsNum(int selfTestsNum) {
        // TODO null pointer exception
        Platform.runLater(() -> viewController.setSelfTestsNumLabel(Integer.toString(selfTestsNum)));
    }

    @Override
    public void displayItemsNumber(Set<Map.Entry<String, JsonElement>> itemsNumber) {
        // TODO null pointer exception
        Platform.runLater(() -> viewController.setChart(itemsNumber));
    }

}
