#include <iostream>

using namespace std;

int main(){

int selector;

do{
cout<<"Choose from list"<<endl;
cout<<"1- File"<<endl;
cout<<"2- Edit"<<endl;
cout<<"3- Save"<<endl;
cout<<"4- Exit"<<endl;
cin>>selector;

switch (selector) {
case 1:
    cout<<"File is Pressed"<<endl;
    cout<<"========================"<<endl<<endl;
    break;
case 2:
    cout<<"Edit is Pressed"<<endl;
    cout<<"========================"<<endl<<endl;
    break;
case 3:

    cout<<"Save is Pressed"<<endl;
    cout<<"========================"<<endl<<endl;
    break;
default :
    cout<<"Exit is Pressed"<<endl;
    cout<<"========================"<<endl<<endl;
    system("pause");
    return 0;
}
} while (selector >=0 && selector <5);


return 0;
}
