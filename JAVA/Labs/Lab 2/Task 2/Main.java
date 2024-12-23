import java.lang.String;
import java.util.StringTokenizer;

class IPCutter {
	
	public static void main(String[] args){
		if(args.length > 0){
			System.out.println("USING SPLIT");
		String[] str = args[0].split("[.]");
		System.out.println("USING SPLIT");
		for(int i = 0; i< str.length; i++){
			System.out.println(str[i]);
		}
		
		System.out.println();
		
		System.out.println("USING STRING_TEKNOTIZER");
		StringTokenizer st = new StringTokenizer(args[0]);
		while (st.hasMoreTokens()) {
         System.out.println(st.nextToken("."));
     }
		
		
		System.out.println();
		
		System.out.println("USING SUBSTRING & INDEXOF");
		String subs = args[0];
		int start = 0;
		int end = subs.length();
		//int i = 1;
		// 123.345.765
		String x = subs;
		while(end > 0){
			end =  subs.indexOf(".", start);
			x = subs.substring(start, end < 0 ? subs.length() : end);
			System.out.println(x);
			start = subs.indexOf(".", start) + 1;
		}
		}else{
			System.out.println("ENTER IP!!");	
		}
	}
}
