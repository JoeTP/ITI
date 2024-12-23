#include <iostream>

using namespace std;



struct Node {
    int d;
    Node *n, *p;

    Node(int data){
        d = data;
        n = p = NULL;
    }
};

Node *head, *tail;

int addNode(int d){
int ret = -1;
Node *ptr = new Node(d);
if(ptr){
    ret = 1;
    if(!head){ //no list
        head = tail = ptr;
    } else{ //there is list
        tail->n = ptr;
        ptr->p = tail;
        tail = ptr;
    }
}
return ret;
}


void insertAsc(int d);
void insertDsc(int d);
void print();

void ins(int d){
    Node *p = new Node(d);
    if(head){
        p->n = head;
        head = p;
    }else{
        head = p;
    }
}

void sorting(){
    Node *p = head;
    int i = 0, c =0, temp, swapp = 1;
        while(p){
            p = p->n;
            c++;
            }
        while(swapp){
            p = head;
            swapp = 0;
            for(int j = 0; j < c - 1 - i && p; j++){
                if(p->d > p->n->d){
                    temp = p->d;
                    p->d = p->n->d;
                    p->n->d = temp;
                    swapp = 1;
                }
                p = p->n;
            }
            i++;
        }
}

Node *mid(Node *s, Node *e){
    Node *fast = s, *slow = s;

    while(fast != e && fast->n != e){
        fast = fast->n->n;
        slow = slow->n;
    }

    return slow;
}

int searching(int d){
    Node *pStart = head, *pEnd = NULL;
    int found = -1;
    while (found == -1 && pStart != pEnd){
        Node *m = mid(pStart, pEnd);

        if(d == m->d){
            found = m->d;
        }else{
            if(d > m->d){
                pStart = m->n;
            }
            if(d < m->d){
                pEnd = m;
            }
        }
    }
    return found;
}



int main()
{
    addNode(1);
    addNode(2);
    addNode(7);
    addNode(3);
    addNode(99);
    addNode(6);
    addNode(9);
    cout<<"BEFORE: ";
    print();
    cout<<endl;
    cout<<"AFTER: ";
    sorting();
    print();
    cout<<endl;
    int f = searching(6);
    f != -1 ? cout<<"FOUND" : cout<<"NOT FOUND";


    return 0;
}

/*
void insertAsc(int d){
  Node *p = new Node(d), *p1, *p2;
    p1 = p2 = head;
    if(!head || d < head->d){ //no list or data > head
            p->n = head;
            head = p;
    }
    else{ //list exist
    while(p2 && d > p2->d){
            p1 = p2;
            p2 = p2->n;
        }
    p->n = p1->n;
    p1->n = p;
    }

}*/

void insertAsc(int d){
    Node *p = new Node(d);
    Node *p1 = head, *p2 = head;

    if(!head){//no list
        head = p;
    }
    else{ // list exist
        if(d < head->d){
            p->n = head;
            head = p;
        }
        else{
            while(p2 && d > p2->d){
                p1 = p2;
                p2 = p2->n;
            }
            p1->n = p;
            p->n = p2;
        }
    }
}


void insertDsc(int d){

}


void print(){
    Node *p = head;
    while(p){
        cout<<p->d<<" ";
        p = p->n;
    }
}


