#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // Constructor with default parameters
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Method to shift the point by dx and dy
    Point* shift(int dx, int dy) {
        x += dx;
        y += dy;
        return this; // Enables method chaining
    }

    // Method to display the current coordinates
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int x, y;
    cout << "Enter initial x and y coordinates: ";
    cin >> x >> y;

    Point p(x, y);

    int n;
    cout << "Enter number of shifts: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int dx, dy;
        cout << "Enter dx and dy for shift " << i + 1 << ": ";
        cin >> dx >> dy;
        p.shift(dx, dy);
    }

    cout << "Final Position: ";
    p.display();

    return 0;
}

