#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance; // private attribute
public:
    BankAccount() : balance(0.0) {} // constructor

    void deposit(double amount)
    { // public method
        if (amount > 0)
        {
            balance += amount;
        }
    }

    void withdraw(double amount)
    { // public method
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
        }
    }

    double getBalance()
    { // public method
        return balance;
    }
};

int main()
{
    BankAccount account;
    account.deposit(1000);
    account.withdraw(500);
    cout << "Current balance: " << account.getBalance() << endl; // Encapsulation
    return 0;
}