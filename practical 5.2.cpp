#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload the '+' operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the '-' operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Function to input complex number
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    // Function to display complex number
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

int main() {
    int n;
    cout << "Enter the number of complex numbers: ";
    cin >> n;

    // Dynamically allocate memory for an array of Complex objects
    Complex* numbers = new Complex[n];

    // Input complex numbers
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter complex number " << i + 1 << ":\n";
        numbers[i].input();
    }

    // Display complex numbers
    cout << "\nThe complex numbers are:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Complex number " << i + 1 << ": ";
        numbers[i].display();
        cout << endl;
    }

    // Perform addition and subtraction of the first two complex numbers
    if (n >= 2) {
        Complex sum = numbers[0] + numbers[1];
        Complex diff = numbers[0] - numbers[1];

        cout << "\nSum of first two complex numbers: ";
        sum.display();
        cout << endl;

        cout << "Difference of first two complex numbers: ";
        diff.display();
        cout << endl;
    }

    // Deallocate the dynamically allocated memory
    delete[] numbers;

    return 0;
}
