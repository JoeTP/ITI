#include <iostream>
#include <string.h>
using namespace std;

class Node{
    public:
    int data;
    Node *pNext;
    Node(){
        data = 0;
        pNext = NULL;
    }

    Node(int d){
        data = d;
        pNext = NULL;
    }
};
Node *pTail, *pHead;

Node* createNode(int d){
    Node *ptr = new Node;
    if(ptr){
        ptr->data = d;
        ptr->pNext = NULL;
    }
    return ptr;
}

void insertNodeAtTail(int d){
    Node *ptr = new Node(d);
    if(ptr){
        if(pTail){// list exist
            pTail->pNext = ptr;
            pTail = ptr;
        } else{ //no list
          pHead = pTail = ptr;
        }
    }
}

void toArr();
void toList();
void rev();
int i = 0;
int *ar = new int[i];

void print(){
    Node *p = pHead;
    while(p){
        cout<<p->data<<" ";
        p = p->pNext;
    }
}


int main() {

/*
    int sizer, d;
    cin>> sizer;
    for(int i=0; i<sizer; i++){
        cin>>d;
        insertNodeAtTail(d);
    }
*/

    insertNodeAtTail(1);
    insertNodeAtTail(2);
    insertNodeAtTail(3);
    insertNodeAtTail(4);
    insertNodeAtTail(5);
    print();
    int x = 0;
    cout<<endl;
    rev();
x++;
    print();
    return 0;
}


void toArr(){
    Node *p = pHead;
    while(p){
        ar[i] = p->data;
        p = p->pNext;
        i++;
    }
}

void toList(){
    Node *p = pHead;
    i--;
    while(p && i >= 0){
        p->data = ar[i];
        i--;
        p = p->pNext;
    }
}

void rev(){
    toArr();
    toList();
}




















