#include <iostream>
using namespace std;

class StationaryShop {
    string items[100];
    double prices[100];
    int itemCount;

public:
    StationaryShop() { itemCount = 0; }

    void addItem() {
        if (itemCount < 100) {
            cout << "Enter item name: ";
            cin >> items[itemCount];
            cout << "Enter item price: ";
            cin >> prices[itemCount];
            itemCount++;
        } else {
            cout << "Item list is full!" << endl;
        }
    }

    void fetchItems() {
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }

    void editPrice() {
        int index;
        cout << "Enter item number to edit price: ";
        cin >> index;
        if (index > 0 && index <= itemCount) {
            cout << "Enter new price: ";
            cin >> prices[index - 1];
        } else {
            cout << "Invalid item number!" << endl;
        }
    }

    void viewItems() {
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << "-" << prices[i] << endl;
        }
    }

    void createReceipt() {
        string boughtItems[100];
        int quantities[100], count = 0;
        double total = 0;
        char more;
        do {
            cout << "Enter item name: ";
            cin >> boughtItems[count];
            cout << "Enter quantity: ";
            cin >> quantities[count];
            for (int i = 0; i < itemCount; i++) {
                if (boughtItems[count] == items[i]) {
                    total += prices[i] * quantities[count];
                }
            }
            count++;
            cout << "Add more items? (y/n): ";
            cin >> more;
        } while (more == 'y');
        cout << "\nReceipt:\n";
        for (int i = 0; i < count; i++) {
            cout << boughtItems[i] << " x " << quantities[i] << endl;
        }
        cout << "Total: $" << total << endl;
    }
};

int main() {
    StationaryShop shop;
    int choice;
    do {
        cout << "\n1. Add Item\n2. Fetch Items\n3. Edit Price\n4. View Items\n5. Create Receipt\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) shop.addItem();
        else if (choice == 2) shop.fetchItems();
        else if (choice == 3) shop.editPrice();
        else if (choice == 4) shop.viewItems();
        else if (choice == 5) shop.createReceipt();
    } while (choice != 6);
    return 0;
}

