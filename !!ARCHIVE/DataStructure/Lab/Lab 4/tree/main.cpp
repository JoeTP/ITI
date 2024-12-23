#include <iostream>

using namespace std;


class Node{
public:
    int data;
    Node *left,*right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

class BT{
public:
    Node *root;

    BT(){
        root = NULL;
    }
};

    Node* inserting(Node *r, int d){
        if(r == NULL){
            r = new Node(d);
        }
       else if(d < r->data){
           r->left = inserting(r->left,d);
        }else{
           r->right = inserting(r->right,d);
        }
        return r;
    }

    void inOrder(Node *r){
        if(r){
        inOrder(r->left);
        cout<<r->data<<"  ";
        inOrder(r->right);
        }
    }

    void preOrder(Node *r){
        if(r){
        cout<<r->data<<"  ";
        preOrder(r->left);
        preOrder(r->right);
        }
    }

    void postOrder(Node *r){
        if(r){
        postOrder(r->left);
        postOrder(r->right);
        cout<<r->data<<"  ";
        }
    }

int main()
{
    //Node *root = new Node(6);
    BT tree;
    Node *root = tree.root;
    root = new Node(6);
    root = inserting(root, 4);
    root = inserting(root, 7);
    root = inserting(root, 2);
    root = inserting(root, 9);
    root = inserting(root, 11);

    inOrder(root);
    cout<<endl<<" = = = = = = = = = = = = = = = = = = = = "<<endl;
    preOrder(root);
    cout<<endl<<" = = = = = = = = = = = = = = = = = = = = "<<endl;
    postOrder(root);
    return 0;
}
