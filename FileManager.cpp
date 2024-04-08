// FileManager.cpp
// This file defines the FileManager class methods. The class handles reading and
// writing the account data to and from a specified file, thus persisting account
// states between executions of the program.
#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// Constructor that sets the file path to the provided path
FileManager::FileManager(const string& path) : filePath(path) {}

// Saves account data to a file in a specified format
void FileManager::saveAccountData(const vector<BankAccount>& accounts) {
    // Opens the file for writing and truncates it to start fresh
    ofstream outFile(filePath, ios::trunc);
    // Check if the file stream is in a good state
    if (!outFile) {
        // If not, print an error and return
        cerr << "Error opening file for writing: " << filePath << endl;
        return;
    } // end of if (!outFile)

    // Set the output format for floating-point numbers to fixed with 2 decimal places
    outFile << fixed << setprecision(2);

    // Iterate through each account in the vector
    for (const auto& account : accounts) {
        // Retrieve the balance using the account's getPin method
        double balance = account.getBalance(account.getPin());

        // Round the balance if it's within a reasonable range
        if (balance < 1e15) {
            balance = floor(balance * 100) / 100;  // Manual rounding to the nearest cent
        } // End of if (balance)

        // Write the account information to the file
        outFile << account.getAccountNumber() << ":"
                << balance << ","
                << account.getOwnerName() << ","
                << account.getOwnerAddress() << ","
                << account.getPin() << endl;  
    } // End of for (const)

    // Close the file after writing to it
    outFile.close();
} // End of void saveAccountData()

// Loads account data from a file and returns a vector of BankAccount objects
vector<BankAccount> FileManager::loadAccountData() {
    // Create an empty vector to store the accounts
    vector<BankAccount> accounts;
    // Open the file for reading
    ifstream inFile(filePath);
    // Check if the file stream is in a good state
    if (!inFile) {
        // If not, print an error and return an empty vector
        cerr << "Error opening file for reading: " << filePath << endl;
        return accounts;
    }// End of if (!inFile)

    accounts.clear(); // Clear existing accounts before loading new ones

    string line;

    // Read the file line by line
    while (getline(inFile, line)) {
        // Create a stringstream from the line, which helps in parsing the data
        istringstream iss(line);
        string balanceStr, accountNumberStr, pinStr, ownerName, ownerAddress;
        double balance;
        int accountNumber, pin; // Assuming PIN is not stored in the file


        // Parse the account number
        getline(iss, accountNumberStr, ':');
        accountNumber = stoi(accountNumberStr);

        // Parse the balance
        getline(iss, balanceStr, ',');
        balance = stod(balanceStr);

        // Parse the owner's name
        getline(iss, ownerName, ',');
        // Parse the owner's address
        getline(iss, ownerAddress, ',');

        // Parse the PIN
        getline(iss, pinStr, '\n');
        pin = stoi(pinStr);

        // Create a BankAccount object using the parsed data
        BankAccount account(accountNumber, ownerName, ownerAddress, balance, pin);
        // Add the account to the vector
        accounts.push_back(account);
    } // End of while (getline)

    inFile.close(); // Close the file after reading
    return accounts; // Return the vector of accounts
} // End of vector loadAccountData()
