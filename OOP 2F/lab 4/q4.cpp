#include <iostream>
using namespace std;
class Car {
private:
  int carID;
  string model;
  int year;
  bool isRented;
public:
    Car() {
        carID = 0;
        year = 0;
        model = "";
        isRented = false;
    }
   Car(int id,string m,int y,bool rent) {
        carID = id;
        model = m;
        year = y;
        isRented = rent;
    }
    string getModel() {
        return model;
    }
    int getID() {
        return carID;
    }
    int getYear(){
        return year;
    }
    bool getRent(){
        return isRented;
    }
    
    void rentCar(){
       isRented = true;
    }
    void returnCar() { 
        cout << "Car has been returned" << endl;
        cout << "Car Available Now" << endl;
        isRented = false;
    }
    bool isVintage(){
        if(year > 2000){
             cout << "Car is not vintage" << endl;
        }else
        cout << "Car is vintage" << endl;
        return true;
    }
};

int main() {
    Car object(45643 , "Toyota" , 2024 , true);
    cout << "Car ID :  " << object.getID() << endl;
    cout << "Car Model  : " << object.getModel() << endl;
    cout << "Year : " << object.getYear() << endl; 
    cout << "Car Rented (0 if not, 1 if yes) :  " << object.getRent() << endl;
    object.rentCar();
    object.returnCar();
    object.isVintage();
    cout << endl;
    Car object2(982653, "Bentley" , 1997 , false);
    cout << "Car ID :  " << object2.getID() << endl;
    cout << "Car Model  : " << object2.getModel() << endl;
    cout << "Year : " << object2.getYear() << endl; 
    cout << "Car Rented (0 if not, 1 if yes) :  " << object2.getRent() << endl;
    object2.rentCar();
    object2.isVintage();
    
}
