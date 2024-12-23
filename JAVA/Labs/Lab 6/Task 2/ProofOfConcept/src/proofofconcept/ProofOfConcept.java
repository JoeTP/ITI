/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proofofconcept;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

/**
 *
 * @author Youssif
 */
public class ProofOfConcept extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        Button btn = new Button();
        btn.setText("EXTERNAL THREAD");
        btn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                th.start();
                
                
                //the right way
                Platform.runLater(new Runnable(){
                @Override
                public void run() {
                String name = Thread.currentThread().getName();
                System.out.println("ProofOfConcept.stop()" + name);
            }
               }); 
               
            }
        });
        
        StackPane root = new StackPane();
        root.getChildren().add(btn);
        
        Scene scene = new Scene(root, 300, 250);
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
        
        String name = Thread.currentThread().getName();
        System.out.println("ProofOfConcept.start()" + name);
    }
    
    @Override
    public void stop() throws Exception{
        String name = Thread.currentThread().getName();
        System.out.println("ProofOfConcept.stop()" + name);
    }
    
    public void init()throws Exception{
        String name = Thread.currentThread().getName();
        System.out.println("ProofOfConcept.init()" + name);
    }
    
    //The wrong way
    Thread th = new Thread(new Runnable(){
        @Override
        public void run() {
        String name = Thread.currentThread().getName();
        System.out.println("ProofOfConcept.ExternalThread BAD WAY" + name);        }
    });
    
    
    public static void main(String[] args) {
        launch(args);  
    }
    
}
