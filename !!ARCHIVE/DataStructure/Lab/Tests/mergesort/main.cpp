#include <iostream>

using namespace std;


void sorting(int ar[], int l, int h);
void merging(int ar[], int l, int mid, int h);
void print(int ar[]);
int s = 7;



struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Function to push a new node to the front of the list
void push(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to reverse the linked list
void reverseList() {
    Node* p = nullptr;
    Node* c = head;
    Node* n = nullptr;

    while (c != NULL) {
    n = c->next;
    c->next = p;
    p = c;
    c = n;
    }
    head = p;

}

// Function to print the linked list
void printList() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}




int main()
{
    int ar[] = {2, 4,6,1,7,3,10};
    print(ar);
    sorting(ar,0,s-1);
    cout<<endl;
    print(ar);

/*

    push(10);
    push(30);
    push(20);
    push(50);
    push(40);

    std::cout << "Original List: ";
    printList();

    // Reverse the linked list
    //reverseList();
    sorting(ar);
    std::cout << "Reversed List: ";
    printList();

*/
    return 0;
}

void print(int ar[]){

for(int i = 0; i < s; i++){
        cout<<ar[i]<<" ";
    }
}

void sorting(int ar[], int l, int h){
    if(l<h){
        int mid = (h+l)/2;
        sorting(ar,l,mid);
        sorting(ar,mid+1,h);
        merging(ar,l,mid,h);
    }
}

void merging(int ar[], int low, int mid, int high){
    int i = low, l1 = low, l2 = mid+1;
    int temp[100];

    while(l1 <= mid && l2 <= high){
        if(ar[l1] < ar[l2]){
            temp[i] = ar[l1];
            i++; l1++;
        }else{
            temp[i] = ar[l2];
            i++; l2++;
        }
    }
    while(l1 <= mid){
        temp[i] = ar[l1];
            i++; l1++;
    }
    while(l2 <= high){
        temp[i] = ar[l2];
            i++; l2++;
    }
    for(i = low; i <= high; i++){
        ar[i] = temp[i];
    }

}



