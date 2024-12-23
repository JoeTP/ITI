#include <iostream>

using namespace std;

struct Node{
    Node *left, *right;
    int d;

    Node(int data){
        d = data;
        left = right = NULL;
    }
};

Node *root;

Node* ins(Node *r,int d){
    if(!r){
        r = new Node(d);
    }else if(d < r->d){
        r->left = ins(r->left,d);
    }else{

        r->right = ins(r->right,d);
    }
    return r;
}

void pre(Node *r){
    if(r){
        cout<<r->d<<" ";
        pre(r->left);
        pre(r->right);
    }
}

int main()
{
    root = ins(root, 1);
    root = ins(root, 2);
    root = ins(root, 3);
    root = ins(root, 4);
    root = ins(root, 5);
    root = ins(root, 6);
    root = ins(root, 7);
    root = ins(root, 8);
    root = ins(root, 9);


    pre(root);
    return 0;
}
