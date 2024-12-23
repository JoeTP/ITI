import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;




public class Main extends Applet{
	

	
		Line line;
		int x;
		int y;
		boolean lineDrawed = false;
	
		public void init(){
			
			this.addMouseListener(new MouseAdapter(){
			public void mousePressed(MouseEvent e){
				x = e.getX();
				y = e.getY();
				line.xs = x;
				line.ys = y;
			}
			
		});
			
			this.addMouseMotionListener(new MouseMotionAdapter(){
					
			public void mouseDragged(MouseEvent e){
				line.xe = e.getX();
				line.ye = e.getY();
				lineDrawed = true;
				repaint();
				}
			});
			
			line = new Line();
			
	}
	
	public void paint(Graphics g){
		g.drawString("Xs: " + line.xs + " Ys: " + line.ys ,getWidth()/2,getHeight()/2);
		g.drawString("Xe: " + line.xe + " Ye: " + line.ye ,getWidth()/2,getHeight()/2+40);
	if(lineDrawed) g.drawLine(line.xs,line.ys,line.xe,line.ye);
	}
	
	
}

 class Line {
	public int xs;
	public int ys;
	public int xe;
	public int ye;
	
	public Line (){
		 this.xs = 0;
		 this.ys = 0;
		 this.xe = 0;
		 this.ye = 0;
	}
	
	public Line (int x1, int y1, int x2, int y2){
		 this.xs = x1;
		 this.ys = y1;
		 this.xe = x2;
		 this.ye = y2;
	}
}