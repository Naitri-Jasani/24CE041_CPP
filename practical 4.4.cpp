#include <iostream>
#include <stack>
using namespace std;

class bankaccount {
protected:
    string accnum;
    double balance;
public:
    bankaccount(string acc, double bal) : accnum(acc), balance(bal) {}

    void deposit(double amt) {
        balance += amt;
        cout << "Deposited: " << amt << ", Balance: " << balance << endl;
    }

    virtual int withdraw(double amt) {
        if (balance >= amt) {
            balance -= amt; // Corrected assignment to subtraction
            cout << "Withdrawn: " << amt << ", Balance: " << balance << endl;
            return 1;
        } else {
            cout << "Insufficient balance!\n";
            return 0;
        }
    }

    double getbalance() const {
        return balance;
    }
};

class savingaccount : public bankaccount {
public:
    savingaccount(string acc, double bal) : bankaccount(acc, bal) {}
};

class currentaccount : public bankaccount {
    double overdraftlimit;
public:
    currentaccount(string acc, double bal, double limit) : bankaccount(acc, bal), overdraftlimit(limit) {}

    int withdraw(double amt) override {
        if (balance + overdraftlimit >= amt) {
            balance -= amt;
            cout << "Withdrawn: " << amt << ", Balance: " << balance << endl;
            return 1;
        } else {
            cout << "Overdraft limit exceeded!\n";
            return 0;
        }
    }

    double getOverdraftlimit() const {
        return overdraftlimit;
    }
};

struct transaction {
    string type; // "deposit" or "withdraw"
    double amt;
};

void showmenu() {
    cout << "\n1. Deposit\n2. Withdraw\n3. Undo\n4. Show Balance\n5. Exit\n";
}

int main() {
    string type, accnum;
    double bal;
    cout << "Account type (saving/current): ";
    cin >> type;
    cout << "Account number: ";
    cin >> accnum;
    cout << "Initial balance: ";
    cin >> bal;

    stack<transaction> history;
    int ch;
    double amt;

    if (type == "saving" || type == "Saving") {
        savingaccount acc(accnum, bal);
        do {
            showmenu();
            cout << "Enter your choice: ";
            cin >> ch;
            switch (ch) {
                case 1:
                    cout << "Amount: ";
                    cin >> amt;
                    acc.deposit(amt);
                    history.push({"deposit", amt});
                    break;
                case 2:
                    cout << "Amount: ";
                    cin >> amt;
                    if (acc.withdraw(amt) == 1)
                        history.push({"withdraw", amt});
                    break;
                case 3:
                    if (!history.empty()) {
                        transaction last = history.top();
                        history.pop();
                        cout << "Undoing: " << last.type << " of " << last.amt << endl;
                        if (last.type == "deposit")
                            acc.withdraw(last.amt);
                        else
                            acc.deposit(last.amt);
                    } else {
                        cout << "No transaction to undo.\n";
                    }
                    break;
                case 4:
                    cout << "Balance: " << acc.getbalance() << endl;
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (ch != 5);
    } else if (type == "current" || type == "Current") {
        double limit;
        cout << "Enter overdraft limit: ";
        cin >> limit;
        currentaccount acc(accnum, bal, limit);
        do {
            showmenu();
            cout << "Enter your choice: ";
            cin >> ch;
            switch (ch) {
                case 1:
                    cout << "Amount: ";
                    cin >> amt;
                    acc.deposit(amt);
                    history.push({"deposit", amt});
                    break;
                case 2:
                    cout << "Amount: ";
                    cin >> amt;
                    if (acc.withdraw(amt) == 1)
                        history.push({"withdraw", amt});
                    break;
                case 3:
                    if (!history.empty()) {
                        transaction last = history.top();
                        history.pop();
                        cout << "Undoing: " << last.type << " of " << last.amt << endl;
                        if (last.type == "deposit")
                            acc.withdraw(last.amt);
                        else
                            acc.deposit(last.amt);
                    } else {
                        cout << "No transaction to undo.\n";
                    }
                    break;
                case 4:
                    cout << "Balance: " << acc.getbalance() << endl;
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (ch != 5);
    } else {
        cout << "Invalid account type.\n";
    }

    return 0;
}
