#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <cmath>
using namespace std;

COORD coord = {0,0};
void gotoxy(int x, int y){
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int sum(int num1,int num2);
int sub(int num1, int num2);
double divide(double num1, double num2);
int multiplication (int num1, int num2);
double power(int num1, int num2);
double powerRecursion(int num1, int num2);
void printMenu();

int main(){

int col = 0;
int row = 0;
char ch;
int selector;

int num1;
int num2;

printMenu();

gotoxy(col,row);
do{
ch = getch();
if(ch == -32){
    ch = getch();
    //down arrow
if(ch == 80){
    row++;
    if(row > 6){
            row = 6;
    }

    gotoxy(col,row);
}
    //up arrow
if(ch == 72){
        row--;
    if(row < 0){
            row = 0;
    }
        gotoxy(col,row);
}
}

if(ch == 13){
        selector = row;
        system("cls");
        switch (selector) {
case 1:
    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;
    cout<<"Summation: "<<num1<< " + " << num2<< " = " << sum(num1,num2)<<endl<<endl;
cout<<"Press enter to do another operation)"<<endl;
system("pause");
system("cls");
printMenu();
gotoxy(0,1);
    break;
case 2:
    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;
    cout<<"Subtraction: "<<num1<< " - " << num2<< " = " << sub(num1,num2)<<endl<<endl;
    cout<<"Press enter to do another operation)"<<endl;
system("pause");
system("cls");
gotoxy(0,2);
printMenu();
    break;
case 3:

    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;
    cout<<"Multiplication: "<<num1<< " * " << num2<< " = " << multiplication(num1,num2)<<endl<<endl;
    cout<<"Press enter to do another operation)"<<endl;
system("pause");
system("cls");
printMenu();
gotoxy(0,3);
    break;
case 4:
    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;cout<<"Division: "<<num1<< " / " << num2<< " = " << divide(num1,num2)<<endl<<endl;
    cout<<"Press enter to do another operation)"<<endl;
system("pause");
system("cls");
printMenu();
gotoxy(0,4);
    break;

case 5:
    cout<<"Enter First Number"<<endl;
    cin>>num1;
    cout<<"Enter Second Number"<<endl;
    cin>>num2;
    power(num1,num2);
    cout<<"Power: "<<num1<< "^" << num2<< " = " << power(num1,num2)<<endl<<endl;
    cout<<"Press enter to do another operation)"<<endl;
system("pause");
system("cls");
printMenu();
gotoxy(0,5);
    break;
case 6 :
    cout<<"Exit is Pressed"<<endl;
    cout<<"========================"<<endl<<endl;
    system("pause");
    return 0;
    break;

}
        }

} while (selector !=6);




return 0;
}


void printMenu(){
cout<<"Summation"<<endl;
cout<<"Subtraction"<<endl;
cout<<"Multiplication"<<endl;
cout<<"Division"<<endl;
cout<<"Power"<<endl;
cout<<"Exit";
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

double power(int num1, int num2){
double result = 1;
for(int i = 1; i <= num2; i++){
result *= num1;
}
return result;
}

// 4^4 = 4 * (4)^3
double powerRecursion(int num1, int num2){
double result = 1;
if(num2 == 0){
    return result;
} else {
    result = num1 * powerRecursion(num1, num2 -1);
}


return result;
}
