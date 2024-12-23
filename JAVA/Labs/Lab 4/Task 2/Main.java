import java.applet.Applet;
import java.awt.*;
import java.util.Date;


public class Main extends Applet implements Runnable{
	
	
	public void init(){
		Thread th = new Thread(this);
		th.start();
	}
	
	int x = 0;
	int width;
	//int height = getHeight();
		
	public void paint(Graphics g){
		width = getWidth();
		
		g.setColor(Color.RED);
		g.fillRect(0, 80, width, 35);
		g.setColor(Color.WHITE);
		g.drawString("JAVA WORLD", x, 100);
	}
	
	public void run(){
		while(true){
			
			try{
			Thread.sleep(200);
			if(x < width){
				x += 8;
			}else{
				x = -75;
			}
			repaint();
			}catch(InterruptedException e){
				e.printStackTrace();
			}
			
		}
	}
	
}