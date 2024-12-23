

class Stars{
	
	public static void main (String[] args){
		
		if(args.length != 0){
		int count = Integer.parseInt(args[0]);
		for(int i = 0; i <= count; i++){

			String x =  new String(new char[i]).replace("\0", "*");
			String space = new String (new char[2*(count - i)]).replace("\0", " ");	
			String y =  new String(new char[i]).replace("\0", "* ");
			System.out.println(x + "  "+  space + y);
			}
		}else{
			System.out.println("ENTER A NUMBER!!");
		}
	}
	
}