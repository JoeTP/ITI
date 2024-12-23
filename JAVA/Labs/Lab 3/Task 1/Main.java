
import java.applet.Applet;
import java.awt.*;

public class Main extends Applet{
	Toolkit tk;
	String[] fontList;
	
	public void init(){
		tk = Toolkit.getDefaultToolkit();
		fontList = tk.getFontList();
	}
	
	public void paint(Graphics g){
			
		for(int i = 0; i < fontList.length; i++){
			Font font = new Font(fontList[i], Font.PLAIN, 15);
			g.setFont(font);
			g.drawString(fontList[i],50,50+(i*45));
		}
	}
}