

class Calc {
	
	public static void main (String[] args){
		double n1 = Integer.parseInt(args[0]);
		String c = args[1];
		double n2 = Integer.parseInt(args[2]);
		double res;
		switch(c){
			case "+": {
				res = n1+n2;
				System.out.println(res);
				break;
			}
			case "-":{
				res = n1-n2;
				System.out.println(res);
				break;
			}
			case "x":{
				res = n1*n2;
				System.out.println(res);
				break;
			}
			case "/":{
				if(n2 == 0){
				System.out.println("UNDIFINED");
				}else{
				
				System.out.println(n1/n2);
				}
				break;
			}
			default:{
				System.out.println("Undifined Operator");
				break;
			}
		}
	}
	
}