#include "Bank.h"
#include <iostream>
#include <limits> // For numeric_limits
using namespace std;

int main() {
    Bank bank("Accounts.txt"); // Initialize bank object to store and utilize the accounts on file
                               // for more info, check the Readme

    while (true) {
        // Display the main menu options
        cout << "\n----------------------------------\n";
        cout << "| Banking System Main Menu       |\n";
        cout << "|--------------------------------|\n";
        cout << "| 1. Create account              |\n";
        cout << "| 2. Delete account              |\n";
        cout << "| 3. Withdraw                    |\n";
        cout << "| 4. Deposit                     |\n";
        cout << "| 5. Transfer                    |\n";
        cout << "| 6. Balance & Account Info      |\n";
        cout << "| 7. Change Pin                  |\n";
        cout << "| 8. Exit                        |\n";
        cout << "----------------------------------\n";
        cout << "Select an option: ";

        // Variables for user input
        int choice = 0;
        int accountNumber = 0;
        int pin = 0;
        double amount = 0.0;

        // Read user's menu choice
        cin >> choice;

        // Process user's choice
        switch (choice) {
        case 1: {
            // Create a new account
            string name, address;
            double deposit = 0;
            int pin = 0;

            // Clear input buffer before taking string input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Gather account details from user
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter initial deposit: ";
            cin >> deposit;
            cout << "Enter PIN: ";
            cin >> pin;

            // Create the account using provided details
            bank.createAccount(name, address, deposit, pin);
            cout << "Account created successfully.\n";
            break;
        }
        case 2: {
            accountNumber = 0;
            pin = 0;

            // Delete an existing account
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter PIN: ";
            cin >> pin;

            // Attempt to delete the account
            if (bank.deleteAccount(accountNumber, pin)) {
                cout << "Account deleted successfully.\n";
            }
            else {
                cout << "Failed to delete account.\n";
            }
            break;
        }
        case 3: {
            // Withdraw
            accountNumber = 0;
            pin = 0;
            amount = 0.0;

            // Withdraw funds from an account
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter PIN: ";
            cin >> pin;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            // Attempt to withdraw
            if (!bank.withdrawFromAccount(accountNumber, pin, amount)) {
                cout << "\nInvalid withdrawal amount or insufficient funds.\nWithdrawal failed.\n";
            }
            else {
                cout << "\nWithdrawal successful.\nAccnt: " << accountNumber << "\nAmount: $" << amount << "\n";
            }
            break;
        }
        case 4: {
            // Deposit    
            accountNumber = 0;
            amount = 0.0;

            // Deposit funds into an account
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter amount to deposit: ";
            cin >> amount;

            // Attempt to deposit
            if (bank.depositToAccount(accountNumber, amount)) {
                cout << "\nDeposit successful.\nAccnt: " << accountNumber << "\nAmount: $" << amount << "\n";
            }
            else {
                cout << "\nDeposit failed. Make sure the account number is correct and the amount is positive.\n";
            }
            break;
        }
        case 5: {
            // Transfer funds between two accounts
            int destAccNum = 0;
            cout << "Enter source account number: ";
            cin >> accountNumber;
            cout << "Enter destination account number: ";
            cin >> destAccNum;
            cout << "Enter PIN for source account: ";
            cin >> pin;
            cout << "Enter amount to transfer: ";
            cin >> amount;

            // Attempt to transfer
            if (bank.transferFunds(accountNumber, destAccNum, pin, amount)) {
                cout << "\nTransfer successful from account " << accountNumber << " to account " << destAccNum << ".\n";
            }
            else {
                cout << "\nTransfer failed.\n";
            }
            break;
        }
        case 6: {
            // Display information for a specific account
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter PIN: ";
            cin >> pin;

            // Attempt to display account info
            if (!bank.displayAccountInfo(accountNumber, pin)) {
                cout << "Failed to display account information.\n";
            }
            break;
        }
        case 7: {
            // Change the PIN for an account
            int oldPin, newPin;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter current PIN: ";
            cin >> oldPin;
            cout << "Enter new PIN: ";
            cin >> newPin;

            // Attempt to change PIN
            if (bank.changeAccountPin(accountNumber, oldPin, newPin)) {
                cout << "\nPIN changed successfully.\n";
            }
            else {
                cout << "\nPIN change failed.\n";
            }
            break;
        }
        case 8:
            // Exit the program
            cout << "Thank you for using the Banking System.\n";
            return 0;
        default:
            // Handle invalid menu choices
            cout << "Invalid option selected. Please try again.\n";
            break;
        }

        // Clear input buffer to handle next input correctly
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
