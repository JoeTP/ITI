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

///GLOBAL & STATIC
int Employee::counter = 0;
Node *pTail;

///PROTOTYPE
Node* createNode(Employee e);
int push(Employee e);
Employee pop();
void printStack();
void clearStack();

int main(){
    int c;
    Employee e;
    bool validInput;
    do{
        cout<<"Choose operation"<<endl;
        cout<<"1-Push"<<endl;
        cout<<"2-Pop"<<endl;
        cout<<"3-Print Stack"<<endl;
        cout<<"4-Clear Stack"<<endl;
        cout<<"5-Quit"<<endl;
        cin>> c;
        if(c >=1){
            validInput = true;
        } else{
            cout<<"WRONG INPUT"<<endl;
            validInput = false;
        }
switch (c){
case 1:
    int id;
    char name[20];
    cout<<"Enter Employee's ID: ";
    cin>>id;
    cout<<"Enter Employee's Name: ";
    cin>>name;
    e.setId(id);
    e.setName(name);
    push(e);
    break;
case 2:{
    Employee epop = pop();
    cout<<endl<<"POPED"<<endl<<epop.getId()<<endl;
    cout<<epop.getName()<<endl<<endl;
    break;}
case 3:
    printStack();
    break;
case 4:
    clearStack();
    break;
    }
        }while(c != 5 && validInput );
    return 0;
}

Node* createNode(Employee e){
    Node* ptr = new (Node);
    if(ptr){
        ptr->employee = e;
        ptr->pPrev = NULL;
    }
    return ptr;
}

int push(Employee e){
    int ret = 0;
    Node *ptr = createNode(e);
    if(ptr){ //created node
        if(!pTail){ //no list
            pTail = ptr;
        } else{ //list exist
            ptr->pPrev = pTail;
            pTail = ptr;
        }
        ret = 1;
    }

    return ret;
}

Employee pop(){
    Employee e;
    Node *ptr;
    if(!pTail){ //no list
        char *n = "NO EMPLOYEE";
        e.setName(n);
    }else{
        ptr = pTail;
        pTail = ptr->pPrev;
        e.setId(ptr->employee.getId());
        e.setName(ptr->employee.getName());
        delete(ptr);
    }
    return e;
}

void printStack(){
    Node *ptr = pTail;
    if(pTail){ //list exist
        while(ptr){
        cout<<"-----"<<ptr->employee.getId()<<"-----"<<endl;
        cout<<"EMPLOYEE NAME: "<<ptr->employee.getName()<<endl;
        cout<<"EMPLOYEE ID: "<<ptr->employee.getId()<<endl<<endl;
        ptr = ptr->pPrev;
        }
    }
}

void clearStack(){
    Node *ptr;
        if(pTail){ //link exist
                //ptr = pTail;
            while(pTail){
                ptr = pTail;
                pTail = pTail->pPrev;
                delete(ptr);
            }
        cout<<"CLEARED STACK"<<endl;
        }
}




