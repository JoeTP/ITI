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
    Point *p1,*p2;
    int length, width;

    public:
        Rect(){
        p1 = p2 = NULL;
        length = width = 0;
        }
        Rect(Point *n, Point *m){
        p1 = n;
        p2 = m;
        if(n != NULL && m != NULL){
            length = abs(p1->getX()-p2->getX());
            width = abs(p1->getY()-p2->getY());
        }
        }
    int getL(){
    return length;
    }
    int getW(){
    return width;
    }
    Point* getP1(){
    return p1;
    }
    Point* getP2(){
    return p2;
    }

    void setP1(Point *p){
        p1 = p;
        if(p1 != NULL && p2 != NULL){
            length = abs(p1->getX()-p2->getX());
            width = abs(p1->getY()-p2->getY());
        }
    }
    void setP1XY(int x, int y){
    p1->setX(x);
    p1->setY(y);
            length = abs(p1->getX()-p2->getX());
            width = abs(p1->getY()-p2->getY());
    }
    void setP2XY(int x, int y){
    p2->setX(x);
    p2->setY(y);
            length = abs(p1->getX()-p2->getX());
            width = abs(p1->getY()-p2->getY());
    }


};


int main()
{

    Point p1(10,2),p2(3,3);
    Rect r(&p1,&p2); //pointer in constructor
    cout<<"Length = "<<r.getL()<<endl;
    cout<<"Width = "<<r.getW()<<endl;

    return 0;
}
