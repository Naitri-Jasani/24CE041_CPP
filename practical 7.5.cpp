#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

ostream& currency(ostream& os) {
    os << "rupees ";
    return os;
}

struct Student {
    string name;
    float marks;
    float tuitionFee;
};

void displayStudents(const vector<Student>& students) {
    cout << "\n======= Student Academic Report =======\n";
    cout << left << setw(20) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;
    cout << string(45, '-') << endl;

    for (const auto& s : students) {
        cout << left << setw(20) << s.name
             << setw(10) << fixed << setprecision(2) << s.marks
             << currency << setw(14) << fixed << setprecision(2) << s.tuitionFee << endl;
    }
}

int main() {
    ifstream file("student.txt");

    if (!file) {
        cerr << "Error: Could not open 'students.txt'. Make sure the file exists." << endl;
        return 1;
    }

    vector<Student> students;
    Student s;

    while (file >> s.name >> s.marks >> s.tuitionFee) {
        students.push_back(s);
    }

    file.close();

    displayStudents(students);

    return 0;
}

