#include <iostream>
using namespace std;

class Engine {
private:
    string type;
public:
    Engine(string t) : type(t) {}
    string getType() {
        return type;
        }
};

class Wheel {
private:
    int size;
public:
    Wheel(int s) : size(s) {}
    int getSize() { 
        return size; 
        
    }
};

class Headlight {
private:
    string brightness;
public:
    Headlight(string b) : brightness(b) {}
    string getBrightness() { 
        return brightness; 
        
    }
};

class Steering {
private:
    string type;
public:
    Steering(string t) : type(t) {}
    string getType() {
        return type; 
        
    }
};

class Car {
private:
    Engine* engine;   
    Wheel* wheel;      
    Headlight headlight; 
    Steering steering;  
public:
    Car(Engine* e, Wheel* w, string hBrightness, string sType)
        : engine(e), wheel(w), headlight(hBrightness), steering(sType) {}

    void displayDetails() {
        cout << "Car Details:" << endl;
        cout << "Engine Type: " << engine->getType() << endl;
        cout << "Wheel Size: " << wheel->getSize() << endl;
        cout << "Headlight Brightness: " << headlight.getBrightness() << endl;
        cout << "Steering Type: " << steering.getType() << endl;
    }
};
int main(){
  
}
