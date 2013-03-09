//
//  flores_assign3_bank.cpp
//  Assignment 3 - Bank
//
//  Created by David Flores on 2/27/13.
//  Copyright (c) 2013 David Flores. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//******************************************************************************
// Class bankAccount (abstract class)
//******************************************************************************

class BankAccount {
public:
    BankAccount(string fullName = "", string accountType = "", int accountNumber = 0, double balance = 0.0);

    string GetAccountHolderName() const;
    string GetAccountType() const;

    int GetAccountNumber() const;
    double GetAccountBalance() const;

    void Deposit(double amount);
    void Withdraw(double amount);

    virtual void Print() const = 0;

private:
    int accountNumber;
    double accountBalance;

    string accountHolderName;
    string accountType;
};

/*contructor*/
BankAccount::BankAccount(string fullName, string accountType, int accountNumber, double balance) {
    this->accountHolderName = fullName;
    this->accountBalance = balance;
    this->accountNumber = accountNumber;
    this->accountType = accountNumber;
}

string BankAccount::GetAccountHolderName() const {
    return accountHolderName;
}

string BankAccount::GetAccountType() const {
    return accountType;
}

int BankAccount::GetAccountNumber() const {
    return accountNumber;
}

double BankAccount::GetAccountBalance() const {
    return accountBalance;
}

void BankAccount::Deposit(double amount) {
    accountBalance += amount;
}

void BankAccount::Withdraw(double amount) {
    if (amount > accountBalance) {
        cout << "Insufficent Funds. Account balance: " << accountBalance << endl;
    } else {
        accountBalance -= amount;
    }
}

//******************************************************************************
// Class checkingAccount (abstract class)
//******************************************************************************

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(string fullName = "", string accountType = "", int accountNumber = 0, double balance = 0.0, int numberOfChecks = 10);

    int GetChecksAvailable() const;

    virtual void WriteCheck() = 0;

private:
    int numberOfChecks;
};

/*constructor*/
CheckingAccount::CheckingAccount(string fullName, string accountType, int accountNumber, double balance, int numberOfChecks)
                :BankAccount(fullName, accountType, accountNumber, balance) {
    this->numberOfChecks = numberOfChecks;
}

int CheckingAccount::GetChecksAvailable() const {
    return this->numberOfChecks;
}

//******************************************************************************
// Class serviceChargeChecking
//******************************************************************************

class ServiceChargeChecking : public CheckingAccount {
public:
    ServiceChargeChecking(string fullName = "", string accountType = "Service Charge Checking", int accountNumber = 0, double balance = 0.0, int numberOfChecks = 10, double minBalance = 10.0, double interestRate = .01);
    void WriteCheck();

    double GetInterestRate() const;
    void Print() const;

private:
    double minimumBalance;
    double interestRate;
};

/*constructor*/
ServiceChargeChecking::ServiceChargeChecking(string fullName, string accountType, int accountNumber, double balance, int numberOfChecks, double minimumBalance, double interestRate)
                      : CheckingAccount(fullName, accountType, accountNumber, balance, numberOfChecks) {
    this->minimumBalance = minimumBalance;
    this->interestRate = interestRate;
}

void ServiceChargeChecking::WriteCheck() {

}

double ServiceChargeChecking::GetInterestRate() const {
    return interestRate;
}

void ServiceChargeChecking::Print() const {
    cout << "Account Number:   " << GetAccountNumber() << endl;
    cout << "Account Type:     " << GetAccountType() << endl;
    cout << "Name:             " << GetAccountHolderName() << endl;
    cout << "Balance:          " << GetAccountBalance() << endl;
    cout << "Interest Rate:    " << GetInterestRate() << endl;
    cout << "Remaining Checks: " << GetChecksAvailable() << endl;
}

//******************************************************************************
// Class noServiceChargeChecking
//******************************************************************************

class NoServiceChargeChecking : public CheckingAccount {
public:
private:
};

//******************************************************************************
// Class highInterestChecking
//******************************************************************************

class HighInterestChecking : public CheckingAccount {
private:
public:
};

//******************************************************************************
// Class savingsAccount
//******************************************************************************

class SavingsAccount: public BankAccount {
private:
public:
};

//******************************************************************************
// Class highInterestSavings
//******************************************************************************

class HighInterestSavings: public SavingsAccount {
private:
public:
};

//******************************************************************************
// Class certificateOfDeposit
//******************************************************************************

class CertificateOfDeposit: public BankAccount {
private:
public:
};

//******************************************************************************
// Main Function
//******************************************************************************

int main() {

    /*testing*/
    ServiceChargeChecking myAccount("David Flores", "Service Charge Checking", 12, 1000.25, 10, 10.0, .01);
    myAccount.Print();

    return 0;
}
