#include <iostream>
#include <vector>

using namespace std;

class Fahrenheit; // Forward declaration

class Celsius {
private:
    double temp;

public:
    Celsius(double t = 0.0) : temp(t) {}

    // Typecast operator to convert Celsius to Fahrenheit
    operator Fahrenheit() const;

    void display() const {
        cout << temp << " C";
    }

    double getTemp() const {
        return temp;
    }
};

class Fahrenheit {
private:
    double temp;

public:
    Fahrenheit(double t = 0.0) : temp(t) {}

    // Typecast operator to convert Fahrenheit to Celsius
    operator Celsius() const;

    void display() const {
        cout << temp << " F";
    }

    double getTemp() const {
        return temp;
    }
};

// Typecast operator to convert Celsius to Fahrenheit
Celsius::operator Fahrenheit() const {
    return Fahrenheit((temp * 9.0 / 5.0) + 32.0);
}

// Typecast operator to convert Fahrenheit to Celsius
Fahrenheit::operator Celsius() const {
    return Celsius((temp - 32.0) * 5.0 / 9.0);
}

int main() {
    vector<Celsius> celsiusTemps;
    vector<Fahrenheit> fahrenheitTemps;

    int n;
    cout << "How many temperatures would you like to convert? ";
    cin >> n;

    // Input temperatures and store in vectors
    for (int i = 0; i < n; ++i) {
        double temp;
        cout << "\nEnter temperature " << i + 1 << " in Celsius: ";
        cin >> temp;
        celsiusTemps.push_back(Celsius(temp));
    }

    // Convert and store in Fahrenheit
    for (const auto& c : celsiusTemps) {
        fahrenheitTemps.push_back(static_cast<Fahrenheit>(c));
    }

    // Display all temperatures
    cout << "\nCelsius Temperatures:\n";
    for (const auto& c : celsiusTemps) {
        c.display();
        cout << endl;
    }

    cout << "\nConverted Fahrenheit Temperatures:\n";
    for (const auto& f : fahrenheitTemps) {
        f.display();
        cout << endl;
    }

    // Compare first Celsius and Fahrenheit
    if (celsiusTemps[0].getTemp() == fahrenheitTemps[0].getTemp()) {
        cout << "\nThe first Celsius and Fahrenheit temperatures are equal.\n";
    } else {
        cout << "\nThe first Celsius and Fahrenheit temperatures are not equal.\n";
    }

    return 0;
}

