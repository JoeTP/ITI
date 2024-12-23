import java.applet.Applet;
import java.util.Random;
import java.awt.*;
import java.awt.event.*;




public class Main extends Applet{
	
	int x = 0;
	int y = 0;
	int size = 50;
	int xOval;
	int yOval;
	Random rand;
	
	public void init(){
		rand = new Random();
		
		xOval = rand.nextInt(getWidth()- size);
		yOval = rand.nextInt(getHeight() - size);
		
		this.addMouseMotionListener(new MouseMotionAdapter(){
		public void mouseDragged(MouseEvent e){
			x = e.getX();
			y = e.getY();
			
		
		if (x >= xOval && x <= xOval + size && y >= yOval && y <= yOval + size) {
			xOval = x - size /2;
			yOval = y - size /2;
		}
			repaint();
		}
	});
}
	
	public void paint(Graphics g){
		
		
		g.fillOval(xOval , yOval, size, size);
		g.drawString("X: " + x + " " +"Y: " + y + " " , getWidth()/2,getHeight()/2);
	}
}