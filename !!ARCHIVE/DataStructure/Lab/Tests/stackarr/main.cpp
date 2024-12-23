#include <iostream>

using namespace std;

struct Node{
    Node *n;
    int d;

    Node(int data){
        d = data;
        n = NULL;
    }
};

Node *head;
Node *tail;

int i;
int *ar = new int[i];

void toArr();
void rev();

void print();
void enQu(int d);
int deQu();
int c;
int* toAr();
int main()
{
    enQu(1);
    enQu(2);
    enQu(3);
    enQu(4);
    enQu(5);
    enQu(6);
    enQu(7);


    print();

    cout<<endl;
    cout<<endl;
    toArr();
    rev();

    print();


    return 0;
}

void toArr(){
    Node *p = head;
    while(p){
        ar[i] = p->d;
        p = p->n;
        i++;
    }
}

void rev(){
    Node *p = head;
    while(p && i >= 0){
        p->d = ar[i];
        i--;
        p = p->n;
    }
}

/*
int* toAr(){
    Node* p = tail;
    int *ar;
    while(p){
        p = p->p;
        c++;
    }
    ar = new int[c];

    p = tail;
    for(int i = 0; i<c && p; i++){
        ar[i] = p->d;
        p = p->p;
    }

    return ar;
}*/

void enQu(int d){
    Node *p = new Node(d);

    if(head){ //queue exist
        p->n = head;
        head = p;
    }
    else{
        head = tail = p;
    }
}

void print(){
    Node *p = head;
    while(p){
        cout<<p->d<<" ";
        p = p->n;
    }
}
/*
int deQu(){
    int ret = -1;
    Node *p = tail;

    if(tail){
        ret = tail->d;
        tail = tail->p;
        delete p;
    }else{
        cout<<"FAILED";
    }
    return ret;
}



*/
void ins(int d){
    Node *p = new Node(d), *p1, *p2;
    p1 = p2 = head;
    if(!head || d > head->d){ //no list or data > head
            p->n = head;
            head = p;
    }
    else{ //list exist
    while(p2 && d < p2->d){
            p1 = p2;
            p2 = p2->n;
        }
    p->n = p1->n;
    p1->n = p;
    }
}
/*
void print(){
    Node *p = head;
    while(p){
        cout<<p->d<<" ";
        p = p->n;
    }
}
*/











