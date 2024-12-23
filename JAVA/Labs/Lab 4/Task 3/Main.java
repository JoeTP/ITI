import java.applet.Applet;
import java.awt.*;
import java.util.Date;


public class Main extends Applet implements Runnable{
	
	
	public void init(){
		Thread th = new Thread(this);
		th.start();
		
		x2 = getWidth();
		y2 = getHeight();
		
		
	}
	
	int x1 = 0;
	int y1 = 0;
	int x2 ;
	int y2 ;
	int width;
	int height;
	int size = 50;
	boolean fx1 = true;
	boolean fy1 = true;
	boolean fx2 = false;
	boolean fy2 = false;
	int i = 0;
	int speed = 5;
	
	Color[] colors = {
		Color.RED,
		Color.BLUE,
		Color.GREEN,
		Color.YELLOW,
		Color.ORANGE,
		Color.PINK
		};
	
	public void paint(Graphics g){
		width = getWidth();
		height = getHeight();
		
		if(i < 6){
		//g.setColor(colors[i]);
		}else{
			i = 0;
		//g.setColor(colors[i+1]);	
		}
		
		g.setColor(colors[0]);	
		g.fillOval(x1, y1, size, size);
		g.setColor(colors[1]);	
		g.fillOval(x2, y2, size, size);

	}
	
	public void run(){
		while(true){
			
			try{
			Thread.sleep(30);
			if(fx1){
				x1 += speed;
				if(x1 > width - size - speed){
				fx1 = false;
				i++;
				}
			}else{
				x1 -= speed;
				if (x1 <= 0){
				fx1 = true;
				i++;
				}
			}
			
			if(fy1 ){
				y1 += speed;
				if(y1 > height - size - speed){
				fy1 = false;
				i++;
				}
			}else{
				y1 -= speed;
				if (y1 <= 0){
				fy1 = true;
				i++;
				}
			}
			
			if(fx2){
				x2 += speed;
				if(x2 > width - size - speed){
				fx2 = false;
				i++;
				}
			}else{
				x2 -= speed;
				if (x2 <= 0){
				fx2 = true;
				i++;
				}
			}
			
			if(fy2){
				y2 += speed;
				if(y2 > height - size - speed){
				fy2 = false;
				i++;
				}
			}else{
				y2 -= speed;
				if (y2 <= 0){
				fy2 = true;
				i++;
				}
			}
			
			
			//collision 1 top of 2
			if((y1 + size == y2 && (x2 >= x1 && x2 <= x1 + size)) || (y2 + size == y1  && (x2 >= x1 && x2 <= x1 + size))){
				fy1 = !fy1;
				fy2 = !fy2;
			}
			//More readable
			/*if(y2 + size == y1  && (x2 >= x1 && x2 <= x1 + size)){
				fy1 = !fy1;
				fy2 = !fy2;
			}*/
			
			if(x1 + size == x2 && (y2 >= y1 && y2 <= y1 + size)){
				fx1 = !fx1;
				fx2 = !fx2;
				//speed += 5;

			}
			if(x2 + size == x1 && (y1 >= y2 && y1 <= y2 + size)){
				fx1 = !fx1;
				fx2 = !fx2;

			//	speed += 5;
				}
			
			
			
			repaint();
			}catch(InterruptedException e){
				e.printStackTrace();
			}
			
		}
	}
	
}