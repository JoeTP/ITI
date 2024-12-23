/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloworld;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.effect.Reflection;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.shape.Rectangle;

/**
 *
 * @author Youssif
 */
public class HelloWorld extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        int width = 500;
        int height = 500;
        Stop[] stops = new Stop[] { new Stop(0, Color.BLACK), new Stop(0.5, Color.TRANSPARENT), 
            new Stop(0.5, Color.WHITE), new Stop(1, Color.BLACK)    };
        
        LinearGradient lg = new LinearGradient(0, 0, 0, 1, true, CycleMethod.REFLECT, stops);

        Rectangle r = new Rectangle(0,0,width-50,height-50);
        r.setFill(lg);
        
        
        Reflection reflection = new Reflection();
        reflection.setFraction(0.7);
        
        Text text = new Text("Hello World");
        text.setX(10.0);
        text.setY(50.0);
        text.setCache(true);
        text.setFill(Color.web("0xFF0000"));
        text.setFont(Font.font(null, FontWeight.BOLD, 40));
        text.setEffect(reflection);

 
        StackPane root = new StackPane();
        root.getChildren().add(r);
        root.getChildren().add(text);
        
        Scene scene = new Scene(root, width, height);
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
