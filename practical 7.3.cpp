#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Product {
    string name;
    int quantity;
    float price;
};

vector<Product> inventory;

void loadInventory(const string& filename) {
    ifstream file(filename);
    if (!file) return;

    Product p;
    while (file >> p.name >> p.quantity >> p.price) {
        inventory.push_back(p);
    }
    file.close();
}

void saveProductToFile(const Product& p, const string& filename) {
    ofstream file(filename, ios::app);
    if (file) {
        file << p.name << " " << p.quantity << " " << p.price << endl;
    }
}

void addProduct(const string& filename) {
    Product p;
    cout << "Enter product name: ";
    cin >> p.name;
    cout << "Enter quantity: ";
    cin >> p.quantity;
    cout << "Enter price: ";
    cin >> p.price;

    inventory.push_back(p);
    saveProductToFile(p, filename);
    cout << "Product added successfully.\n";
}

void viewInventory() {
    cout << left << setw(15) << "Name" << setw(10) << "Quantity" << setw(10) << "Price\n";
    cout << "-------------------------------------\n";
    for (const auto& p : inventory) {
        cout << left << setw(15) << p.name << setw(10) << p.quantity << setw(10) << p.price << endl;
    }
}

void searchProduct() {
    string searchName;
    cout << "Enter product name to search: ";
    cin >> searchName;

    for (const auto& p : inventory) {
        if (p.name == searchName) {
            cout << "Found: " << p.name << ", Qty: " << p.quantity << ", Price: $" << p.price << endl;
            return;
        }
    }
    cout << "Product not found.\n";
}

int main() {
    string filename = "inventory.txt";
    loadInventory(filename);

    int choice;
    do {
        cout << "\nInventory Management Menu\n";
        cout << "1. Add Product\n2. View Inventory\n3. Search Product\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(filename); break;
            case 2: viewInventory(); break;
            case 3: searchProduct(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

