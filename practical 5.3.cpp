#include <iostream>
#include <vector>

using namespace std;

class Point {
private:
    int x, y;

public:
    // Default constructor
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Unary '-' operator to negate the point
    Point operator-() const {
        return Point(-x, -y);
    }

    // Binary '+' operator to add two points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // '==' operator to compare two points
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    // Function to input point coordinates
    void input() {
        cout << "Enter x coordinate: ";
        cin >> x;
        cout << "Enter y coordinate: ";
        cin >> y;
    }

    // Function to display point coordinates
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    vector<Point> points;
    int n;

    cout << "How many points would you like to enter? ";
    cin >> n;

    // Input points from the user
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter coordinates for point " << i + 1 << ":\n";
        Point p;
        p.input();
        points.push_back(p);
    }

    // Display all points
    cout << "\nEntered Points:\n";
    for (const auto& p : points) {
        p.display();
        cout << endl;
    }

    // Demonstrate addition of first two points
    if (points.size() >= 2) {
        Point sum = points[0] + points[1];
        cout << "\nSum of first two points: ";
        sum.display();
        cout << endl;
    }

    // Demonstrate negation of the first point
    if (!points.empty()) {
        Point negated = -points[0];
        cout << "\nNegation of the first point: ";
        negated.display();
        cout << endl;
    }

    // Compare first two points
    if (points.size() >= 2) {
        if (points[0] == points[1]) {
            cout << "\nThe first two points are equal.\n";
        } else {
            cout << "\nThe first two points are different.\n";
        }
    }

    return 0;
}

