#include <iostream>

using namespace std;



struct Node{
    int d;
    Node *n,*p;

    Node(int data){
        d = data;
        n = p = NULL;
    }
};

Node *head, *tail;

void freeList();
void printList(Node *head);
Node* adding(int d);
Node* inserting(int d, int loc);
void deleting(int loc);
void deleteByLoc(int loc);
void reverseList(Node& head);

int main()
{
    // head = new Node(100);
    adding(1);
    adding(2);
    adding(3);
    adding(4);
    adding(8);
    adding(9);
    reverseList(&head);

    printList(head);

    return 0;
}



void freeList(){
    Node *temp;
    while(head){
        temp = head;
        head = temp->n;
        delete temp;
    }
}

void printList(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->d<<" ";
        temp = temp->n;
    }
}

Node* adding(int d){
    Node *pt = new Node(d);
    if(head){
        tail->n = pt;
        pt->p = tail;
        tail = pt;
    }else{
        head = tail = pt;
    }
    return pt;
}

Node* inserting(int d, int loc){
    Node *pt = new Node(d);
    if(!head){
        head = tail = pt;
    }
    else if(loc == 0){
        head->p = pt;
        pt->n = head;
        head = pt;
    }else {
        Node *temp = head;
        for(int i = 0; i<loc && temp; i++){
            temp = temp->n;
        }

        if(temp == tail || !temp){
            tail->n = pt;
            pt->p = tail;
            tail = pt;
        }else{
        pt->p = temp;
        pt->n = temp->n;
        temp->n->p = pt;
        temp->n = pt;
        }
    }
    return pt;
}

void deleting(int loc){
    Node *pt;
    if(head){
        pt = head;
        for(int i = 0; i < loc && pt; i++){
            pt = pt->n;
        }
        if(pt == head){ // first
            if(head == tail){//1 node
                head = tail = NULL;
            }else{//nodes
                head = head->n;
                head->p = NULL;
            }
        }else if(pt == tail){//last
            tail = tail->p;
            tail->n = NULL;
        }else if(pt){//mid
            pt->p->n = pt->n;
            pt->n->p = pt->p;
        }
        delete pt;
    }
}



void reverseList(Node& head) {
    Node temp = nullptr;
    Node* current = head;

    while (current) {
        // Swap next and prev for each node
        temp = current->p;
        current->p = current->n;
        current->n = temp;
        current = current->p; // Move to the next node (originally prev)
    }

    if (temp) {
        head = temp->p; // Update head to the last node
    }
}

