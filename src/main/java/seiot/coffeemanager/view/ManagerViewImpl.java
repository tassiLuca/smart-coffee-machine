package seiot.coffeemanager.view;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import seiot.coffeemanager.utils.EventSubscriber;

import java.util.Map;
import java.util.Optional;
import java.util.Set;

import com.google.gson.*;

public class ManagerViewImpl extends Application implements ManagerView {

    private static Optional<ManagerViewController> viewController = Optional.empty();
    private static EventSubscriber eventController;

    @Override
    public final void start(final Stage primaryStage) throws Exception {
        final FXMLLoader loader = new FXMLLoader(getClass().getResource("/layouts/SimpleGui.fxml"));
        final Parent root = loader.load();
        viewController = Optional.of(loader.getController());
        viewController.get().register(eventController);
        final Scene scene = new Scene(root);
        primaryStage.setTitle("App FXML");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public void run() {
        launch();
    }

    @Override
    public void setController(final EventSubscriber controller) {
        eventController = controller;
    }

    private void updateView(final Runnable runnable) {
        Platform.runLater(runnable);
    }

    @Override
    public void displayMachineStatus(final int status) {
        viewController.ifPresent(managerViewController -> updateView(
                () -> managerViewController.setMachineStatusLabel(status))
        );
    }

    @Override
    public void displaySelfTestsNum(final int selfTestsNum) {
        viewController.ifPresent(managerViewController -> updateView(
                () -> viewController.get().setSelfTestsNumLabel(selfTestsNum))
        );
    }

    @Override
    public void displayItemsNumber(final Set<Map.Entry<String, JsonElement>> itemsNumber) {
        viewController.ifPresent(managerViewController -> updateView(
                () -> managerViewController.setChart(itemsNumber))
        );
    }

}
