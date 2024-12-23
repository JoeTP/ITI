import java.applet.Applet;
import java.awt.Graphics;
import java.util.Date;


public class Main extends Applet implements Runnable{
	
	public void init(){
		Thread th = new Thread(this);
		th.start();
	}
	
	public void paint(Graphics g){
		
		Date d = new Date();
		g.drawString(d.toString(), 100,100);
		
	}
	
	public void run(){
		while(true){
			try{
			Thread.sleep(1000);
			}catch(InterruptedException e){
				e.printStackTrace();
			}
			repaint();
		}
	}
	
}