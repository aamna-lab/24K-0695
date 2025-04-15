#include <iostream>
using namespace std;

class Vehicle{
    protected:
    string model;
    double rate;
    public:
    Vehicle (string m,double r) : model(m) , rate(r) {}
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
};

class Car : public Vehicle{
    public :
    Car (string m,double r) : Vehicle(m,r) {}
    double getDailyRate() override{
        return rate;
    }
    void displayDetails() override{
        cout << " Car Model Name : " << model << endl;
        cout << " Car Daily Rate : " << getDailyRate() << endl;
    }
};

class Bike : public Vehicle{
    public :
    Bike (string m,double r) : Vehicle(m,r) {}
    double getDailyRate() override{
        return rate;
    }
    void displayDetails() override{
        cout << " Bike Model Name : " << model << endl;
        cout << " Bike Daily Rate : " << getDailyRate() << endl;
    }
};


int main() {
   Car c("Toyota 345", 8.45);
   Bike b("Hyundai 234" , 7.45);
   
   Vehicle *v1 = &c;
   Vehicle *v2 = &b;
   v1->displayDetails();
   v2->displayDetails();
   cout << "Daily Rates of car : " << v1->getDailyRate() << endl;
    cout << "Daily Rates of bike : " << v2->getDailyRate() << endl;
  
}
