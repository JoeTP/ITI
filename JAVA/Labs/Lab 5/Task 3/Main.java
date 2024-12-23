import java.applet.Applet;
import java.util.Random;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.Thread.State;

public class Main extends Applet{
	
	Random rand = new Random();
	int x1 = 0;
	int y1 = 0;
	int width;
	int height;
	int size = 50;
	boolean fx1 = true;
	boolean fy1 = true;
	int speed = 5;
	boolean started = false;
	
	Button startButton;
	Button stopButton;
	
	public void init(){
		width = getWidth();
		height = getHeight();
		
		x1 = rand.nextInt(width - size);
		y1 = rand.nextInt(height - size);
		
		
		Thread th = new Thread(new Runnable(){
				public void run(){
				while(true){
			
			try{
			Thread.sleep(30);
			if(fx1){
				x1 += speed;
				if(x1 > width - size - speed){
				fx1 = false;
				}
			}else{
				x1 -= speed;
				if (x1 <= 0){
				fx1 = true;
				}
			}
			
			if(fy1 ){
				y1 += speed;
				if(y1 > height - size - speed){
				fy1 = false;
				}
			}else{
				y1 -= speed;
				if (y1 <= 0){
				fy1 = true;
				}
			}
			repaint();
			}catch(InterruptedException e){
				e.printStackTrace();
					}		
				}
			}
		});
	
	
	class StartActionListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			if(started == false){
				th.start();
				started = true;
			}else{
				th.resume(); //this is because thread can only started ONCE!!
			}
		}
	}
	
		startButton = new Button("START");
		StartActionListener SAL = new StartActionListener();
		startButton.addActionListener(SAL);
		
		stopButton = new Button("PAUSE");
		stopButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				if(started == true){
					th.suspend();
				}
			}
		});
		
		add(startButton);
		add(stopButton);
	
	}
	
	
	public void paint(Graphics g){
		
		
		g.fillOval(x1, y1, size, size);
	}
	
	
	
	
}