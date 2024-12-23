#include <iostream>
#include <string.h>

using namespace std;


///(-1) is the indication of fail
///(1) is the indication of Success
///addNode function will add at the last of the linked list

class Employee{
    int id;
    char name[20];
public:
    Employee(){
        id = 0;
        name[20] = {0};
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
    Node *pNext, *pPrev;
};

///GLOBAL VARs
Node *pHead, *pTail;

///FUNCTION PROTOTYPES
Employee fillEmployee();
Node* createNode(Employee e);
int addNode(Employee e);
void printAll();
void freeList();
int searchById(int id);
int searchByName(char *name);
int deleteByLoc(int loc);
int switchCase(int c);
int insertNode(int loc,Employee e);
///////////////////////

int main()
{
    int c;
    Employee e;

    do{
        cout<<"Choose operation"<<endl;
        cout<<"1-Add Node"<<endl;  //DONE
        cout<<"2-Insert Node"<<endl;
        cout<<"3-Print All Nodes"<<endl; //DONE
        cout<<"4-Search by ID"<<endl; //DONE
        cout<<"5-Search by Name"<<endl; //DONE
        cout<<"6-Delete Node"<<endl; //DONE
        cout<<"7-Free List"<<endl; //DONE
        cout<<"8-Quit"<<endl; //DONE
       //choose = switchCase();
           cin>> c;
    switch (c) {
case 1:
   addNode(e);
    break;
case 2:{
    int loc;
    char name[20];
    int id;
    cout<<"Enter Node Location: "<<endl;
    cin>>loc;
    cout<<"Enter Employee's ID: "<<endl;
    cin>>id;
    cout<<"Enter Employee's Name: "<<endl;
    cin>>name;
    e.setId(id);
    e.setName(name);
    insertNode(loc,e);
    break;
    }
case 3:
    printAll();
    break;
case 4:
    int myId;
    cout<<"Enter id to search: ";
    cin>>myId;
    searchById(myId);
    break;
case 5:
    char myName[20];
    cout<<"Enter name to search: ";
    cin>>myName;
    searchByName(myName);
    break;
case 6:{
    cout<<"Enter Node Location: ";
    int loc;
    cin>>loc;
    deleteByLoc(loc);
    break;}
case 7:
    freeList();
    break;
case 8:
    c = 8;

    }
}while(c != 8 );

    return 0;
}

Employee fillEmployee() {
    int id;
    char name[20];
    Employee e;
    cout<<"Enter ID: ";
    cin>> id;
    cout<<"Enter Name: ";
    cin>> name;
    e.setId(id);
    e.setName(name);
    return e;
}

Node* createNode(Employee e){
    Node *ptr = new (Node);
if(ptr){
    ptr->employee = e;
    ptr->pNext = NULL;
    ptr->pPrev = NULL;
}
return ptr;
}

int addNode(Employee e){
int ret = -1;
Employee emp = fillEmployee();
Node *ptr = createNode(emp);
if(ptr){
    cout<<"CREATED SUCCESS"<<endl;
    ret = 1;
    if(!pHead){ //no list
        pHead = pTail = ptr;
    cout<<"NO LIST"<<endl;
    } else{ //there is list
        pTail->pNext = ptr;
        ptr->pPrev = pTail;
        pTail = ptr;

    cout<<"ADDED AT TAIL OF LIST"<<endl;
    }
}
return ret;
}

void printAll(){
    Node *ptr = pHead;
    int counter = 1;
    if(pHead){
    while(ptr){
        cout<<"-----"<<counter<<"-----"<<endl;
        cout<<"ID "<<ptr->employee.getId()<<endl;
        cout<<"Name "<<ptr->employee.getName()<<endl;
        counter++;
        ptr = ptr->pNext;
    }
    }
    else{
        cout<<"NO LIST FOUND"<<endl;
    }
}

void freeList(){
    Node *ptr ;
    while(pHead){
        ptr = pHead;
        pHead = pHead->pNext;
        delete(ptr);
    }
    pTail = NULL;
    cout<<"FREED LIST"<<endl;
}

int searchById(int id){
    int ret = -1;
    Node *ptr = pHead;
    while(ptr){
        if(ptr->employee.getId() != id){ //not found
            ptr = ptr->pNext;
        } else{ //found
        ret = 1;
        delete(ptr);
        }
    }
    if(ret == 1){cout<<"FOUND"<<endl;}
    else {cout<<"NOT FOUND"<<endl;}
    return ret;
}

int searchByName(char *name){
    int ret = -1;
    Node *ptr = pHead;
    while(ptr){
        if(strcmp(ptr->employee.getName(),name) == 0){ //found
        ret = 1;
        delete(ptr);
        } else{ //not found
        ptr = ptr->pNext;
        }
    }
    if(ret == 1){cout<<"FOUND"<<endl;}
    else {cout<<"NOT FOUND"<<endl;}
    return ret;
}

int deleteByLoc(int loc){
    int ret = -1;
    Node *ptr;
    if(pHead){ //there is list
        ptr = pHead;
        if(loc == 0){ //delete 1st node
          //if only 1 node, if more than 1 node
          if(pHead->pNext == NULL){
            pHead = pTail = NULL;
          }else {
            pHead->pNext->pPrev = NULL;
            pHead = pHead->pNext;
            }
            delete (ptr);
            ret =1;
        } else{ //not 1st location
            for (int i = 0; i<loc && ptr; i++){ptr = ptr->pNext;} //reach destination
                if(ptr){ //location within boundries
                    if(ptr == pTail){ //deleting last node
                        pTail->pPrev->pNext = NULL;
                        pTail = pTail->pPrev;
                        pTail->pNext = NULL;
                      } else { //deleting middle node
                        ptr->pPrev->pNext = ptr->pNext;
                        ptr->pNext->pPrev = ptr->pPrev;
                    }
                }
            delete(ptr);
            ret = 1;
            }
        }

    return ret;
}

//insert at loc = 0
//insert at  0 < loc < last
//insert at loc = last
int insertNode(int loc, Employee e){
 int ret = 0;
 Node *ptr = createNode(e);
 Node *pTemp;
if(ptr){
    if(loc == 0) { //put at 1st location
    if(pHead){ //if there is list
        pHead->pPrev = ptr;
        ptr->pNext = pHead;
        pHead = ptr;
    } else{
        pHead = pTail = ptr;
    }
    ret = 1;
 }
 else{ //put at middle / last location
     if(!pHead){//if NO list
        pHead = pTail = pTemp = ptr;
     }else{
        pTemp = pHead;
     for(int i =0; i < loc-1 && pTemp; i++){
        pTemp = pTemp->pNext;
     }
     if(pTemp == pTail){ //last node
        pTail->pPrev->pNext = ptr;
        ptr->pNext = pTail;
        ptr->pPrev = pTail->pPrev;
        pTail->pPrev = ptr;
     }
     if(!pTemp){//adding after tail
        pTail->pNext = ptr;
        ptr->pPrev = pTail;
        pTail = ptr;
        }
     else{ // add middle
        ptr->pNext = pTemp;
        ptr->pPrev = pTemp->pPrev;
        ptr->pPrev->pNext = ptr;
        pTemp->pPrev = ptr;
        }
     }
     }
     ret = 1;
    }

 return ret;
}

