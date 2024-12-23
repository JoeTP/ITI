#include <iostream>
using namespace std;

class Node{
    public:
    Node *right, *left;
    int data;

    Node(int d){
        data=d;
        right = left = NULL;
    }

} ;

Node *root;

Node * inserting(Node *r, int d){

    if(!r ){
        r = new Node(d);
    } else if(d < r->data){
      r->left = inserting(r->left, d);
    } else{
       r->right = inserting(r->right, d);
    }
    return r;
}

void preOrder(Node *p) {
    if(p){
    cout<<p->data<<" ";
    preOrder(p->left);
    preOrder(p->right);
    }
}

int main() {
    root = inserting(root, 4);
    root = inserting(root, 7);
    root = inserting(root, 2);
    root = inserting(root, 9);
    root = inserting(root, 11);
    root = inserting(root, 12);
    root = inserting(root, 13);
    root = inserting(root, 121);
    root = inserting(root, 12);
    root = inserting(root, 135);
    root = inserting(root, 16);
    root = inserting(root, 19);

   preOrder(root);

    return 0;
}
