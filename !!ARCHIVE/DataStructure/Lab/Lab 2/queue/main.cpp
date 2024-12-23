#include <iostream>
#include <string.h>

using namespace std;


class Employee{
    int id;
    char name[20];
    static int counter;
public:
    Employee(){
        id = 0;
        name[20] = {0};
        counter++;
    }
    Employee(int i, char *n){
    id = i;
    strcpy(name, n);
    }

    void setName(char *n){
        strcpy(name, n);
    }

    void setId(int id){
    this->id = id;
    }

    char* getName(){return name;}
    int getId(){return id;}
};

struct Node{
    Employee employee;
    Node *pPrev;
};

///GLOBALS
int q;
Employee ar[100];
int Employee::counter = 0;

///PROTOTYPE
int enQueue(Employee e);
Employee deQueue();
void printQueue();
void clearQueue();

int main()
{
    int c;
    bool validInput;
    Employee e;
    do{
        cout<<"Choose operation"<<endl;
        cout<<"1-EnQueue"<<endl;
        cout<<"2-DeQueue"<<endl;
        cout<<"3-Print Queue"<<endl;
        cout<<"4-Clear Queue"<<endl;
        cout<<"5-Quit"<<endl;
        cin>> c;
        if(c >=1){
            validInput = true;
        } else{
            cout<<"WRONG INPUT"<<endl;
            validInput = false;
        }
switch (c){
case 1:{
    char name[20];
    int id;
    cout<<"Enter Employee's ID: ";
    cin>>id;
    cout<<"Enter Employee's Name: ";
    cin>>name;
    Employee e(id,name);
    enQueue(e);
    break;
}
case 2:{
    Employee eDeq = deQueue();
    Employee e(eDeq.getId(),eDeq.getName());
    cout<<endl<<"DEQUEUED"<<endl<<"ID: "<<e.getId()<<endl<<"NAME: "<<e.getName()<<endl<<endl;
    break;
    }
case 3:
    printQueue();
    break;
case 4:
    clearQueue();
    break;
        }
        }while(c != 5 && validInput );
    return 0;
}

Employee deQueue(){
    Employee e;
    if(q >0){
        q--;
        e.setId(ar[0].getId());
        e.setName(ar[0].getName());
        for (int i = 0; i <q; i++){
            ar[i] = ar[i+1];
        }
    } else{
    e.setId(0);
    e.setName("NO NAME");
    }
    return e;
}

int enQueue(Employee e){
    int ret = 0;
    if(q < 100){
    ret = 1;
    ar[q].setId(e.getId());
    ar[q].setName(e.getName());
    q++;
    }
    return ret;
}

void printQueue(){
    if(!q){
        cout<<endl<<"NO QUEUE FOUND"<<endl<<endl;
    }
    for(int i =0; i<q; i++){
        cout<<"----"<<i<<"----"<<endl;
        cout<<"Employee's ID: "<<ar[i].getId()<<endl;
        cout<<"Employee's Name: "<<ar[i].getName()<<endl<<endl;
    }
}

void clearQueue(){
    if(q<0){
        for (int i = 0; i <= q; i++){
        deQueue();
    }
    cout<<"CLEARED QUEUE"<<endl;
    }
}
