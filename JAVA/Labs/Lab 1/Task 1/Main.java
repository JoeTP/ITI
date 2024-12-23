package mypkg;


class Main{
	
	public static void main(String[] args){
		
		if(args.length == 0){
		System.out.println("Hello Java");
		}else{
			System.out.print("Hello Java ");	
			for (int i = 0; i<args.length; i++){
				System.out.print(args[i] + " ");	
			}
			System.out.println();
		}
	}
}