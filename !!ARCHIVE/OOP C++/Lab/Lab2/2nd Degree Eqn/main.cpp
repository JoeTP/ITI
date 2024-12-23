#include <iostream>
#include <cmath>
using namespace std;



int main (){

cout<<"Solving Second equation"<<endl;
cout<<"Enter Equation Coefficients"<<endl;
cout<<"ax^2 + bx + c"<<endl;
double a,b,c;
double x1,x2;
double dim;
cin>>a; cin>>b; cin>>c;
//f(x) = ax^2 + bx + c
//dim = b^2 - 4ac

dim = (b*b) - (4*a*c);

if(dim>0) {
    x1= (-b+sqrt(dim))/(2*a);
    x2= (-b-sqrt(dim))/(2*a);
        cout<<"X1 = "<<x1<<"\t"<<"X2 = "<<x2<<endl;

}
else if(dim == 0) {
        x1=x2 = -b/(2*a);
    cout<<"X1 = "<<x1<<"\t\t"<<"X2 = "<<x2<<endl;
}
else {cout<<"IMAGINARY SOLUTION"<<endl;}

return 0;
}



