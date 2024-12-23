package cmplx;


public class Complex{
	private int real;
	private int imagin;
	
	public Complex(){}
	
	public Complex(int r, int i){
		real = r;
		imagin = i;
	}
	
	public void setReal(int d){
		real = d;
	}
	public void setImagin(int d){
		imagin = d;
	}
	
	public int getReal(){return real;}
	public int getImagin(){return imagin;}
	
	public void add(Complex c1){
		this.real += c1.getReal();
		this.imagin += c1.getImagin();
	}
	
	
	public void add(int real, int imagin){
		this.real += real;
		this.imagin += imagin;
	}
	
	public static Complex add(Complex c1, Complex c2){
		Complex c = new Complex(c1.real + c2.real, c2.imagin + c2.imagin);
		printComplex() ;
		return c;
	}
	
	public void printComplex(){
		System.out.println(this.real + " + " + this.imagin + "i");
	}
}