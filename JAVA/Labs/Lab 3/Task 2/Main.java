
import java.applet.Applet;
import java.awt.*;

public class Main extends Applet{
	
	GraphicsEnvironment ge;
	String[] fontList;
	
	public void init(){
		ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
		fontList = ge.getAvailableFontFamilyNames();
	}
	
	public void paint(Graphics g){
			
		for(int i = 0; i < fontList.length; i++){
			Font font = new Font(fontList[i], Font.BOLD, 24);
			g.setFont(font);
			g.drawString(fontList[i],50,50+(i*25));
		}
	}
}