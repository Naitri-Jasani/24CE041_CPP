#include <iostream>
#include <vector>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void showPerson() const {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// Derived class 1
class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a) {
        empID = id;
    }

    void showEmployee() const {
        showPerson();
        cout << "Employee ID: " << empID << endl;
    }
};

// Derived class 2
class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int a, int id, string dept) : Employee(n, a, id) {
        department = dept;
    }

    void showManager() const {
        showEmployee();
        cout << "Department: " << department << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of managers: ";
    cin >> n;

    vector<Manager> managers;

    for (int i = 0; i < n; ++i) {
        string name, dept;
        int age, id;

        cout << "\nEnter details for Manager " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore(); // flush newline from previous input
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Department: ";
        cin.ignore(); // flush newline
        getline(cin, dept);

        Manager m(name, age, id, dept);
        managers.push_back(m);
    }

    cout << "\n======= Manager Details =======\n";
    for (int i = 0; i < managers.size(); ++i) {
        cout << "Manager " << i + 1 << ":\n";
        managers[i].showManager();
        cout << "-------------------------\n";
    }

    return 0;
}

