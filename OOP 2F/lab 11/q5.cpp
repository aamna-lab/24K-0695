#include <iostream>
#include <string>
using namespace std;

class InsufficientFundsException : public exception {
    string msg;
public:
    InsufficientFundsException(double deficit) {
        msg = "InsufficientFundsException - Deficit: $";

        int dollars = (int)deficit;
        int cents = (int)((deficit - dollars) * 100 + 0.5); 

        msg += to_string(dollars) + ".";

        if (cents < 10) msg += "0"; 
        msg += to_string(cents);
    }

    const char* what() const throw() {
        return msg.c_str();
    }
};

template <typename T>
class BankAccount {
    T balance;
public:
    BankAccount(T b) {
        balance = b;
    }

    void withdraw(T amount) {
        if (amount > balance) {
            throw InsufficientFundsException(amount - balance);
        }

        balance -= amount;
        cout << "Withdraw successful. New balance: $" << balance << endl;
    }
};

int main() {
    BankAccount<double> acc(500.0);

    try {
        acc.withdraw(600.0);
    } catch (exception& e) {
        cout << "Withdraw $600: " << e.what() << endl;
    }

    return 0;
}
