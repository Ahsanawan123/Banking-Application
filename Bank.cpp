#include "Bank.h"
#include "FileManager.h"

using namespace std;

// Constructor that loads account data from a specified file path
Bank::Bank(const std::string& filePath) : filePath(filePath) {
    this->loadAccountsFromFile(); // Load existing accounts from file at initialization
}

// Creates a new bank account and adds it to the accounts vector
void Bank::createAccount(const string& name, const string& address, double initialDeposit, int pin) {
    // Generate a new account number, incrementing from the last account's number
    int accountNumber = this->accounts.empty() ? 1 : this->accounts.back().getAccountNumber() + 1;
    // Create a new BankAccount object
    BankAccount newAccount(accountNumber, name, address, initialDeposit, pin);
    // Add the new account to the vector of accounts
    this->accounts.push_back(newAccount);
    // Save the updated accounts list to the file
    this->saveAccountsToFile();
}

// Deletes a bank account if the account exists and the PIN matches
bool Bank::deleteAccount(int accountNumber, int inputPin) {
    // Iterate over the accounts vector to find the matching account
    for (auto it = this->accounts.begin(); it != this->accounts.end(); ++it) {
        if (it->getAccountNumber() == accountNumber && it->getBalance(inputPin) != -1) {
            // Remove the account from the vector
            this->accounts.erase(it);
            // Save the updated accounts list to the file
            this->saveAccountsToFile();
            return true; // Return true if account was successfully deleted
        }
    }
    return false; // Return false if no matching account was found or if PIN was invalid
}

// Finds and returns a pointer to a BankAccount object, or nullptr if not found
BankAccount* Bank::findAccount(int accountNumber) {
    // Iterate over the accounts vector to find the matching account
    for (BankAccount& account : this->accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;  // Return a pointer to the found account
        }
    }
    return nullptr; // Return nullptr if no matching account was found
} 

// Displays the account numbers for all accounts
void Bank::displayAccounts() {
    // Iterate over the accounts vector and print each account's number
    for (const BankAccount& account : this->accounts) {
        cout << "Account Number: " << account.getAccountNumber() << endl;
    }
}

// Saves the current state of all accounts to a file
void Bank::saveAccountsToFile() {
    // Create a FileManager object with the current file path
    FileManager fileManager(this->filePath);
    // Use FileManager to save the accounts data to the file
    fileManager.saveAccountData(this->accounts);
}

// Loads account data from a file and updates the accounts vector
void Bank::loadAccountsFromFile() {
    // Create a FileManager object with the current file path
    FileManager fileManager(this->filePath);
    // Use FileManager to load account data from the file and update the accounts vector
    this->accounts = fileManager.loadAccountData();
}

// Processes a withdrawal from a specific account if the account exists and the PIN matches
bool Bank::withdrawFromAccount(int accountNumber, int inputPin, double amount) {
    // Find the account using the account number
    BankAccount* account = findAccount(accountNumber);
    // Check if the account was found
    if (account != nullptr) {
        // Attempt to withdraw the specified amount
        bool success = account->withdraw(amount, inputPin);
        if (success) {
            // Save the updated accounts list to the file if withdrawal was successful
            saveAccountsToFile();
        }
        return success; // Return the result of the withdrawal attempt
    }
    return false; // Return false if no matching account was found
}

// Processes a deposit to a specific account if the account exists
bool Bank::depositToAccount(int accountNumber, double amount) {
    // Find the account using the account number
    BankAccount* account = findAccount(accountNumber);
    if (account != nullptr && amount > 0) { // Check if the account was found and the amount is positive
        // Deposit the amount to the account
        account->deposit(amount);
        // Save the updated accounts list to the file
        saveAccountsToFile();
        return true; // Return true if the deposit was successful
    }
    return false; // Return false if no matching account was found or if the amount was not positive
}


// Transfers funds from one account to another if both accounts exist and the source account's PIN matches
bool Bank::transferFunds(int sourceAccNum, int destAccNum, int pin, double amount) {
    // Find the source and destination accounts using their account numbers
    BankAccount* sourceAcc = findAccount(sourceAccNum);
    BankAccount* destAcc = findAccount(destAccNum);

    // Check if both accounts were found
    if (!sourceAcc || !destAcc) {
        cout << "One or both account numbers are invalid." << endl;
        return false;
    }

    // Attempt the transfer from the source account
    if (sourceAcc->transfer(amount, pin)) {
        // If successful, deposit the amount into the destination account
        destAcc->deposit(amount);
        // Save the updated accounts list to the file
        saveAccountsToFile();
        return true;
    }
    // Return false if the transfer failed (e.g., due to an incorrect PIN or insufficient funds)
    return false;
}

// Displays detailed information about a specific account if the account exists and the PIN matches
bool Bank::displayAccountInfo(int accountNumber, int inputPin) {
    // Find the account using the account number
    BankAccount* account = findAccount(accountNumber);
    // Check if the account was found
    if (account != nullptr) {
        // Use getBalance with the PIN to verify access to the account
        if (account->getBalance(inputPin) != -1) {
            // Display account details
            cout << "\nAccount Number: " << account->getAccountNumber() << endl;
            cout << "Owner Name: " << account->getOwnerName() << endl;
            cout << "Owner Address: " << account->getOwnerAddress() << endl;
            cout << "Current Balance: $" << account->getBalance(inputPin) << endl;
            return true;
        }
        else {
            cout << "Invalid PIN." << endl;
        }
    }
    else {
        cout << "Account not found." << endl;
    }
    // Return false if the account was not found or if the PIN was incorrect
    return false;
}

// Changes the PIN for a specific account if the account exists and the old PIN is correct
bool Bank::changeAccountPin(int accountNumber, int oldPin, int newPin) {
    // Find the account using the account number
    BankAccount* account = findAccount(accountNumber);
    // Check if the account was found
    if (account != nullptr) {
        // Attempt to change the PIN
        return account->changePin(oldPin, newPin); // The changePin method returns true if the old PIN was correct and the change was successful
    }
    // Return false if the account was not found
    return false;
}



