#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const throw() {
        return "NegativeNumberException - Input must be non-negative!";
    }
};

class InvalidTypeException : public exception {
public:
    const char* what() const throw() {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};

template <typename T>
T mysqrt(T num) {
    if (typeid(T) != typeid(int) && typeid(T) != typeid(double)) {
        throw InvalidTypeException();
    }
    if (num < 0) {
        throw NegativeNumberException();
    }
    return sqrt(num);
}

int main() {
    try {
        cout << mysqrt(-4) << endl;
    } catch (exception& e) {
        cout << "sqrt(-4): " << e.what() << endl;
    }

    try {
        string s = "hello";
        throw InvalidTypeException(); 
    } catch (exception& e) {
        cout << "sqrt(\"hello\"): " << e.what() << endl;
    }

    return 0;
}
