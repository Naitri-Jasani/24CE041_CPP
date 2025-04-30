/*A bank wants to create a simple system to manage customer bank accounts. The system should
allow customers to perform basic banking operations such as depositing money, withdrawing
money, and checking their account balance.
Each bank account will need to have an account holder's name, a unique account number, and
a balance. Deposits should increase the account balance, while withdrawals should only be
allowed if there are sufficient funds in the account. If an attempt is made to withdraw more
money than is available, an error message should be displayed. Customers should also have the
ability to view their account balance whenever required.
The system must be designed using Object-Oriented Programming principles, focusing on
creating a simple and efficient solution to manage the accounts effectively. The system should
ensure that all account details are secure and accessible only through authorized methods.
*/
#include<iostream>
#include<string>
using namespace std;
class Account{
        private:
            string name;
            int acc_num;
            float balance;
        public:
            void get_details();
            void put_details();
            void deposit(float amount);
            void withdraw(float amount);
            void checkbalance();
};

void Account::get_details()
{
    cout<<endl;
    cout<<"Enter the accountant name:";
    getline(cin,name);
    cout<<"Enter the account number:";
    cin>>acc_num;
    cout<<"Enter the balance:Rs,";
    cin>>balance;
}
void Account::put_details()
{
    cout<<endl;
    cout<<"The accountant name:"<<name<<endl;
    cout<<"Enter the account number:"<<acc_num<<endl;
    cout<<"Enter the balance:Rs,"<<balance<<endl;
}
void Account::deposit(float amount)
{
    if(amount>0){
        balance+=amount;
        cout<<"Deposited amount is:Rs,"<<amount;
    }
    else{
        cout<<"Amount is not deposited";
    }
}
void Account:: withdraw(float amount)
{
    if(amount>0 && amount<=balance)
    {
        balance-=amount;
        cout<<"Withdraw amount Rs, "<<amount<<" sunccesfully";
    }
    else if(amount>balance)
    {
        cout<<"Money can not be withdraw because money can't be sufficient";
    }
    else
    {
        cout<<"Failed Withdrawal";
    }
}
void Account:: checkbalance()
{
     cout<<"The balance is :Rs, "<<balance;

}
int main ()
{
    Account A;
    A.get_details();
    A.put_details();
int choice;
float balance;
    while (true) {
        // Display menu to the user
        cout<<endl;
        cout << "\n====== Bank Account Menu =======" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Deposit money
                cout << "Enter amount to deposit: Rs,";
                cin >> balance;
                A.deposit(balance);
                break;

            case 2:
                // Withdraw money
                cout << "Enter amount to withdraw: Rs, ";
                cin >> balance;
                A.withdraw(balance);
                break;

            case 3:
                // Check balance
                A.checkbalance();
                break;

            case 4:
                // Exit the program
                cout << "Exiting... Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

    }
    return 0;
}
