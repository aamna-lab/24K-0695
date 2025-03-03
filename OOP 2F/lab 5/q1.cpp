#include <iostream>
using namespace std;

class Square {
private:
    float sideLength;
    float area;
    static float allareas;

public:
    Square() {
        sideLength = 0.0;
        area = 0.0;
    }

    Square(float sideLength) {
        this->sideLength = sideLength;
        area = sideLength * sideLength;  
    }

    float getlength() {
        return sideLength;
    }

    float getarea() {
        return area;
    }

    void setlength(float sideLength) {
        this->sideLength = sideLength;
        area = sideLength * sideLength; 
    }

    static float getallareas() {
        return allareas;
    }

    void calculateArea() {
        area = sideLength * sideLength;  
        allareas += area;  
        cout << "Your area for side length: " << sideLength << " is " << area << endl;
    }
};


float Square::allareas = 0.0;

int main() {
    Square s1, s2, s3;

    s1.setlength(6.5);
    s2.setlength(7.5);
    s3.setlength(8.5);
    s1.calculateArea();   
    s2.calculateArea();
    s3.calculateArea();
    cout << "Area for s1: " << s1.getarea() << endl;
    cout << "All Areas: " << Square::getallareas() << endl;
    cout << "Area for s2: " << s2.getarea() << endl;
    cout << "All Areas: " << Square::getallareas() << endl;
    cout << "Area for s3: " << s3.getarea() << endl;
    cout << "All Areas: " << Square::getallareas() << endl;

}
