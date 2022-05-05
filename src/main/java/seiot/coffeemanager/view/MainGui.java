package seiot.coffeemanager.view;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class MainGui extends Application {

    @Override
    public final void start(final Stage primaryStage) throws Exception {
        final Parent root = FXMLLoader.load(ClassLoader.getSystemResource("layouts/SimpleGui.fxml"));
        final Scene scene = new Scene(root);
        primaryStage.setTitle("App FXML");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void run(final String[] args) {
        launch(args);
    }

}
