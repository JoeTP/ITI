import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;



public class Main extends Applet{
	

	
		ArrayList<Line> lines;
		int currline = 0;
		int x1;
		int y1;
		int x2;
		int y2;
	
		public void init(){
			lines = new ArrayList<Line>();
			
			this.addMouseListener(new MouseAdapter(){
			public void mousePressed(MouseEvent e){
					x1 = e.getX();
					y1 = e.getY();
			}
			
					
			public void mouseReleased(MouseEvent e){
					
					Line line = new Line();
					line.xe = e.getX();
					line.ye = e.getY();
					line.xs = x1;
					line.ys = y1;
					
					if(e.getX() != x1 && e.getY() != y1){
					lines.add(line);
					repaint();
					}
				}
			});
			
			this.addMouseMotionListener(new MouseMotionAdapter(){
			public void mouseDragged(MouseEvent e){
				x2 = e.getX();
				y2 = e.getY();
				
				repaint();
			}
			
		});	
	}
	
	public void paint(Graphics g){
		
		g.drawLine(x1,y1,x2,y2);
	for(Line line : lines){
		g.drawLine(line.xs,line.ys,line.xe,line.ye);
		}	
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