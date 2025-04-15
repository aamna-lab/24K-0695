#include <iostream>
using namespace std;

class SmartDevice{
    public:
    SmartDevice(){}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool getStatus() = 0;
};

class LightBulb : public SmartDevice{
    protected:
    bool isOn;
    int brightness;
    public:
    LightBulb(int b) : brightness(b) , isOn(false) , SmartDevice(){}
    void turnOn() override{
        isOn=true;
        cout << "LightBulb has turned on\n";
        cout << "Brightness is : " << brightness << endl;
    }
    void turnOff() override{
        isOn=false;
        cout << "LightBulb has turned off\n";
     
    }
    bool getStatus() override{
        return isOn;
    }
};

class Thermostat : public SmartDevice{
    protected:
    bool isOn;
    double temperature;
    public:
    Thermostat(double t) : temperature(t), isOn(false) , SmartDevice(){}
    void turnOn() override{
        isOn=true;
        cout << "Thermostat has turned on\n";
        cout << "Temperature is : " << temperature << endl;
    }
    void turnOff() override{
        isOn=false;
        cout << "Thermostat has turned off\n";
       
    }
    bool getStatus() override{
        return isOn;
    }
    
};

int main() {
    LightBulb l(6);
    Thermostat t(23.4);
    
    l.turnOn();
    t.turnOn();
    
    cout << "Status of Light bulb : " << l.getStatus() << endl;
    cout<< "Status of Thermostat : " << t.getStatus() << endl;
    
    l.turnOff();
    t.turnOff();

}
