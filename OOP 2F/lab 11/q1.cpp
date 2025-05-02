#include <iostream>
#include <exception>
using namespace std;

class InvalidValueException : public exception
{
public:
    const char *what() const noexcept override
    {
        cerr << "Error: InvalidValueException - Age cannot be negative or exceed 120" << endl;
    }
};

void validateAge(int age)
{
    if (age < 0 || age > 120)
    {
        throw InvalidValueException();
    }
    else
    {
        cout << "Valid Age." << endl;
    }
}

int main()
{
    int age;
    cout << "Enter age: " << endl;
    cin >> age;

    try
    {
        validateAge(age);
    }
    catch (InvalidValueException &e)
    {
        e.what();
    }

    return 0;
}
