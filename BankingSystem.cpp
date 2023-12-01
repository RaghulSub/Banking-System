#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNumber, double initialBalance = 0) : accountNumber(accNumber), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs." << amount << ". New balance: Rs." << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs." << amount << ". New balance: Rs." << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    void inquireBalance() const {
        cout << "Account Balance: Rs." << balance << endl;
    }

    string getAccountNumber() const {
        return accountNumber;
    }
};

class BankCustomer {
private:
    string customerName;
    vector<BankAccount> accounts;   //here we can add multiple accounts for a single person

public:
    BankCustomer(string name) : customerName(name) {}

    void addAccount(const BankAccount& account) {
        accounts.push_back(account);
        cout << "Account " << account.getAccountNumber() << " added for " << customerName << "." << endl;
    }

    BankAccount* getAccount(const string& accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        cout << "Account " << accountNumber << " not found for " << customerName << "." << endl;
        return nullptr;
    }
};

int main() {
    cout<<"\t\tIndian Bank\n"<<endl;
    cout<<"Enter the name of the Customer :";
    string customer_name;
    getline(cin,customer_name);
    int balance;
    cout<<"Enter your Entry balance:";
    cin>>balance;

    BankCustomer customer1(customer_name);
    
    BankAccount account1("az67890", balance);

    customer1.addAccount(account1);
    
    cout<<"Choice"<<endl;
    cout<<"1) Deposit\n2) Withdraw"<<endl;
    int choice;
    cout<<"Enter your choice :";
    cin>>choice;
    switch (choice){
        case 1:
        cout<<"Enter amount to deposite : ";
        double dep_amt;
        cin>>dep_amt;
        account1.deposit(dep_amt);
        break;

        case 2:
        cout<<"Enter amount to withdraw : ";
        double withdraw_amt;
        cin>>withdraw_amt;
        account1.withdraw(withdraw_amt);
        break;

        default:
        cout<<"Invalid Input";
    }

    account1.inquireBalance();

    return 0;
}
