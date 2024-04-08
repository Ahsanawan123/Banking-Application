#include "BankAccount.h"

// Constructor implementation using 'this->' for member variables initialization
BankAccount::BankAccount(int accNum,  const string& name, const string& address, double initialBalance, int accPin) {
    this->accountNumber = accNum;    // Unique identifier for the account
    this->ownerName = name;          // Personal Identification Number for the account
    this->ownerAddress = address;    // Name of the account owner
    this->balance = initialBalance;  // Address of the account owner
    this->pin = accPin;              // Current balance of the account
}

// Accessor method implementations that return respective member variables
int BankAccount::getAccountNumber() const {
    return this->accountNumber;
}

string BankAccount::getOwnerName() const {
    return this->ownerName;
}

string BankAccount::getOwnerAddress() const {
    return this->ownerAddress;
}

int BankAccount::getPin() const {
    return this->pin;
}

// Retrieves the balance if the correct PIN is provided, otherwise indicates an invalid PIN
double BankAccount::getBalance(int inputPin) const {
    if (inputPin == this->pin) {
        return this->balance;
    }
    else {
        cout << "Invalid PIN." << endl;
        return -1;
    }
}

// Adds the specified amount to the balance if it is positive
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        this->balance += amount;
    }
    else {
        cout << "Invalid deposit amount." << endl;
    }
}

// Withdraws the specified amount from the balance if the PIN is correct and the funds are sufficient
bool BankAccount::withdraw(double amount, int inputPin) {
    if (inputPin == this->pin) {
        if (amount > 0 && this->balance >= amount) {
            this->balance -= amount;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        cout << "Invalid PIN." << endl;
        return false;
    }
}

// Changes the PIN if the old PIN provided is correct
bool BankAccount::changePin(int oldPin, int newPin) {
    if (oldPin == this->pin) {
        this->pin = newPin;
        return true;
    }
    else {
        cout << "Invalid PIN." << endl;
        return false;
    }
}

// Updates the account's address to the new address provided
void BankAccount::setAddress(const string& newAddress) {
    this->ownerAddress = newAddress;
    cout << "Address updated successfully." << endl;
}

// Transfers the specified amount if the PIN is correct and there are sufficient funds
bool BankAccount::transfer(double amount, int inputPin) {
    if (inputPin != this->pin) {
        cout << "Invalid PIN." << endl;
        return false;
    }
    else if (amount > this->balance) {
        cout << "Insufficient funds." << endl;
        return false;
    }
    this->balance -= amount; // Deduct the amount from the sender's account
    return true;
}


