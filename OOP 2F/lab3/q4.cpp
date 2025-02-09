#include <iostream>
using namespace std;

class Angle {
    int degrees;
    float minutes;
    char direction;

public:
    Angle(int d, float m, char dir) {
        degrees = d;
        minutes = m;
        direction = dir;
    }
    
    void getAngle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;
    }
    
    void displayAngle() {
        cout << degrees << " ' " << minutes << " ' " << direction << endl;
    }
};
int main() {
    
    while (true) {
        Angle a2(0, 0.0, 'N');
        a2.getAngle();
        a2.displayAngle();
    }
    return 0;
}
