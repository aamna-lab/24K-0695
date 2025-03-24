#include <iostream>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceType;
    double powerRating;
    bool status;

public:
    Device(string id, string type, double pr) : deviceID(id), deviceType(type), powerRating(pr), status(false) {}
    virtual void turnOn() {
        status = true;
        cout << "Turning ON: " << deviceType << "\nID: " << deviceID << endl;
    }
    virtual void turnOff() {
        status = false;
        cout << "Turning OFF: " << deviceType << "\nID: " << deviceID << endl;
    }
    virtual double calculatePowerUsage(int hours) = 0;
};

class Lights : public Device {
public:
    Lights(string id, string type, double pr) : Device(id, type, pr) {}
    double calculatePowerUsage(int hours) override {
        return powerRating * hours;
    }
};

class Fans : public Device {
protected:
    int speedFactor;
public:
    Fans(string id, string type, double pr, int sf) : Device(id, type, pr), speedFactor(sf) {}
    double calculatePowerUsage(int hours) override {
        return powerRating * hours * speedFactor;
    }
};

class AC : public Device {
protected:
    float currentTemp, desiredTemp;
public:
    AC(string id, string type, double pr, float ct, float dt) : Device(id, type, pr), currentTemp(ct), desiredTemp(dt) {}
    double calculatePowerUsage(int hours) override {
        return powerRating * hours * (1 - (currentTemp - desiredTemp) / 100);
    }
};

class SecuritySystems : public Device {
public:
    SecuritySystems(string id, string type, double pr) : Device(id, type, pr) {}
    double calculatePowerUsage(int hours) override {
        return powerRating * hours;
    }
    friend class MaintenanceTool;
};

class User {
protected:
    string userID, userRole;
    int accessLevel;
public:
    User(string id, string role, int al) : userID(id), userRole(role), accessLevel(al) {}
    void viewAccessibleDevices() {
        cout << "User " << userID << " can use these devices:\n";
        cout << "- Light\n- Fan\n- Air Conditioner\n";
    }
    friend void accessSecurityLogs(User user, SecuritySystems secSys);
};

void accessSecurityLogs(User user, SecuritySystems secSys) {
    if (user.accessLevel >= 2) {
        cout << "User " << user.userID << " can see security logs:\n";
        cout << "- Alert: Intrusion detected at 3:00 AM\n- System needs reset\n";
    } else {
        cout << "Sorry, you do not have access to security logs.\n";
    }
}

class MaintenanceTool {
public:
    void resetSecurityAlert(SecuritySystems &secSys) {
        cout << "Resetting alert : ID: " << secSys.deviceID << endl;
    }
};

int main() {
    User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);
    Lights light("L001", "Light", 10);
    Fans fan("F001", "Fan", 75, 3);
    AC ac("AC001", "Air Conditioner", 1500, 25, 20);
    SecuritySystems secSys("S001", "Security Alarm", 100);
    light.turnOn();
    fan.turnOn();
    ac.turnOn();
    secSys.turnOn();
    cout << "Power Usage Details:\n";
    cout << "Light: " << light.calculatePowerUsage(5) << endl;
    cout << "Fan: " << fan.calculatePowerUsage(3) << endl;
    cout << "Air Conditioner: " << ac.calculatePowerUsage(6) << endl;
    cout << "Security Alarm: " << secSys.calculatePowerUsage(24) << endl;
    user1.viewAccessibleDevices();
    accessSecurityLogs(user1, secSys);
    user2.viewAccessibleDevices();
    accessSecurityLogs(user2, secSys);
    MaintenanceTool tool;
    tool.resetSecurityAlert(secSys);
    return 0;
}
