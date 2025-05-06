#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor\n"; }
    virtual ~Base() { cout << "Base destructor\n"; } // Make it virtual
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[5];
        cout << "Derived constructor\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived destructor\n";
    }
};

int main() {
    Base* obj = new Derived(); // Still upcasting
    delete obj; // Now both destructors are called, memory is released
    return 0;
}

