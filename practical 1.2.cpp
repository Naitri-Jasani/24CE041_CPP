
#include <iostream>
#include <string>
using namespace std;

class Product {
    int productId;
    string name;
    int quantity;
    int price;

public:
    Product(int id = 0, string na = "", int quan = 0, int pri = 0) {
        productId = id;
        name = na;
        quantity = quan;
        price = pri;
    }

    void getProductDetails();
    void putProductDetails() const;
    void addProduct(int amount);
    void removeProduct(int amount);
    int calculateAmount() const;
    void buyProduct();
};

void Product::getProductDetails() {
    cout << "Enter the product ID: ";
    cin >> productId;
    cout << "Enter the product name: ";
    cin >> name;
    cout << "Enter the quantity: ";
    cin >> quantity;
    cout << "Enter the price per item: ";
    cin >> price;
}

void Product::putProductDetails() const {
    cout << "\nProduct ID: " << productId << endl;
    cout << "Product Name: " << name << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price per item: " << price << endl;
}

void Product::addProduct(int amount) {
    if (amount > 0) {
        quantity += amount;
        cout << "Product quantity updated. New quantity: " << quantity << endl;
    } else {
        cout << "Invalid quantity to add." << endl;
    }
}

void Product::removeProduct(int amount) {
    if (amount > quantity) {
        cout << "Cannot remove more than available quantity!" << endl;
    } else if (amount <= 0) {
        cout << "Invalid quantity to remove." << endl;
    } else {
        quantity -= amount;
        cout << "Product quantity updated. New quantity: " << quantity << endl;
    }
}

int Product::calculateAmount() const {
    return quantity * price;
}

void Product::buyProduct() {
    int buyQty;
    cout << "Enter the quantity to purchase: ";
    cin >> buyQty;

    if (buyQty <= 0) {
        cout << "Invalid purchase quantity!" << endl;
    } else if (buyQty > quantity) {
        cout << "Error: Not enough stock!" << endl;
    } else {
        quantity -= buyQty;
        cout << "Purchase successful! Remaining quantity: " << quantity << endl;
    }
}

int main() {
    Product p;
    int choice, amount;

    do {
        cout << "\n========= Inventory Menu =========" << endl;
        cout << "1. Enter product details" << endl;
        cout << "2. Add product quantity" << endl;
        cout << "3. Remove product quantity" << endl;
        cout << "4. Display product details" << endl;
        cout << "5. Calculate inventory value" << endl;
        cout << "6. Buy product" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p.getProductDetails();
            break;
        case 2:
            cout << "Enter quantity to add: ";
            cin >> amount;
            p.addProduct(amount);
            break;
        case 3:
            cout << "Enter quantity to remove: ";
            cin >> amount;
            p.removeProduct(amount);
            break;
        case 4:
            p.putProductDetails();
            break;
        case 5:
            cout << "Total inventory value: " << p.calculateAmount() << endl;
            break;
        case 6:
            p.buyProduct();
            break;
        case 0:
            cout << "Exiting... Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

