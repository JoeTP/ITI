#include <iostream>

using namespace std;

class Shape{
    protected:
        int d1,d2;
        float dimProduct(){return d1*d2;}
    public:
        Shape(){d1=d2=0;}
        Shape(int v){d1 = d2 = v;}
        Shape(int x, int y){d1 = x; d2 = y;}

        void setD1(int v){d1 = v;}
        void setD2(int v){d2 = v;}
        int getD1(){return d1;}
        int getD2(){return d2;}
        virtual float shapeArea()=0;
};


class Circle : public Shape{
public:
    Circle (int r) : Shape(r){}
    float shapeArea(){
    return 3.14*dimProduct();
    }
};

class Triangle : public Shape{
public:
    Triangle(int b, int h) : Shape(b,h){}
    float shapeArea(){
    return 0.5*dimProduct();
    }
};
class Rectangle : public Shape{
public:
    Rectangle(int x,int y){}
    float shapeArea(){
    return dimProduct();
    }
};
class Square : public Rectangle{
public:
    Square(int s) : Rectangle(s,s){}
};


class GeoArea{
    Shape *p[4];
public:
    GeoArea(Shape *p1, Shape *p2,Shape *p3,  Shape *p4){
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    }
    float totalArea(){
        int sum = 0;
    for(int i= 0; i<4; i++){
        sum += p[i]->shapeArea();
        }
        return sum;
    }
};

int main()
{
    Triangle t(2,4);
    Circle c(4);
    Rectangle r(2,5);
    Square s(2);
    GeoArea g(&t,&c,&r,&s);
    cout<<g.totalArea();
       return 0;
}
