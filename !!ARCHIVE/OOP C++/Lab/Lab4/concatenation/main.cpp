#include <iostream>

using namespace std;

int main (){
char fName [10];
char lName [10];
char fullName [20];

cout<<"enter First Name"<<endl;
cin>>fName;
cout<<"enter Last Name"<<endl;
cin>>lName;
strcpy(fullName,fName);
strcat(fullNmae,lName);
cout<<fullName<<endl;

return 0;
}
