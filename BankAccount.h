// BankAccount.h
// Declaration of the BankAccount class, which represents a model of a bank account.
// It contains private member variables for account details and public methods for account operations.
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    int pin;
    string ownerName;
    string ownerAddress;
    double balance;

public:
    BankAccount(int accNum, const string& name, const string& address, double initialBalance, int accPin);

    int getAccountNumber() const;
    string getOwnerName() const;
    string getOwnerAddress() const;
    int getPin() const;
    double getBalance(int inputPin) const;

    void deposit(double amount);
    bool withdraw(double amount, int inputPin);
    bool changePin(int oldPin, int newPin);
    void setAddress(const string& newAddress);
    bool transfer(double, int);
};

#endif // BANKACCOUNT_H
