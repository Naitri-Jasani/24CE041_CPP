#include <iostream>
#include <vector>

using namespace std;

// Define PI manually
const double PI = 3.1415;

// Abstract base class
class Shape {
public:
    virtual void input() = 0;             // Pure virtual function for input
    virtual double area() const = 0;      // Pure virtual function for area calculation
    virtual ~Shape() {}                   // Virtual destructor
};

// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    void input() override {
        cout << "Enter length and width of the rectangle: ";
        cin >> length >> width;
    }

    double area() const override {
        return length * width;
    }
};

// Derived class for Circle
class Circle : public Shape {
private:
    double radius;

public:
    void input() override {
        cout << "Enter radius of the circle: ";
        cin >> radius;
    }

    double area() const override {
        return PI * radius * radius;
    }
};

int main() {
    vector<Shape*> shapes;  // Dynamic collection of shape pointers
    int choice;

    cout << "Shape Area Calculator\n";
    cout << "1. Add Rectangle\n";
    cout << "2. Add Circle\n";
    cout << "3. Calculate Areas\n";
    cout << "4. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Shape* rect = new Rectangle();
            rect->input();
            shapes.push_back(rect);
        } else if (choice == 2) {
            Shape* circ = new Circle();
            circ->input();
            shapes.push_back(circ);
        } else if (choice == 3) {
            cout << "\nCalculating Areas:\n";
            for (size_t i = 0; i < shapes.size(); ++i) {
                cout << "Shape " << i + 1 << " area: " << shapes[i]->area() << endl;
            }
        } else if (choice == 4) {
            // Clean up dynamically allocated memory
            for (Shape* shape : shapes) {
                delete shape;
            }
            shapes.clear();
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

