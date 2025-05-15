#include <iostream>
#include <limits>
#include "BankSystem.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;

int main() {
    BankSystem bank;
    int choice;
    string name;
    int amount;

    while (true) {
        cout << "\n--- Mini Bank ---\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Print Transactions\n6. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                bank.createAccount(name);
                break;
            case 2:
                cout << "Enter name and amount: ";
                cin >> name >> amount;
                bank.deposit(name, amount);
                break;
            case 3:
                cout << "Enter name and amount: ";
                cin >> name >> amount;
                bank.withdraw(name, amount);
                break;
            case 4:
                cout << "Enter name: ";
                cin >> name;
                bank.checkBalance(name);
                break;
            case 5:
                cout << "Enter name: ";
                cin >> name;
                bank.printTransactions(name);
                break;
            case 6:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
