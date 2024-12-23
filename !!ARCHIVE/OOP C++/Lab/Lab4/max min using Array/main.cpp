#include <iostream>

using namespace std;


int main()
{
    int ar[5];
    int maxV;
    int minV;
    cout<<"Enter five numbers to get their max, min values"<<endl;
    for (int i = 0; i<5; i++){
        cin>>ar[i];

    }
    //get max and min
    maxV = minV = ar[0];
    for(int j = 1; j <=5; j++){
        if(ar[j] >= maxV){
            maxV = ar[j];
        }
        if(ar[j] <= minV){
            minV = ar[j];
        }
    }
        cout<<"MAX = "<<maxV<<endl;
        cout<<"MIN = "<<minV<<endl;

    return 0;
}
