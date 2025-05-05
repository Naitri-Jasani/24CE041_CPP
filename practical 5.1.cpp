#include <iostream>

using namespace std;

class Calculator {
public:
    // Add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Add two floats
    float add(float a, float b) {
        return a + b;
    }

    // Add an integer and a float
    float add(int a, float b) {
        return a + b;
    }

    // Add a float and an integer
    float add(float a, int b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    int choice;

    cout << "Calculator\n";
    cout << "Choose an option:\n";
    cout << "1. Add two integers\n";
    cout << "2. Add two floats\n";
    cout << "3. Add an integer and a float\n";
    cout << "4. Add a float and an integer\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int a, b;
            cout << "Enter two integers: ";
            cin >> a >> b;
            int result = calc.add(a, b);
            cout << "Result: " << result << endl;
            break;
        }
        case 2: {
            float a, b;
            cout << "Enter two floats: ";
            cin >> a >> b;
            float result = calc.add(a, b);
            cout << "Result: " << result << endl;
            break;
        }
        case 3: {
            int a;
            float b;
            cout << "Enter an integer and a float: ";
            cin >> a >> b;
            float result = calc.add(a, b);
            cout << "Result: " << result << endl;
            break;
        }
        case 4: {
            float a;
            int b;
            cout << "Enter a float and an integer: ";
            cin >> a >> b;
            float result = calc.add(a, b);
            cout << "Result: " << result << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}

