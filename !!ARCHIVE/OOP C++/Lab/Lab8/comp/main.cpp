#include <iostream>

using namespace std;

class Point {
int x, y;

public:
    Point(){
    x = y = 0;
    }
    Point(int a, int b){
    x = a;
    y = b;
    }

    void setX(int v){
    x = v;
    }
    void setY(int v){
    y = v;
    }
    int getX(){return x;}
    int getY(){return y;}
};

class Rect{
    Point p1,p2;
    int length, width;

    public:
        Rect(int x1,int y1, int x2, int y2) : p1(x1,y1), p2(x2,y2){
        length = abs(x2-x1);
        width = abs(y2-y1);
        }
    int getL(){
    return length;
    }
    int getW(){
    return width;
    }
    Point getP1(){
    return p1;
    }
    Point  getP2(){
    return p2;
    }

    void setP1(int x, int y){
    p1.setX(x);
    p1.setY(y);
    }
    void setP2(int x, int y){
    p2.setX(x);
    p2.setY(y);
    }

};


int main()
{
    Rect re(1,2,3,4); //4 values in constructor
    cout<<"Length = "<<re.getL()<<endl;
    cout<<"Width = "<<re.getW()<<endl;

    return 0;
}
