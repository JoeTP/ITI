#include <iostream>
#include<string.h>
#include<ctype.h>
#include <iomanip>
using namespace std;


int main (){

char sub1[] = {"Mth"};
char sub2[] = {"Arb"};
char sub3[] = {"Eng"};
char sub4[] = {"Sci"};
char sumCh[] = {"SUM"};
double degrees[3][4];
double sumAr[3] = {0};
double avgAr[4] = {0};


//fill degrees of students
for (int j =0; j <3; j++){
    cout<<"Enter Student "<<j+1<<" Degrees"<<endl;
    for (int i = 0; i < 4 ;i++){
    cin>>degrees[j][i];
    }
}


//get SUM
for (int row =0; row <3; row++){
    for (int col = 0; col < 4 ;col++){
    sumAr[row] += degrees[row][col];
    }
}

//get Avg
for (int col =0; col <4; col++){
    for (int row = 0; row < 3 ;row++){
    avgAr[col] += degrees[row][col]/3;
    }
}

//results
cout<<endl<<"_____________________________________"<<endl;
cout<<sub1<<"\t"<<sub2<<"\t"<<sub3<<"\t"<<sub4<<"\t"<<sumCh<<endl;
for (int row = 0; row < 3; row++){
    for(int col = 0; col <4; col++){
        cout<<degrees[row][col]<<"\t";
        if(col == 3){
            cout<<"| "<<sumAr[row];
        }
    }
    cout<<endl;
}
cout<<"_______________AVG______________"<<endl;
for (int row = 0; row < 4; row++){
        cout<<avgAr[row]<<"\t";
}
    cout<<endl;


return 0;
}









