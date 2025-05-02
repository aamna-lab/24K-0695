#include <iostream>
#include <string>
using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const throw() {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const throw() {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack {
    T arr[5];
    int top;
public:
    Stack() { top = -1; }

    void push(T val) {
        if (top == 4) throw StackOverflowException();
        arr[++top] = val;
    }

    T pop() {
        if (top == -1) throw StackUnderflowException();
        return arr[top--];
    }
};

int main() {
    Stack<int> s;

    try {
        for (int i = 0; i < 6; i++) s.push(i);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        for (int i = 0; i < 6; i++) s.pop();
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
