#include <iostream>
using namespace std;

class Activity{
    public:
    Activity(){}
    virtual double calculateCaloriesBurned() = 0;
};

class Running : public Activity{
    protected:
    double distance;
    double time1;
    public:
    Running(double d, double t):distance(d),time1(t),Activity(){}
    double calculateCaloriesBurned() override{
        return distance*time1;
    }
    
};

class Cycling : public Activity{
    protected:
    double speed;
    double time2;
    public:
    Cycling(double s,double t) : speed(s), time2(t) , Activity(){}
    double calculateCaloriesBurned() override{
        return speed*time2;
    }
    
};

int main() {
    Running r(2.34,30.8);
    Cycling c(7.54,1.67);
    
    cout << "Calories Burned through running : " << r.calculateCaloriesBurned() << endl;
    cout << "Calories Burned through cycling : " << c.calculateCaloriesBurned() << endl;
    
  
 
}
