#include <iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

int main(){
char word[10];
cout<<"enter a word"<<endl;
cin>>word;
int i = 0;
while(word[i] !='\0'){
    i++;
}
cout<<"the length = "<<i<<endl;
return 0;
}
