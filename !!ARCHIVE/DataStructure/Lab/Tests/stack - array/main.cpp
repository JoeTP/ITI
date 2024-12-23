#include <iostream>
#include <string.h>
using namespace std;

class Person{
    char name[20];
public:
    Person(){
    strcpy(name, "");
    }

    Person(char *n){
        strcpy(name,n);
    }

    void setName(char *n){strcpy(name,n);}

    char* getName(){return name;}
};

int tos;
Person *ar = new Person[5];


int push(Person person);
Person pop();
void print();
void clearStack();

int main()
{
    int c;
    do{
        cout<<"1-push"<<endl;
        cout<<"2-pop"<<endl;
        cout<<"3-print"<<endl;
        cout<<"4-clear"<<endl;
        cout<<"5-quit"<<endl;
        cin>>c;

        switch(c){
        case 1:{
        char name[20];
        cout<<"ENTER NAME: ";
        cin>>name;
        Person pers;
        pers.setName(name);
        int check = push(pers);
        if(check){
            cout<<"PUSHED SUCCESS"<<endl;
        }else{
            cout<<"PUSHED FAILED, STACK FULL OR NO MEMORY"<<endl;
        }
        break;
        }
        case 2:{
            Person pers = pop();
            cout<<pers.getName()<<endl;

            break;
         }
        case 3:
            print();
            break;
        case 4:
            clearStack();
        }
    }while(c !=5);


    return 0;
}

int push(Person person){
    int ret = 0;
    if(tos < 5){
        ret = 1;
        ar[tos] = person;
        tos++;
    }
        return ret;
}
Person pop(){
    Person pers;
    if(tos > 0){
        tos--;
        pers = ar[tos];
    }else{
    cout<<"NOTHING TO POP"<<endl;
    }
    return pers;
}

void print(){
    for (int i = 0; i < tos; i++){
        cout<<i<<": "<<ar[i].getName()<<endl;
    }
}

void clearStack(){
    tos = 0;
    delete[] ar;
}



















