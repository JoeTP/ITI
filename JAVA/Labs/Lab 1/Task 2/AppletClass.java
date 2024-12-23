import java.applet.Applet;
import java.awt.Graphics;

public class AppletClass extends Applet{
	public void paint(Graphics g){
			String s = getParameter("test");
			g.drawString("Hello Java" + s,50,200);
		}
	}