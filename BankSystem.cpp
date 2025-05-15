#include "BankSystem.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void BankSystem::createAccount(const string& name) {
    if (accounts.find(name) == accounts.end()) {
        accounts[name] = 0;
        transactionLogs[name] = {};
        cout << "Account created for " << name << endl;
    } else {
        cout << "Account already exists." << endl;
    }
}

void BankSystem::deposit(const string& name, int amount) {
    if (accounts.find(name) != accounts.end()) {
        accounts[name] += amount;
        transactionLogs[name].push_back("Deposited ₹" + std::to_string(amount));
        cout << "Deposited ₹" << amount << " to " << name << "'s account." << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

void BankSystem::withdraw(const string& name, int amount) {
    if (accounts.find(name) != accounts.end()) {
        if (accounts[name] >= amount) {
            accounts[name] -= amount;
            transactionLogs[name].push_back("Withdrew ₹" + std::to_string(amount));
            cout << "Withdrew ₹" << amount << " from " << name << "'s account." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    } else {
        cout << "Account not found." << endl;
    }
}

void BankSystem::checkBalance(const string& name) {
    if (accounts.find(name) != accounts.end()) {
        cout << name << "'s balance: ₹" << accounts[name] << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

void BankSystem::printTransactions(const string& name) {
    if (transactionLogs.find(name) != transactionLogs.end()) {
        cout << "Transaction history for " << name << ":" << endl;
        for (const auto& entry : transactionLogs[name]) {
            cout << " - " << entry << endl;
        }
    } else {
        cout << "No transactions found or account does not exist." << endl;
    }
}
