#include <iostream>
#include <vector>
using namespace std;

// Define pi manually
const double PI = 3.14159;

// Base class
class Shape {
protected:
    double radius;
public:
    void setRadius(double r) {
        radius = r;
    }
    double getRadius() const {
        return radius;
    }
};

// Derived class
class Circle : public Shape {
public:
    double getArea() const {
        return PI * radius * radius;
    }

    void displayArea(int index) const {
        cout << "Circle " << index + 1 << " with radius " << radius
             << " has area: " << getArea() << endl;
    }
};

int main() {
    int choice;
    cout << "Choose method:\n1. Static (Array)\n2. Dynamic (Vector)\nEnter your choice: ";
    cin >> choice;

    int num;
    cout << "Enter number of circles: ";
    cin >> num;

    if (choice == 1) {
        Circle circles[100];

        for (int i = 0; i < num; ++i) {
            double r;
            cout << "Enter radius for circle " << i + 1 << ": ";
            cin >> r;
            circles[i].setRadius(r);
        }

        for (int i = 0; i < num; ++i) {
            circles[i].displayArea(i);
        }

    } else if (choice == 2) {
        vector<Circle> circles;

        for (int i = 0; i < num; ++i) {
            double r;
            cout << "Enter radius for circle " << i + 1 << ": ";
            cin >> r;

            Circle c;
            c.setRadius(r);
            circles.push_back(c);
        }

        for (int i = 0; i < circles.size(); ++i) {
            circles[i].displayArea(i);
        }

    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

