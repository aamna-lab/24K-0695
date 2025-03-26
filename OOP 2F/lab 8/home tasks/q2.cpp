#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int productID;
    double price;
public:
    Product(int id, double p) : productID(id), price(p) {}
    virtual void calculatePrice() = 0;
    void applyDiscount(int percent) {
        price -= (price * percent / 100.0);
        cout << "Discounted Price (with " << percent << " discount): " << price << endl;
    }

    void applyDiscount(double fixed) {
        price -= fixed;
        cout << "Discounted Price (with " << fixed << " discount): " << price << endl;
    }

    void applyDiscount(Product &obj) {
        obj.price /= 2;
        cout << "Buy One Get One Free applied! New price: " << obj.price << endl;
    }

    double getPrice() {
        return price;
    }
};

class Electronics : public Product {
public:
    Electronics(int id, double p) : Product(id, p) {}

    void calculatePrice() override {
        price += (price * 0.15);
        cout << "Electronics Price after tax (15%): " << price << endl;
    }
};

class Clothing : public Product {
public:
    Clothing(int id, double p) : Product(id, p) {}

    void calculatePrice() override {
        price += (price * 0.05);
        cout << "Clothing Price after tax (5%): " << price << endl;
    }
};

class ShoppingCart {
    int count;
    Product *items[10]; 
public:
    ShoppingCart() : count(0) {}
    void addItem(Product *p) {
        if (count < 10) {
            items[count++] = p;
        } else {
            cout << "Cart is full!\n";
        }
    }

    void displayCart() {
        cout << "Shopping Cart contains:\n";
        for (int i = 0; i < count; i++) {
            cout << " Product ID: " << i + 1 << ", Price: " << items[i]->getPrice() << endl;
        }
    }

    
    ShoppingCart operator+(ShoppingCart &other) {
        ShoppingCart newCart;
        for (int i = 0; i < count; i++) newCart.addItem(items[i]);
        for (int i = 0; i < other.count; i++) newCart.addItem(other.items[i]);
        return newCart;
    }

    void operator-() {
        if (count > 0) {
            cout << "Removed last item from cart.\n";
            count--;
        }
    }

    void operator*(double discount) {
        for (int i = 0; i < count; i++) {
            items[i]->applyDiscount(discount);
        }
    }

    void operator/(int users) {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += items[i]->getPrice();
        }
        cout << "Each user pays: " << total / users << endl;
    }
};

int main() {
    Electronics laptop(101, 1000);
    Clothing shirt(202, 50);
    laptop.calculatePrice();
    shirt.calculatePrice();
    laptop.applyDiscount(10);
    shirt.applyDiscount(5.0);
    laptop.applyDiscount(laptop); 
    ShoppingCart cart1, cart2;
    cart1.addItem(&laptop);
    cart1.addItem(&shirt);
    Electronics phone(103, 800);
    Clothing jeans(204, 75);
    cart2.addItem(&phone);
    cart2.addItem(&jeans);
    ShoppingCart mergedCart = cart1 + cart2;
    mergedCart.displayCart();
    -mergedCart;
    mergedCart.displayCart();
    mergedCart * 10; 

  
}
