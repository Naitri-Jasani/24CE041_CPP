#include <iostream>
#include <queue>
using namespace std;

// Base class for Fuel Type
class FuelType {
protected:
    string fuel;

public:
    FuelType(string f) {
        fuel = f;
    }

    void showFuel() const {
        cout << "Fuel Type: " << fuel << endl;
    }
};

// Base class for Brand
class Brand {
protected:
    string brand;

public:
    Brand(string b) {
        brand = b;
    }

    void showBrand() const {
        cout << "Brand: " << brand << endl;
    }
};

// Derived class Car
class Car : public FuelType, public Brand {
public:
    Car(string f, string b) : FuelType(f), Brand(b) {}

    void showCarDetails() const {
        showBrand();
        showFuel();
    }
};

int main() {
    int n;
    cout << "Enter number of cars to add to service queue: ";
    cin >> n;

    queue<Car> serviceQueue;

    for (int i = 0; i < n; ++i) {
        string brand, fuel;
        cout << "\nEnter details for Car " << i + 1 << ":\n";
        cout << "Brand: ";
        cin.ignore(); // Clear newline from previous input
        getline(cin, brand);
        cout << "Fuel Type (e.g., Petrol, Diesel): ";
        getline(cin, fuel);

        Car car(fuel, brand);
        serviceQueue.push(car);
    }

    cout << "\n===== Processing Service Queue =====\n";
    int carNumber = 1;
    while (!serviceQueue.empty()) {
        cout << "Car " << carNumber << ":\n";
        serviceQueue.front().showCarDetails();
        cout << "----------------------\n";
        serviceQueue.pop();
        carNumber++;
    }

    return 0;
}

