
#include <iostream>
#include <cmath>
using namespace std;


int sum(int num1,int num2);
int sub(int num1, int num2);
double divide(double num1, double num2);
int multiplication (int num1, int num2);
int power(int num1, int num2);


int main(){

int selector;
int num1;
int num2;
do{
cout<<"Choose from list"<<endl;
cout<<"1- Summation"<<endl;
cout<<"2- Subtraction"<<endl;
cout<<"3- Multiplication"<<endl;
cout<<"4- Division"<<endl;
cout<<"5- Power"<<endl;
cout<<"6- Exit"<<endl;
cin>>selector;

switch (selector) {
case 1:
    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;
    cout<<"Summation: "<<num1<< " + " << num2<< " = " << sum(num1,num2)<<endl<<endl;
    break;
case 2:
    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;
    cout<<"Subtraction: "<<num1<< " - " << num2<< " = " << sub(num1,num2)<<endl<<endl;
    break;
case 3:

    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;
    cout<<"Multiplication: "<<num1<< " * " << num2<< " = " << multiplication(num1,num2)<<endl<<endl;
    break;
case 4:
    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;cout<<"Division: "<<num1<< " / " << num2<< " = " << divide(num1,num2)<<endl<<endl;
    break;

case 5:
    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;
    power(num1,num2);
    cout<<"Power: "<<num1<< "^" << num2<< " = " << power(num1,num2)<<endl<<endl;
    break;
default :
    cout<<"Exit is Pressed"<<endl;
    cout<<"========================"<<endl<<endl;
    system("pause");
    return 0;
}
} while (selector >=0 && selector <7);


return 0;
}


int sum(int num1, int num2){
int result;
result = num1 + num2;
return result;
}

int sub(int num1, int num2){
int result;
result = num1 - num2;
return result;
}

double divide(double num1, double num2){
double result;
if(num2 == 0) {
    cout<<"UNDEFINE VALUE"<<endl;
} else{
result = num1 / num2;
}
return result;
}


int multiplication (int num1, int num2){
int result;
result = num1 * num2;
return result;
}

int power(int num1, int num2){
int result = 1;
for(int i = 1; i <= num2; i++){
num1 *= num1;
result = num1;
}
return result;
}
