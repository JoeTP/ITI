import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;




public class Main extends Applet{
	

	
		Line[] lines= new Line[3];
		int currline = 0;
		int x;
		int y;
	
		public void init(){
			for (int i = 0; i < 3; i++) {
            lines[i] = new Line(); 
			}
			
			this.addMouseListener(new MouseAdapter(){
			public void mousePressed(MouseEvent e){
				if(currline < 3){
					lines[currline].xs = e.getX();
					lines[currline].ys = e.getY();
				}else{
					lines[2].xs = e.getX();
					lines[2].ys = e.getY();
				}
			}
			
			
			public void mouseReleased(MouseEvent e){
				if(currline < 3){
					lines[currline].xe = e.getX();
					lines[currline].ye = e.getY();
					currline++;
				}else{
					lines[2].xe = e.getX();
					lines[2].ye = e.getY();
				}
			}
		});
			
			this.addMouseMotionListener(new MouseMotionAdapter(){
			public void mouseDragged(MouseEvent e){
				if(currline < 3){
				lines[currline].xe = e.getX();
				lines[currline].ye = e.getY();
				repaint();
				}else{
				lines[2].xe = e.getX();
				lines[2].ye = e.getY();
				repaint();
				}
			}
		});	
	}
	
	public void paint(Graphics g){
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