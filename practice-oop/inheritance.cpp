/*Practice Question # 01
A power distribution company wants to automate its billing system. The company supplies electricity to residential, commercial, and industrial consumers. The billing system should
calculate the monthly electricity bill based on different tariff rates for each consumer type.
Problem Statement:
The company has consumers who are categorized as follows:
1. Residential Consumers: Charged at $0.12 per unit.
2. Commercial Consumers: Charged at $0.20 per unit.
3. Industrial Consumers: Charged at $0.30 per unit.
Additionally:
 If a residential consumer consumes more than 500 units, a surcharge of 5% is applied.
 If a commercial consumer consumes more than 1000 units, a surcharge of 10% is
applied.
 If an industrial consumer consumes more than 2000 units, a surcharge of 15% is
applied.
The system should allow:
 Registering a consumer (with details like consumer name, ID, and units consumed).
 Displaying the total bill based on category-wise calculations.
Implementation Requirements:
 Create a base class Consumer with attributes like name, consumerID, and
unitsConsumed.
 Create derived classes ResidentialConsumer, CommercialConsumer, and
IndustrialConsumer which inherit from Consumer.
 Each derived class should have a method to calculate the bill based on the unit
consumption and applicable surcharge.
 Create a main() function to allow user input and display the calculated bill.*/

#include <iostream>
using namespace std;

const float res= 0.12;
const float com = 0.20;
const float ind = 0.30;

class Consumer{
    string name;
    int consumerID;
    int unitsConsumed;
    public:
    Consumer(string n,int id, int unit): name(n),consumerID(id),unitsConsumed(unit){}
    string getName() const{
        return name;
    }
    int getID() const{
        return consumerID;
    }
    int getUnits() const{
        return unitsConsumed;
    }
    void setName(string n){
        name=n;
    }
    void setID(int newid){
        consumerID=newid;
    }
    void setUnits(int newUnit){
        unitsConsumed = newUnit;
    }
    void addCustomer(){
        cout<< "Enter name: " << endl;
        cin >> name;
        cout << "Enter id :  \n";
        cin >> consumerID;
        cout << "Enter units :\n";
        cin>>unitsConsumed;
    }
    virtual void display(){
        cout << "Name: " << name << endl;
        cout << "Consumer ID: " << consumerID << endl;
        cout << "Units Consumed: " << unitsConsumed << endl;
    }
};

class ResidentialConsumer : public Consumer{
    private:
    int totalbill;
    public:
    ResidentialConsumer(string n="",int id=0,int unit=0,int total=0): Consumer(n,id,unit),totalbill(total){}
    void totalBill(){
        totalbill=getUnits()*0.15;
        if (getUnits()>500){
         totalbill=totalbill+((totalbill*5)/100);
        }
        cout << "Your total bill is : " << totalbill << endl;
    }
};
class CommercialConsumer : public Consumer{
     private:
    int totalbill;
    public:
    CommercialConsumer(string n="",int id=0,int unit=0,int total=0): Consumer(n,id,unit),totalbill(total){}
    void totalBill(){
        totalbill=getUnits()*0.2;
        if (getUnits()>1000){
         totalbill=totalbill+((totalbill*10)/100);
        }
        cout << "Your total bill is : " << totalbill << endl;
    }
    
};
class IndustrialConsumer : public Consumer{
     private:
    int totalbill;
    public:
   IndustrialConsumer(string n="",int id=0,int unit=0,int total=0): Consumer(n,id,unit),totalbill(total){}
    void totalBill(){
        totalbill=getUnits()*0.3;
        if (getUnits()>2000){
         totalbill=totalbill+((totalbill*15)/100);
        }
        cout << "Your total bill is : " << totalbill << endl;
    }
};

int main(){
    int num;
    Consumer con("",0,0);
    con.addCustomer();
    cout << "residential customer, press 0\n";
    cout << "commercial customer, press 1\n";
    cout << "indutrial customer,press 2\n";
    cin >> num;
    if(num==0){
          ResidentialConsumer r(con.getName(),con.getID(),con.getUnits(),0);
        r.totalBill();
        r.display();
    }
    else if(num==1){
         CommercialConsumer c(con.getName(),con.getID(),con.getUnits(),0);
        c.totalBill();
        c.display();
    }
    else if(num==2){
         IndustrialConsumer i(con.getName(),con.getID(),con.getUnits(),0);
        i.totalBill();
        i.display();
    }else
    cout << "\nwrong input";
    
}
