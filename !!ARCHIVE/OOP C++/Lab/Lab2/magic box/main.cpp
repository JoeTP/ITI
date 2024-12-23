#include <iostream>
using namespace std;





int main (){

cout<<"PLAY MAGIC BOX"<<endl;
int s;
int row,col;

do{
cout<<"enter the box SIZE #MAKE SURE TO ENTER ODD NUMBER#"<<endl;
cin>>s;
} while(s%2 == 0 && s >1);

row = 1;
col = (s + 1)/2;

cout<<"Num = 1"<<"\t\t"<<"row = " <<row <<"\t\t"<<"column = "<<col<<endl;

for (int i = 2; i <= s*s; i++){
    if(((i-1)%s)!=0){
        row--;
        col--;
        if(row <1){
            row = s;
            }
        if(col<1){
            col = s;
            }
    cout<<"Num = "<<i<<"\t\t"<<"row = "<<row <<"\t\t"<<"column = "<<col<<endl;
    }else{
        row++;
        if (row >s){
            row = 1;
            }
    cout<<"Num = "<<i<<"\t\t"<<"row = "<<row <<"\t\t"<<"column = "<<col<<endl;
    }
}
return 0;
}
