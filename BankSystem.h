#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <string>
#include <map>
#include <vector>

class BankSystem {
private:
    std::map<std::string, int> accounts;
    std::map<std::string, std::vector<std::string>> transactionLogs;

public:
    void createAccount(const std::string& name);
    void deposit(const std::string& name, int amount);
    void withdraw(const std::string& name, int amount);
    void checkBalance(const std::string& name);
    void printTransactions(const std::string& name);
};

#endif
