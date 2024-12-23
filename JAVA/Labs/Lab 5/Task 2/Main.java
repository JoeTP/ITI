import java.applet.Applet;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;


public class Main extends Applet{
	
	int x;
	int y;
	
	public void init(){
		x = getWidth()/2;
		y = getHeight()/2;
	
	
		this.addKeyListener(new KeyAdapter(){
        public void keyPressed(KeyEvent e) {
			
			switch(e.getKeyCode()) {
                case KeyEvent.VK_UP: {
					if(y >= 0){
						y -= 5;
					}else{
						y = getHeight();
					}
                    break;
                }
                case KeyEvent.VK_DOWN: {
					if(y <= getHeight()){
						y += 5; 
					}else{
						y = 0;
					}
                    break;
                }
                case KeyEvent.VK_RIGHT: {
					if(x >= getWidth()){
						
						x = 0;
					}else{
						x += 5;
					}
                    break;
                }
                case KeyEvent.VK_LEFT: {
                    if(x >= 0){
						x -= 5;
					}else{
						x = getWidth();
					}
                    break;
                }
            }
			repaint();
			}
		});
	}
	
	
	public void paint(Graphics g){
	
		
		g.drawString("JAVA", x, y);
	}
}