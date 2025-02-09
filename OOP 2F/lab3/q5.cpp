#include <iostream>
#include <string>
using namespace std;

class Cal {
    string t[12][31];
    int y;

public:
    Cal(int yr) { y = yr; }
    
    void addT(string task, int d, int m) {
        if (m >= 1 && m <= 12 && d >= 1 && d <= 31)
            t[m - 1][d - 1] = task;
    }
    
    void remT(int d, int m) {
        if (m >= 1 && m <= 12 && d >= 1 && d <= 31)
            t[m - 1][d - 1] = "";
    }
    
    void showT() {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 31; j++) {
                if (!t[i][j].empty())
                    cout << "M " << i + 1 << " D " << j + 1 << ": " << t[i][j] << endl;
            }
        }
    }
};

int main() {
    Cal c(2025);
    c.addT("Doctor", 5, 2);
    c.addT("Meeting", 12, 3);
    c.addT("Gym", 20, 4);
    c.addT("Party", 8, 6);
    c.addT("Deadline", 15, 7);
    c.addT("Flight", 25, 9);
    c.showT();
    cout << "\nRemoving task...\n";
    c.remT(12, 3);
    c.showT();
    
}
