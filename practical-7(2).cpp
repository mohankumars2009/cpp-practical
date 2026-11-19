
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Base custom exception class
class BankException : public exception
{
protected:
    string message;

public:
    BankException(string msg)
    {
        message = msg;
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

// Derived exception class
class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException()
        : BankException("Error: Insufficient balance for withdrawal.")
    {
    }
};

// Another derived exception class
class InvalidAmountException : public BankException
{
public:
    InvalidAmountException()
        : BankException("Error: Amount must be greater than zero.")
    {
    }
};

// Bank Account class
class BankAccount
{
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b)
    {
        name = n;
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        if (amount > balance)
            throw InsufficientFundsException();

        balance -= amount;
    }

    void display()
    {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    string name;
    double balance, depositAmount, withdrawAmount;

    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> balance;

    BankAccount account(name, balance);

    cout << "\nInitial Account Details:";
    account.display();

    try
    {
        cout << "\nEnter Deposit Amount: ";
        cin >> depositAmount;

        account.deposit(depositAmount);

        cout << "Deposit Successful!" << endl;

        cout << "\nEnter Withdrawal Amount: ";
        cin >> withdrawAmount;

        account.withdraw(withdrawAmount);

        cout << "Withdrawal Successful!" << endl;
    }

    catch (const InsufficientFundsException &e)
    {
        cout << e.what() << endl;
    }

    catch (const InvalidAmountException &e)
    {
        cout << e.what() << endl;
    }

    catch (const BankException &e)
    {
        cout << "Bank Exception: " << e.what() << endl;
    }

    catch (const exception &e)
    {
        cout << "General Exception: " << e.what() << endl;
    }

    cout << "\nFinal Account Details:";
    account.display();

    return 0;
}
