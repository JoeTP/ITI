#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    cout<<"Calculating max and min values of five numbers"<<endl;
    int max, min;
    int n1,n2,n3,n4,n5;

    cout<<"Enter list of numbers"<<endl;
    cin>> n1; cin>> n2; cin>> n3; cin>> n4; cin>> n5;
    max = min = n1;
    if (n2>=max) max = n2;
    if (n3>=max) max = n3;
    if (n4>=max) max = n4;
    if (n5>=max) max = n5;

    if (n2<=min) min = n2;
    if (n3<=min) min = n3;
    if (n4<=min) min = n4;
    if (n5<=min) min = n5;


    cout<<"max value = " <<max<<endl;
    cout<<"min value = "<<min<<endl;

    cout<<endl;
    cout<<"====================================="<<endl;
    cout<<"CALCULATING MAX AND MIN"<<endl;
    cout<<"=============USING LOOP=============="<<endl;
    cout<<endl;
    cout<<"Enter list of numbers"<<endl;

    int n;
    cin>>n;
    max = n;
    min = n;
    for(int i =1; i<=4; i++){
        cin>>n;
        if(n>=max){
            max = n;
        }else{
            if(min>n){
                min = n;
            }
        }
    }
    cout<<"max value = " <<max<<endl;
    cout<<"min value = "<<min<<endl;

    return 0;
}



