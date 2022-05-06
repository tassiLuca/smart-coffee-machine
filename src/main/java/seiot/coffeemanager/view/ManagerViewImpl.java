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

import java.util.Map;

public class ManagerViewImpl extends Application implements ManagerView {

    private static ManagerViewController viewController;

    @Override
    public final void start(final Stage primaryStage) throws Exception {
        final FXMLLoader loader = new FXMLLoader(getClass().getResource("/layouts/SimpleGui.fxml"));
        final Parent root = loader.load();
        viewController = loader.getController();
        viewController.setMachineStatusLabel("Hello boys");
        final Scene scene = new Scene(root);
        primaryStage.setTitle("App FXML");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public void run() {
        launch();
    }

    @Override
    public void displayMachineStatus(String status) {
        Platform.runLater(() -> viewController.setMachineStatusLabel(status));
    }

    @Override
    public void displaySelfTestsNum(int selfTestsNum) {

    }

    @Override
    public void displayItemsNumber(Map<String, Integer> itemsNumber) {

    }

}
