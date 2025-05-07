#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Struct to hold student data
struct Student {
    string name;
    int marks;
    char grade;
};

// User-defined manipulator for column alignment
ostream& format(ostream& out) {
    out << left << setw(15);  // 15-character wide columns
    return out;
}

// Approach 1: Read and display directly
void displayDirectly(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file '" << filename << "'." << endl;
        return;
    }

    string name;
    int marks;
    char grade;

    cout << format << "Name" << format << "Marks" << format << "Grade" << endl;
    cout << string(40, '-') << endl;

    while (file >> name >> marks >> grade) {
        cout << format << name << format << marks << format << grade << endl;
    }

    file.close();
}

// Approach 2: Store in vector for future sorting/filtering
void displayWithStorage(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file '" << filename << "'." << endl;
        return;
    }

    vector<Student> students;
    Student s;
    while (file >> s.name >> s.marks >> s.grade) {
        students.push_back(s);
    }

    file.close();

    // Simple display (can be sorted or filtered later)
    cout << format << "Name" << format << "Marks" << format << "Grade" << endl;
    cout << string(40, '-') << endl;

    for (const auto& stu : students) {
        cout << format << stu.name << format << stu.marks << format << stu.grade << endl;
    }
}

// Main program
int main() {
    string filename = "students.txt";

    cout << "Choose method:\n1. Display directly from file\n2. Store and display\nEnter choice: ";
    int choice;
    cin >> choice;

    if (choice == 1)
        displayDirectly(filename);
    else if (choice == 2)
        displayWithStorage(filename);
    else
        cout << "Invalid choice!" << endl;

    return 0;
}
