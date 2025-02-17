/*
Task
A C++ project is designed with an object-oriented approach, with classes for customers, accounts, transactions, and banking services. Features included creating and managing customers, accounts, and transactions, as well as performing banking services such as withdrawals, deposits, and transfers. It also allows customers to view their account information, including account balances, recent transactions, and other details.
*/
#include <iostream>
#include <vector>
#include <string>

class Customer {
public:
    Customer(std::string name, int id) : name(name), id(id) {}
    std::string getName() const { return name; }
    int getId() const { return id; }

private:
    std::string name;
    int id;
};

class Account {
public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}
    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) { if (amount <= balance) balance -= amount; }

private:
    int accountNumber;
    double balance;
};

class Transaction {
public:
    Transaction(int accountNumber, double amount, std::string type) 
        : accountNumber(accountNumber), amount(amount), type(type) {}
    int getAccountNumber() const { return accountNumber; }
    double getAmount() const { return amount; }
    std::string getType() const { return type; }

private:
    int accountNumber;
    double amount;
    std::string type;
};

class BankingService {
public:
    void addCustomer(const Customer& customer) { customers.push_back(customer); }
    void addAccount(const Account& account) { accounts.push_back(account); }
    void addTransaction(const Transaction& transaction) { transactions.push_back(transaction); }

    void deposit(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.deposit(amount);
                transactions.push_back(Transaction(accountNumber, amount, "Deposit"));
                break;
            }
        }
    }

    void withdraw(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.withdraw(amount);
                transactions.push_back(Transaction(accountNumber, amount, "Withdrawal"));
                break;
            }
        }
    }

    void transfer(int fromAccountNumber, int toAccountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == fromAccountNumber) {
                account.withdraw(amount);
                transactions.push_back(Transaction(fromAccountNumber, amount, "Transfer Out"));
                break;
            }
        }
        for (auto& account : accounts) {
            if (account.getAccountNumber() == toAccountNumber) {
                account.deposit(amount);
                transactions.push_back(Transaction(toAccountNumber, amount, "Transfer In"));
                break;
            }
        }
    }

    void viewAccountInfo(int accountNumber) const {
        for (const auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
                std::cout << "Balance: " << account.getBalance() << std::endl;
                break;
            }
        }
    }

    void viewRecentTransactions(int accountNumber) const {
        std::cout << "Recent Transactions for Account Number: " << accountNumber << std::endl;
        for (const auto& transaction : transactions) {
            if (transaction.getAccountNumber() == accountNumber) {
                std::cout << "Type: " << transaction.getType() << ", Amount: " << transaction.getAmount() << std::endl;
            }
        }
    }

private:
    std::vector<Customer> customers;
    std::vector<Account> accounts;
    std::vector<Transaction> transactions;
};

int main() {
    BankingService bank;

    Customer customer1("John Doe", 1);
    bank.addCustomer(customer1);

    Account account1(1001, 500.0);
    bank.addAccount(account1);

    bank.deposit(1001, 200.0);
    bank.withdraw(1001, 100.0);
    bank.viewAccountInfo(1001);
    bank.viewRecentTransactions(1001);

    return 0;
}