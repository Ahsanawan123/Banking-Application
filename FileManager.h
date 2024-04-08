// FileManager.h
// This file declares the FileManager class, which is responsible for file operations
// associated with bank accounts. It provides functionality to save account data
// to a file and load account data from a file
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "BankAccount.h"
#include <vector>
#include <string>

using namespace std;

class FileManager {
private:
    string filePath;

public:
    FileManager(const string& path);
    void saveAccountData(const vector<BankAccount>& accounts);
    vector<BankAccount> loadAccountData();
};

#endif // FILEMANAGER_H
