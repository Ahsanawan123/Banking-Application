// Bank.h
// Declaration of the Bank class, which acts as a central hub for managing multiple bank accounts.
// It contains methods for account creation, deletion, and transactions like deposits, withdrawals, and transfers.
#ifndef BANK_H
#define BANK_H

#include "BankAccount.h"
#include <vector>
#include <string>
using namespace std; // Ensure using namespace std is here for consistency

class Bank {
private:
    vector<BankAccount> accounts;  // Stores a dynamic array of BankAccount objects
    string filePath;               // File path for saving and loading account data


public:
    Bank(const string& filePath);
    void createAccount(const string& name, const string& address, double initialDeposit, int pin);
    bool deleteAccount(int accountNumber, int inputPin);
    BankAccount* findAccount(int accountNumber);
    void displayAccounts();
    void saveAccountsToFile();
    void loadAccountsFromFile();
    bool withdrawFromAccount(int, int, double);
    bool depositToAccount(int, double);
    bool transferFunds(int, int, int, double);
    bool displayAccountInfo(int, int);
    bool changeAccountPin(int, int, int);
};

#endif // BANK_H
