package texteditor;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Dialog;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextArea;
import javafx.scene.input.Clipboard;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.layout.BorderPane;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCombination;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

public class FXMLDocumentBase extends BorderPane {

    protected final MenuBar editMenu;
    protected final Menu fileMenu;
    protected final MenuItem openLowMenuItem;
    protected final MenuItem openHighMenuItem;
    protected final MenuItem saveLowMenuItem;
    protected final MenuItem saveHighMenuItem;
    protected final MenuItem closeMenuItem;
    protected final Menu menu;
    protected final MenuItem cutMenuItem;
    protected final MenuItem copyMenuItem;
    protected final MenuItem pasteMenuItem;
    protected final MenuItem deleteMenuItem;
    protected final Menu helpMenu;
    protected final MenuItem aboutMenuItem;
    protected final TextArea textArea;
    Stage myStage;

    public FXMLDocumentBase(Stage stage) {

        myStage = stage;
        editMenu = new MenuBar();
        fileMenu = new Menu();
        openLowMenuItem = new MenuItem();
        openHighMenuItem = new MenuItem();
        saveLowMenuItem = new MenuItem();
        saveHighMenuItem = new MenuItem();
        closeMenuItem = new MenuItem();
        menu = new Menu();
        cutMenuItem = new MenuItem();
        copyMenuItem = new MenuItem();
        pasteMenuItem = new MenuItem();
        deleteMenuItem = new MenuItem();
        helpMenu = new Menu();
        aboutMenuItem = new MenuItem();
        textArea = new TextArea();

        setMaxHeight(USE_PREF_SIZE);
        setMaxWidth(USE_PREF_SIZE);
        setMinHeight(USE_PREF_SIZE);
        setMinWidth(USE_PREF_SIZE);
        setPrefHeight(400.0);
        setPrefWidth(600.0);

        BorderPane.setAlignment(editMenu, javafx.geometry.Pos.CENTER);

        fileMenu.setMnemonicParsing(false);
        fileMenu.setText("File");

        //INPUT FROM OUTSIDE THE APPLICATION
        openLowMenuItem.setMnemonicParsing(false);
        openLowMenuItem.setText("Open Low");
        openLowMenuItem.setAccelerator(new KeyCodeCombination(KeyCode.O, KeyCombination.CONTROL_DOWN));
        openLowMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                FileChooser fc = new FileChooser();
                File file = fc.showOpenDialog(myStage);
                if (file != null) {
                    try {
                        FileInputStream fis = new FileInputStream(file);
                        int size = fis.available();
                        byte[] b = new byte[size];
                        fis.read(b);
                        textArea.setText(new String(b));
                        fis.close();
                    } catch (FileNotFoundException ex) {
                        Logger.getLogger(FXMLDocumentBase.class.getName()).log(Level.SEVERE, null, ex);
                    } catch (IOException ex) {
                        Logger.getLogger(FXMLDocumentBase.class.getName()).log(Level.SEVERE, null, ex);
                    }
                } else {

                }
            }
        });

        //INPUT FROM OUTSIDE THE APPLICATION
        openHighMenuItem.setMnemonicParsing(false);
        openHighMenuItem.setText("Open Hight");
        openHighMenuItem.setAccelerator(new KeyCodeCombination(KeyCode.O, KeyCombination.CONTROL_DOWN, KeyCombination.SHIFT_DOWN));
        openHighMenuItem.setOnAction(new EventHandler() {
            @Override
            public void handle(Event event) {
                FileChooser fc = new FileChooser();
                File file = fc.showOpenDialog(myStage);
                if (file != null) {
                    try {
                        FileInputStream fis = new FileInputStream(file);
                        DataInputStream dis = new DataInputStream(fis);
                        textArea.setText(dis.readUTF());
                        dis.close();
                    } catch (FileNotFoundException ex) {
                        Logger.getLogger(FXMLDocumentBase.class.getName()).log(Level.SEVERE, null, ex);
                    } catch (IOException ex) {
                        Logger.getLogger(FXMLDocumentBase.class.getName()).log(Level.SEVERE, null, ex);
                    }
                } else {

                }
            }
        });

        //APPLICATION EXPORTING DATA
        saveLowMenuItem.setMnemonicParsing(false);
        saveLowMenuItem.setText("Save Low");
        saveLowMenuItem.setAccelerator(new KeyCodeCombination(KeyCode.S, KeyCombination.CONTROL_DOWN));
        saveLowMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                FileChooser fc = new FileChooser();
                File file = fc.showSaveDialog(myStage);
                if (file != null) {
                    try {
                        FileOutputStream fos = new FileOutputStream(file);
                        fos.write(textArea.getText().getBytes());
                        fos.flush();
                        fos.close();
                    } catch (FileNotFoundException ex) {
                        Logger.getLogger(FXMLDocumentBase.class.getName()).log(Level.SEVERE, null, ex);
                    } catch (IOException ex) {
                        Logger.getLogger(FXMLDocumentBase.class.getName()).log(Level.SEVERE, null, ex);
                    }
                } else {

                }

            }
        });
        
        //APPLICATION EXPORTING DATA
        saveHighMenuItem.setMnemonicParsing(false);
        saveHighMenuItem.setText("Save High");
        saveHighMenuItem.setAccelerator(new KeyCodeCombination(KeyCode.S, KeyCombination.CONTROL_DOWN, KeyCombination.SHIFT_DOWN));
        saveHighMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                FileChooser fc = new FileChooser();
                File file = fc.showSaveDialog(myStage);
                if (file != null) {
                    FileOutputStream fos;
                    try {
                        fos = new FileOutputStream(file);
                        DataOutputStream dos = new DataOutputStream(fos);
                        dos.writeUTF(textArea.getText());
                        dos.close();
                    } catch (FileNotFoundException ex) {
                        Logger.getLogger(FXMLDocumentBase.class.getName()).log(Level.SEVERE, null, ex);
                    } catch (IOException ex) {
                        Logger.getLogger(FXMLDocumentBase.class.getName()).log(Level.SEVERE, null, ex);
                    }

                } else {
                }

            }
        });

        closeMenuItem.setMnemonicParsing(false);
        closeMenuItem.setText("Close");
        closeMenuItem.setAccelerator(new KeyCodeCombination(KeyCode.Q, KeyCombination.CONTROL_DOWN));
        closeMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                Platform.exit();
            }
        });

        menu.setMnemonicParsing(false);
        menu.setText("Edit");

        cutMenuItem.setMnemonicParsing(false);
        cutMenuItem.setText("Cut");
        cutMenuItem.setAccelerator(new KeyCodeCombination(KeyCode.X, KeyCombination.CONTROL_DOWN));
        cutMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                textArea.cut();
            }
        });
        
        copyMenuItem.setMnemonicParsing(false);
        copyMenuItem.setText("Copy");
        copyMenuItem.setAccelerator(new KeyCodeCombination(KeyCode.C, KeyCombination.CONTROL_DOWN));
        copyMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                textArea.copy();
            }
        });
        
        pasteMenuItem.setMnemonicParsing(false);
        pasteMenuItem.setText("Paste");
        pasteMenuItem.setAccelerator(new KeyCodeCombination(KeyCode.V, KeyCombination.CONTROL_DOWN));
        pasteMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                    textArea.paste();
            }
        });
        
        deleteMenuItem.setMnemonicParsing(false);
        deleteMenuItem.setText("Delete");
        deleteMenuItem.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                    textArea.deleteText(  textArea.getSelection());
            }
        });

        helpMenu.setMnemonicParsing(false);
        helpMenu.setText("Help");
        helpMenu.setOnAction(new EventHandler<ActionEvent>() {
            Button bt = new Button("OK");

            @Override
            public void handle(ActionEvent event) {
                Alert dialog = new Alert(Alert.AlertType.INFORMATION, "VERSION 1.0", ButtonType.CLOSE);
                dialog.setContentText("THIS IS HELP!");
                dialog.setTitle("Help");
                dialog.show();
                dialog.setGraphic(bt);
                
                bt.setOnAction(new EventHandler<ActionEvent>() {
                    @Override
                    public void handle(ActionEvent event) {
                        dialog.close();
                    }
                });
            }
        });

        aboutMenuItem.setMnemonicParsing(false);
        aboutMenuItem.setText("About");
        setTop(editMenu);

        BorderPane.setAlignment(textArea, javafx.geometry.Pos.CENTER);
        textArea.setPrefHeight(200.0);
        textArea.setPrefWidth(200.0);
        setCenter(textArea);

        fileMenu.getItems().add(openLowMenuItem);
        fileMenu.getItems().add(openHighMenuItem);
        fileMenu.getItems().add(saveLowMenuItem);
        fileMenu.getItems().add(saveHighMenuItem);
        fileMenu.getItems().add(closeMenuItem);
        editMenu.getMenus().add(fileMenu);
        menu.getItems().add(cutMenuItem);
        menu.getItems().add(copyMenuItem);
        menu.getItems().add(pasteMenuItem);
        menu.getItems().add(deleteMenuItem);
        editMenu.getMenus().add(menu);
        helpMenu.getItems().add(aboutMenuItem);
        editMenu.getMenus().add(helpMenu);

    }
}
