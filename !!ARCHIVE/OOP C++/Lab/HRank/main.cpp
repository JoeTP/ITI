#include <iostream>
#include <string.h>

using namespace std;

class MyArray {
private:
    int data[10]; // Fixed-size array

public:
    MyArray() {
        // Initialize the array elements
        for (int i = 0; i < 10; ++i) {
            data[i] = i * 10;
        }
    }

    // Overloading the [] operator
    int& operator[](int index) {
        return data[index];
    }
};
int f(int &x, int c){
    c = c-1;
    if(c==0){
        return 1;
    }
    x = x +1;
    return f(x,c)*x;
}

int main() {
    int a =4;
   cout<<f(a,a);
    return 0;
}
