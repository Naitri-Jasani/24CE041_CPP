
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int loanTenure;

public:
    Loan() {} // Default constructor

    void getLoanDetails() {
        cout << "\nEnter the loan ID: ";
        cin >> loanID;

        cout << "Enter the name: ";
        cin.ignore();
        getline(cin, applicantName);

        cout << "Enter the total loan amount: ";
        cin >> loanAmount;

        cout << "Enter the annual interest rate (%): ";
        cin >> annualInterestRate;

        cout << "Enter the loan tenure (in months): ";
        cin >> loanTenure;
    }

    double calculateEMI() const {
        double P = loanAmount;
        double R = (annualInterestRate / 100) / 12;
        int T = loanTenure;

        double EMI = P * R * pow(1 + R, T) / (pow(1 + R, T) - 1);
        return EMI;
    }

    void displayLoanDetails() const {
        double EMI = calculateEMI();
        cout << "\n===== Loan Details =====" << endl;
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Loan Tenure: " << loanTenure << " months" << endl;
        cout << "Calculated EMI: " << EMI << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of people applying for a loan: ";
    cin >> n;

    Loan* loans = new Loan[n]; // Dynamic array of Loan objects

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for applicant " << i + 1 << ":";
        loans[i].getLoanDetails();
    }

    for (int i = 0; i < n; i++) {
        loans[i].displayLoanDetails();
    }

    delete[] loans; // Free memory
    return 0;
}
