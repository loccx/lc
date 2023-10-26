#include <iostream>

using namespace std;

typedef long long ll;

class Bank {
    private:
        class Account {
            private:
                ll id;
                string accountHolder;
                double amount;
            public:
                Account() {}
                Account(ll id, string name, double amount) : id(id), accountHolder(name), amount(amount) {}

                ll getId() {
                    return id;
                }

                string getName() {
                    return accountHolder;
                }

                double getAmount() {
                    return amount;
                }

                bool setAmount(double amount) {
                    if (amount > 0) {
                        this->amount = amount;
                        return true;
                    }
                    return false;
                }

                bool deposit(double amount) {
                    if (amount > 0) {
                        this->amount += amount;
                        cout << "Deposit of " << amount << " was made to " << accountHolder << "'s account.\n";
                        return true;
                    }
                    cout << "Deposit incomplete. Negative amount entered.\n";
                    return false;
                }

                bool withdraw(double amount) {
                    if (this->amount >= amount) {
                        this->amount -= amount;
                        cout << "Withdrawal of " << amount << " was made from " << accountHolder << "'s account.\n";
                        return true;
                    }
                    cout << "Withdrawal incomplete. Insufficient funds.\n";
                    return false;
                }
        }; 

        double reserves;
        unordered_map<ll, Account> accounts;
        ll currId;

    public:
        Bank() : currId(0) {}
        friend ostream& operator<<(ostream& os, Account& account) {
            cout  << account.getName() << ":\n";
            cout << "ID: " << account.getId() << '\n';
            cout << "Amount: $" << account.getAmount() << '\n';
            return os;
        }
        bool createAccount(string accountName, double amount);
        void deposit(ll id, double amount); 
        void withdraw(ll id, double amount);
        void transfer(ll source, ll destination, double amount);
        void showAccounts();
        void showReserves();
};

bool Bank::createAccount(string accountName, double amount) {
    if (amount < 0) {
        cout << "Initial amount can not be negative.\n";
        return false;
    }
    Account newAccount(currId, accountName, amount);
    accounts[currId] = newAccount;
    currId++;
    reserves += amount;
    return true;
}

void Bank::deposit(ll id, double amount) {
    if (accounts.count(id) == 0) {
        cout << "The ID you entered does not exist.\n";
        return;
    } 
    accounts[id].deposit(amount);
    reserves += amount;
} 

void Bank::withdraw(ll id, double amount) {
    if (accounts.count(id) == 0) {
        cout << "The ID you entered does not exist.\n";
        return;
    }
    accounts[id].withdraw(amount);
    reserves -= amount;
}

void Bank::transfer(ll source, ll destination, double amount) {
    if (accounts.count(source) && accounts.count(destination) && amount > 0 && accounts[source].withdraw(amount)) {
        accounts[destination].deposit(amount);
        cout << "Transfer Complete!\n";
    }
    else if (amount == 0) {
        cout << "Transfer Complete!\n";
    }
    else cout << "Transfer incomplete.\n";
}

void Bank::showAccounts() {
    for (auto k : accounts) {
        cout << k.second << '\n';
    }
}

void Bank::showReserves() {
    cout << "The bank currently holds: $" << reserves << '\n';
}

int main() {
    Bank capitalOne;
    ll id;
    ll idd;
    string command;
    string name;
    double amount;

    do {
        cout << "_________________________________________\n";
        cout << '\n';
        capitalOne.showAccounts();
        cout << "_________________________________________\n";
        cout << '\n';

        cout << "What would you like to do today?\n";
        cout << "********************************\n";
        cout << "NA : New Account\n";
        cout << "D : Deposit Money\n";
        cout << "W : Withdraw Money\n";
        cout << "T: Transfer from Account A to B\n";
        cout << "N: Close Bank\n";
        cout << "S: Show reserves\n";
        cout << "********************************\n";
        cout << '\n';

        cin >> command;
        cout << '\n';

        if (cin.fail()) {
            cin.clear(); // Clear the failure flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please try again.\n";
            continue; // Restart the loop
        }

        if (command == "N") {
            cout << "Have a nice day!\n";
        }

        else if (command == "NA") {
            cout << "What name would you like to name this account?\n";
            cin >> name;
            cout << "How much money would you like to initially deposit?\n";
            cin >> amount;
            capitalOne.createAccount(name, amount);
        }

        else if (command == "D") {
            cout << "What is the ID of your account?\n";
            cin >> id;
            cout << "How much money would you like to deposit?\n";
            cin >> amount;
            capitalOne.deposit(id, amount);
        }

        else if (command == "W") {
            cout << "What is the ID of your account?\n";
            cin >> id;
            cout << "How much money would you like to withdraw?\n";
            cin >> amount;
            capitalOne.withdraw(id, amount);
        }

        else if (command == "T") {
            cout << "What is the ID of the source account?\n";
            cin >> id;
            cout << "What is the ID of the destination account?\n";
            cin >> idd;
            cout << "How much money would you like to transfer?\n";
            cin >> amount;
            capitalOne.transfer(id, idd, amount);
        }
        
        else if (command == "S") {
            capitalOne.showReserves();
        }
    } while (command != "N");

    return 0;
}
