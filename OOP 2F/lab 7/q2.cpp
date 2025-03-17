#include <iostream>
using namespace std;
class Shape{
    protected:
    int px,py;
    string color;
    float borderThickness;
    public:
    Shape(int x, int y, string col, float bt) : 
    px(x), py(y) , color(col) , borderThickness(bt){}
    virtual void draw() = 0;
    virtual float calculateArea() = 0;
    virtual float calculatePerimeter() = 0;
};
class Circle : public Shape{
    protected:
    int cx,cy; float radius;
    public :
    Circle(int c1,int c2, float rad,int x, int y, string col, float bt) :
    cx(c1),cy(c2), radius(rad) , Shape(x,y,col,bt) {}
    void draw() override{
        cout << "Drawing Circle from center : ( " << cx << ", " << cy << ")" << endl;
    }
    float calculateArea() override{
       return (22/7)*radius*radius;
    }
    float calculatePerimeter() override{
        return (22/7)*2*radius;
    }

};
class Rectangle : public Shape{
    protected:
    float width,height;
    



};
class Triangle : public Shape{

};
class Polygon : public Shape{

};
int main() {
      


  

}
