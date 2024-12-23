#include <iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

int main(){

char word [10];
char rev [10];
char temp [10];
cout<<"enter word"<<endl;
cin>>word;
int i = 0;
while(word[i] !='\0'){
    i++;
}
for(int j = 0; j<= i; j++){
        while(i>=0){
            rev[j] = word[i];
            i--;
    cout<<rev[j];
        }
}
return 0;
}
