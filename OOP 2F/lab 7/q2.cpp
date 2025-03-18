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
       return (22.0/7.0)*radius*radius;
    }
    float calculatePerimeter() override{
        return (22.0/7.0)*2*radius;
    }

};
class Rectangle : public Shape{
    protected:
    float width,height;
    int posx,posy;
    public:
    Rectangle(float w, float h,int pos1,int pos2, int x, int y, string col, float bt) : 
    width(w),height(h),posx(pos1),posy(pos2),Shape(x,y,col,bt){}
    void draw() override{
        cout << "Drawing Rectangle from top-left position : ( " << posx << ", " << posy<< ")" << endl;
    }
    float calculateArea() override{
       return width*height;
    }
    float calculatePerimeter() override{
        return 2*(width + height);
    }
    
};
class Triangle : public Shape{
    protected:
    float length, breadth,hyp;
    public:
    Triangle(float l,float b,float hp,int x, int y, string col, float bt):length(l),breadth(b),hyp(hp),Shape(x,y,col,bt){}
    void draw() override{
        cout << "Drawing Triangle"<< endl;
    }
    float calculateArea() override{
       return (length*breadth)/2;
    }
    float calculatePerimeter() override{
        return (length+breadth+hyp);
    }

};
class Polygon : public Shape{
    protected:
    float s1,s2;
    public:
    Polygon(float side1,float side2,int x, int y, string col, float bt):s1(side1),s2(side2),Shape(x,y,col,bt){}
    void draw() override{
        cout << "Drawing Polygon"<< endl;
    }
    float calculateArea() override{
       return (s1*s2);
    }
    float calculatePerimeter() override{
        return 2*(s1+s2);
    }

};
int main() {
    Circle c(1,2,1.5,3,3,"Red",2.3);
    Rectangle r(2.5,4,4,5,4,7,"Purple",1.2);
    Triangle t(3.0,4.0,5.0,3,4,"Black",2.4);
    Polygon p(3.4,5.6,5,6,"Pink",6.7);
    c.draw();
    cout << "Area of circle :"<< c.calculateArea() << endl;
    cout << "Perimeter of circle :"<< c.calculatePerimeter() << endl;
    r.draw();
    cout << "Area of recatbgle:"<< r.calculateArea() << endl;
    cout << "Perimeter of rectangle :"<< r.calculatePerimeter() << endl;
    t.draw();
    cout << "Area of triangle :"<< t.calculateArea() << endl;
    cout << "Perimeter of triangle:"<< t.calculatePerimeter() << endl;
    p.draw();
    cout << "Area of polygon :"<< p.calculateArea() << endl;
    cout << "Perimeter of polygon :"<< p.calculatePerimeter() << endl;
  
}
