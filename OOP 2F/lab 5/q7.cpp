#include <iostream>
using namespace std;

#define MAX_ITEMS 10  

class MenuItem {
private:
    string name;
    double price;
public:
    MenuItem() : name(""), price(0) {}  
    MenuItem(string n, double p) : name(n), price(p) {}

    string getName() {
        return name; 
        
    }
    double getPrice() {
        return price; 
        
    }
};

class Menu {
private:
    MenuItem items[MAX_ITEMS]; 
    int count; 
public:
    Menu() : count(0) {}

    void addItem(string name, double price) {
        if (count < MAX_ITEMS) {
            items[count] = MenuItem(name, price);
            count++;
        } else {
            cout << "Menu is full!\n";
        }
    }

    void displayMenu() {
        cout << "Restaurant Menu:\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << items[i].getName() << " -" << items[i].getPrice() << endl;
        }
    }

    MenuItem getItem(int index) { 
        if (index >= 0 && index < count) {
            return items[index];
        }
        return MenuItem(); 
    }
};

class Payment {
private:
    double amount;
public:
    Payment() : amount(0) {}
    Payment(double amt) : amount(amt) {}

    void displayPayment() {
        cout << "Total Payment: " << amount << endl;
    }
};

class Order {
private:
    MenuItem orderedItems[MAX_ITEMS]; 
    int itemCount; 
    Payment payment;
public:
    Order() : itemCount(0) {} 

    void addItem(MenuItem item) {
        if (itemCount < MAX_ITEMS) {
            orderedItems[itemCount] = item;
            itemCount++;
        } else {
            cout << "Cannot add more items!\n";
        }
    }

    void processPayment() {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += orderedItems[i].getPrice();
        }
        payment = Payment(total);
    }

    void displayOrder() {
        cout << "Order Details:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << orderedItems[i].getName() << " - " << orderedItems[i].getPrice() << endl;
        }
        payment.displayPayment();
    }
};

int main() {
    Menu menu;
    menu.addItem("Burger", 584.5);
    menu.addItem("Pizza", 845.6);
    menu.addItem("Pasta", 749);
    cout << "Restaurant Menu:\n";
    menu.displayMenu();
    Order order;
    order.addItem(menu.getItem(0)); 
    order.addItem(menu.getItem(1));
    order.processPayment();
    order.displayOrder();

}
