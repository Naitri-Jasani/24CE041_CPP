#include <iostream>
#include <vector>
using namespace std;

// Abstract base class
class Student {
protected:
    string name;
    int marks;
public:
    Student(string n, int m) : name(n), marks(m) {}
    virtual void computeGrade() = 0; // Pure virtual function
    virtual void display() = 0; // Also virtual to allow polymorphic behavior
    virtual ~Student() {}
};

// Undergraduate student class
class Undergraduate : public Student {
public:
    Undergraduate(string n, int m) : Student(n, m) {}

    void computeGrade() override {
        cout << "Undergraduate Student: " << name << " - ";
        if (marks >= 70)
            cout << "Grade: A\n";
        else if (marks >= 50)
            cout << "Grade: B\n";
        else
            cout << "Grade: C\n";
    }

    void display() override {
        cout << "Undergraduate Student \n Name: " << name << ", Marks: " << marks << endl;
    }
};

// Postgraduate student class
class Postgraduate : public Student {
public:
    Postgraduate(string n, int m) : Student(n, m) {}

    void computeGrade() override {
        cout << "Postgraduate Student: " << name << " - ";
        if (marks >= 75)
            cout << "Grade: A\n";
        else if (marks >= 60)
            cout << "Grade: B\n";
        else
            cout << "Grade: C\n";
    }

    void display() override {
        cout << "Postgraduate Student \n  Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student*> students;

    // Collecting student data from the user
    for (int i = 0; i < n; ++i) {
        string type, name;
        int marks;
        cout << "\nEnter student type (UG/PG): ";
        cin >> type;
        cin.ignore();  // To clear the buffer before using getline
        cout << "Enter student name: ";
        getline(cin, name);  // Taking full name as input
        cout << "Enter marks: ";
        cin >> marks;

        if (type == "UG" || type == "ug") {
            students.push_back(new Undergraduate(name, marks));
        } else if (type == "PG" || type == "pg") {
            students.push_back(new Postgraduate(name, marks));
        } else {
            cout << "Invalid type! Skipping this student.\n";
        }
    }

    // Displaying student details and grades
    cout << "\n=== Student Grades ===\n";
    for (Student* s : students) {
        s->display();
        s->computeGrade();
    }

    // Clean up memory
    for (Student* s : students)
        delete s;

    return 0;
}

