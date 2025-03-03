#include <iostream>
#include <string>
using namespace std;

class ValidateString {
private:
    string str;  
public:
    ValidateString(const string& s) : str(s) {}
    bool isValid() const {
        for (char c : str) {
            if (!isalpha(c)) {  
                return false;
            }
        }
        return true;  
    }
};

int main() {
    string input1, input2, input3;
    cout << "Enter 1st string: ";
    cin >> input1;
    cout << "Enter 2nd string: ";
    cin >> input2;
    cout << "Enter 3rd string: ";
    cin >> input3;
    ValidateString v1(input1);
    ValidateString v2(input2);
    ValidateString v3(input3);
    cout << "String 1 is " << (v1.isValid() ? "valid" : "invalid") << endl;
    cout << "String 2 is " << (v2.isValid() ? "valid" : "invalid") << endl;
    cout << "String 3 is " << (v3.isValid() ? "valid" : "invalid") << endl;
}
