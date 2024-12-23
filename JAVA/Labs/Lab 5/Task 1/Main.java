import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Button;
import java.awt.event.*;


public class Main extends Applet{
	
	int count = 0;
	Button incButton;
	Button decButton;
	int width;
	int height;
	
	public void init(){
		incButton = new Button("INCREMENT");
		incButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				count++;
				repaint();
			}
		});
		
		decButton = new Button("DECREMENT");
		decButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				count--;
				repaint();
			}
		});
		
		add(incButton);
		add(decButton);
	}
	
	public void paint(Graphics g){
		width = getWidth();
		height = getHeight();
		
		g.drawString("COUNT: " + count, width/2 - 50, height/2);
		

	}
}