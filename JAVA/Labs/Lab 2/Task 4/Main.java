import cmplx.Complex;
import java.util.StringTokenizer;

class Main{
	
	public static void main(String[] args){
		Complex comp = new Complex(5,2);
		//comp.add(2,2); //7 + 2i
		//comp.add(comp); //10 + 4i
		
		if(args.length > 0){
			if(args.length == 3){ //x + yi
				
				int r = Integer.parseInt(args[0]);
				int i = Integer.parseInt(args[2].split("i")[0]);
				
				comp.setReal(r);
				comp.setImagin(i);

			}else{ //x+yi 
			
			StringTokenizer st = new StringTokenizer(args[0]);
			while(st.hasMoreTokens()){
				comp.setReal(Integer.parseInt(st.nextToken("+")));
				comp.setImagin(Integer.parseInt(st.nextToken("i")));
			}
		
			}
			
		comp.printComplex();
		}
		else{
		comp.printComplex();
		}
		
	}
	
}