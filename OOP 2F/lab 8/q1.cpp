#include <iostream>
using namespace std;

class Device{
protected:
string deviceID;
string deviceType;
double powerRating;
bool status;
public:
Device(string id,string type,double pr): deviceID(id),deviceType(type),powerRating(pr),status(false){}
virtual void turnOn(){
    status = true;
    cout << "device turned on\n";
}
virtual void turnOff(){
    status = false;
}
virtual double calculatePowerUsage(int hours) {} = 0;
};

class Lights: public Device{
    public:
    Lights(string id,string type,double pr) : Device(id,type,pr){}
    void turnOn(){
        status = true;
        cout << "device turned on\n";
    }
    void turnOff(){
        status = false;
        cout << "device turned off\n";
    }
    double calculatePowerUsage(int hours) override{
        return powerRating*hours;
    }
};

class Fans: public Device{
    protected:
    int speedFactor;
    public:
    Fans(int sf,string id,string type,double pr) : speedFactor(sf), Device(id,type,pr){}
    void turnOn() override{
        status = true;
        cout << "device turned on\n";
    }
    void turnOff() override{
        status = false;
        cout << "device turned off\n";
    }
    double calculatePowerUsage(int hours) override{
        return powerRating*hours*speedFactor;
    }
};

class SecuritySystems : public Device

class AC : public Device{
    protected:
    float currentTemp,desiredTemp;
    public:
    AC(float ct,float dt,,string id,string type,double pr): currenTemp(ct),desiredTemp(dt),Device(id,type,pr){}
    void turnOn() override {
        status = true;
        cout << "device turned on\n";
    }
    void turnOff() override{
        status = false;
        cout << "device turned off\n";
    }
    double calculatePowerUsage(int hours) override{
        return powerRating*hours*;
    }

};

class User{
    protected:
    string userID,userRole;
    int accessLevel;
    public:
    User(string id, string role, int al): userID(id), userRole(role), accessLevel(al){}
    void viewAccessibleDevices(){
       cout << "User " << userID <<  " can access standard devices\n";
    }
};


class MaintenanceTool{
};





int main() {
   
    return 0;
}
