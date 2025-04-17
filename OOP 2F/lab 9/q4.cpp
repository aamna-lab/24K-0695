#include <iostream>
using namespace std;

class PaymentMethod{
    public:
    PaymentMethod(){}
    virtual void processPayment(double amount)=0;
};

class CreditCard : public PaymentMethod{
    protected:
    string cardNumber;
    public:
    CreditCard(string c):cardNumber(c),PaymentMethod(){}
    void processPayment(double amount) override{
        cout << "Card Number : " << cardNumber << endl;
        cout << "Amount entered : " << amount << endl;
    }
};

class DigitalWallet : public PaymentMethod{
    protected:
    double balance;
    public:
    DigitalWallet(double b) : balance(b), PaymentMethod(){}
    void processPayment(double amount) override{
        if(amount<balance || amount==balance){
            balance=balance-amount;
            cout << "New Balance after deducting " << amount << " : " << balance << endl;
            return;
        }
        cout << "Insufficient balance\n";
    }
};

int main() {
    CreditCard c("A675HG7");
    c.processPayment(3400);
    
    DigitalWallet d(3400);
    d.processPayment(450);
    cout << "Deducting more balance than available :\n";
    d.processPayment(9000);
 
}
