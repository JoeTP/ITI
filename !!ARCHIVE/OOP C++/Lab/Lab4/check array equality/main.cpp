#include <iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

int main(){

char w1 [10];
char w2 [10];
int compare;
int i = 0;
do{
cout<<"enter first word"<<endl;
cin>>w1;
cout<<"enter second word"<<endl;
cin>>w2;
compare = strcmp(w1,w2);
if(compare){
    cout<<"THEY ARE DIFFERENT"<<endl;
}else{
    cout<<"THEY ARE THE SAME"<<endl;
}
i++;
} while (i <20);
return 0;
}
