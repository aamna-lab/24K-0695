#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;
public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() {
        return amount * exchangeRate;
    }
    virtual double convertTo(Currency& targetCurrency) {
        double amountInBase = convertToBase();
        return amountInBase / targetCurrency.exchangeRate;
    }
    virtual void displayCurrency() {
        cout << currencySymbol << " " << amount  <<  endl;
    }

};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    void displayCurrency() override {
        cout << "Amount in Dollars: ";
        Currency::displayCurrency();
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    void displayCurrency() override {
        cout << "Amount in Euros: ";
        Currency::displayCurrency();
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs.", 0.012) {}

    void displayCurrency() override {
        cout << "Amount in  Rupees: ";
        Currency::displayCurrency();
    }
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee pkr(5000);

    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "Converting 50 EUR to USD: " << eur.convertTo(usd) <<  endl;
    cout << "Converting 5000 PKR to USD: " << pkr.convertTo(usd) <<  endl;
    cout << "Converting 100 USD to PKR: " << usd.convertTo(pkr) <<  endl;

}

