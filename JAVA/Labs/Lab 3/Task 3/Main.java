
import java.applet.Applet;
import java.awt.*;


public class Main extends Applet{
	
	public void paint(Graphics g){
		int shiftX = 50;
		int shiftY = 70;
		//LINE 1
		int l1x1 = 200;
		int l1y1 = 50 + shiftY;
		int l1x2 = 100;
		int l1y2 = 400 + shiftY;
		//LINE 2
		int l2x1 = 600; //o1Width + l1x1 = 600
		int l2y1 = 50 + shiftY; //l1y1
		int l2x2 = 700; //l1x1 + o1Width = 300
		int l2y2 = 400 + shiftY; //l1y2 = 400
		
		
		//drawOval
		//OVAL 1 TOP
		int o1x1 = 200; //l1x1 = 200
		int o1y1 = 0 + shiftY;
		int o1Width = 400;
		int o1Height = 100;
		//OVAL 2 CENTER CENTER
		int o2x1 = 330; //o1Width/2 + l1x1 - o2Width = 200 + 200 - 100 = 300
		int o2y1 = 150 + shiftY;
		int o2Width = 140;
		int o2Height = 240;
		//OVAL 3 CENTER LEFT
		int o3x1 = 200; // 
		int o3y1 = 200 + shiftY; //o1Height + (o2Height/2) + 20 = 100 + 100 +20 = 220
		int o3Width = 80;
		int o3Height = 140;
		//OVAL 4 CENTER RIGHT
		int o4x1 = 520; //l1x1 + o1Width - 100 = 200+400-100 = 500 
		int o4y1 = o3y1; // 
		int o4Width = 80;
		int o4Height = 140;
		//ARC
		int ax = 100;
		int ay = 330 + shiftY;
		int aWidth = 600;
		int aHeight = 140;
		int aStartAngel = 0;
		int aEndAngel = -180;
		//LINE 3
		int l3x1 = 350; //the half distance is 400 (shifted -50)
		int l3y1 = 470 + shiftY;
		int l3x2 = 300;
		int l3y2 = 670 + shiftY;
		//LINE 4
		int l4x1 = 450; //the half distance is 400 (shifted +20)
		int l4y1 = 470 + shiftY;
		int l4x2 = 490;
		int l4y2 = 670 + shiftY;
		//RECT
		int rx = 200;
		int ry = 670 + shiftY;
		int rWidth = 400;
		int rHeight = 90;
		
		g.drawLine(l1x1,l1y1,l1x2,l1y2);
		g.drawLine(l2x1,l2y1,l2x2,l2y2);
		g.drawOval(o1x1,o1y1,o1Width,o1Height);
		g.drawOval(o2x1,o2y1,o2Width,o2Height);
		g.drawOval(o3x1,o3y1,o3Width,o3Height);
		g.drawOval(o4x1,o4y1,o4Width,o4Height);
		g.drawArc(ax,ay,aWidth,aHeight,aStartAngel,aEndAngel);  
		g.drawLine(l3x1,l3y1,l3x2,l3y2);
		g.drawLine(l4x1,l4y1,l4x2,l4y2);
		g.drawRect(rx,ry,rWidth,rHeight);
		g.setColor(Color.YELLOW);
		g.fillOval(o1x1+1,o1y1+1,o1Width-1,o1Height-1);
		g.fillOval(o2x1+1,o2y1+1,o2Width-1,o2Height-1);
		g.fillOval(o3x1+1,o3y1+1,o3Width-1,o3Height-1);
		g.fillOval(o4x1+1,o4y1+1,o4Width-1,o4Height-1);
		
	}
	
}