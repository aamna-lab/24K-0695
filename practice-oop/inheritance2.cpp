#include <iostream>
using namespace std;

class Vehicle {
private:
    string name, vehicleID, type;
    int speed;
public:
    Vehicle(string n = "", string id = "", string t = "", int s = 0) : name(n), vehicleID(id), type(t), speed(s) {}
    
    string getName() { return name; }
    string getID() { return vehicleID; }
    string getType() { return type; }
    int getSpeed() { return speed; }
    
    virtual float calculateFine() const = 0;
    
    void display() {
        cout << "\nTraffic Violation Details\n";
        cout << "------------------------------\n";
        cout << "Owner Name: " << getName() << endl;
        cout << "Vehicle Type: " << getType() << endl;
        cout << "Speed Recorded: " << getSpeed() << " km/h" << endl;
    }
};

class Car : public Vehicle {
private:
    int sl;
    int fineRate;
public:
    Car(string n = "", string id = "", string t = "", int s = 0, int speedL = 80, int fr = 5)
        : Vehicle(n, id, t, s), sl(speedL), fineRate(fr) {}
    
    float calculateFine() const override {
        int spd = getSpeed();
        if (spd <= sl) return 0;
        float fine = (spd - sl) * fineRate;
        if (spd > 120) fine += fine * 0.1;
        return fine;
    }
    
    void display() {4
        Vehicle::display();
        float fine = calculateFine();
        cout << "Speed limit: " << sl << " km/h" << endl;
        if (fine == 0) {
            cout << "No fine." << endl;
            return;
        }
        cout << "Total Fine: " << fine << endl;
    }
};

class Bike : public Vehicle {
private:
    int sl;
    int fineRate;
public:
    Bike(string n = "", string id = "", string t = "", int s = 0, int speedL = 60, int fr = 3)
        : Vehicle(n, id, t, s), sl(speedL), fineRate(fr) {}
    
    float calculateFine() const override {
        int spd = getSpeed();
        if (spd <= sl) return 0;
        float fine = (spd - sl) * fineRate;
        if (spd > 90) fine += fine * 0.15;
        return fine;
    }
    
    void display() {
        Vehicle::display();
        float fine = calculateFine();
        cout << "Speed limit: " << sl << " km/h" << endl;
        if (fine == 0) {
            cout << "No fine." << endl;
            return;
        }
        cout << "Total Fine: " << fine << endl;
    }
};

class Truck : public Vehicle {
private:
    int sl;
    int fineRate;
public:
    Truck(string n = "", string id = "", string t = "", int s = 0, int speedL = 70, int fr = 7)
        : Vehicle(n, id, t, s), sl(speedL), fineRate(fr) {}
    
    float calculateFine() const override {
        int spd = getSpeed();
        if (spd <= sl) return 0;
        float fine = (spd - sl) * fineRate;
        if (spd > 100) fine += fine * 0.2;
        return fine;
    }
    
    void display() {
        Vehicle::display();
        float fine = calculateFine();
        cout << "Speed limit: " << sl << " km/h" << endl;
        if (fine == 0) {
            cout << "No fine." << endl;
            return;
        }
        cout << "Total Fine: " << fine << endl;
    }
};

int main() {
    Car car1("John Doe", "ABC123", "Car", 130);
    Bike bike1("Jane Smith", "XYZ456", "Bike", 95);
    Truck truck1("Mike Johnson", "LMN789", "Truck", 110);

    car1.display();
    cout << endl;
    bike1.display();
    cout << endl;
    truck1.display();
    return 0;
}

