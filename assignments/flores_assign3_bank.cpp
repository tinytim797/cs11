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

class bankAccount
{
private:
    string accHolderName;
    string accountType;
    int accountNumber;
    double accBalance;
public:
    bankAccount(string fullName = "", string accType = "", int accNum = 0, double balance = 0.0);
    string getAccHolderName() const;
    string getAccountType() const;
    int getAccountNumber() const;
    double getAccBalance() const;
    void deposit(double amount);
    void withdrawl(double amount);
    virtual void print() const = 0;
};

/*contructor*/
bankAccount::bankAccount(string fullName, string accType, int accNum, double balance) {
    accHolderName = fullName;
    accountType = accType;
    accountNumber = accNum;
    accBalance = balance;
}

string bankAccount::getAccHolderName() const{
    return accHolderName;
}

string bankAccount::getAccountType() const{
    return accountType;
}

int bankAccount::getAccountNumber() const{
    return accountNumber;
}

double bankAccount::getAccBalance() const{
    return accBalance;
}

void bankAccount::deposit(double amount) {
    accBalance += amount;
}

void bankAccount::withdrawl(double amount) {
    if (amount > accBalance) {
        cout << "Insufficent Funds. Account balance: " << accBalance << endl;
    } else {
        accBalance -= amount;
    }
}

//******************************************************************************
// Class checkingAccount (abstract class)
//******************************************************************************

class checkingAccount: public bankAccount
{
private:
    int numOfChecks;
public:
    checkingAccount(string fullName = "", string accType = "", int accNum = 0, double balance = 0.0, int numChecks = 10);
    int getChecksAvailable() const;
/*pure virtual function*/
    virtual void writeCheck() = 0;
};

/*constructor*/
checkingAccount::checkingAccount(string fullName, string accType, int accNum, double balance, int numChecks)
                :bankAccount(fullName, accType, accNum, balance) {
    numOfChecks = numChecks;
}

int checkingAccount::getChecksAvailable() const {
    return numOfChecks;
}

//******************************************************************************
// Class serviceChargeChecking
//******************************************************************************

class serviceChargeChecking: public checkingAccount
{
private:
    double minBalance;
    double intRate;
public:
    serviceChargeChecking(string fullName = "", string accType = "Service Charge Checking", int accNum = 0, double balance = 0.0, int numChecks = 10, double mBalance = 10.0, double iRate = .01);
    void writeCheck();
    double getIntRate() const;
    void print() const;
};

/*constructor*/
serviceChargeChecking::serviceChargeChecking(string fullName, string accType, int accNum, double balance, int numChecks, double mBalance, double iRate)
                      :checkingAccount(fullName, accType, accNum, balance, numChecks) {
    minBalance = mBalance;
    intRate = iRate;
}

void serviceChargeChecking::writeCheck() {
    
}

double serviceChargeChecking::getIntRate() const {
    return intRate;
}

void serviceChargeChecking::print() const {
    cout << "Account Number:   " << getAccountNumber() << endl;
    cout << "Account Type:     " << getAccountType() << endl;
    cout << "Name:             " << getAccHolderName() << endl;
    cout << "Balance:          " << getAccBalance() << endl;
    cout << "Interest Rate:    " << getIntRate() << endl;
    cout << "Remaining Checks: " << getChecksAvailable() << endl;
}

//******************************************************************************
// Class noServiceChargeChecking
//******************************************************************************

class noServiceChargeChecking: public checkingAccount
{
private:
public:
};

//******************************************************************************
// Class highInterestChecking
//******************************************************************************

class highInterestChecking: public checkingAccount
{
private:
public:
};

//******************************************************************************
// Class savingsAccount
//******************************************************************************

class savingsAccount: public bankAccount
{
private:
public:
};

//******************************************************************************
// Class highInterestSavings
//******************************************************************************

class highInterestSavings: public savingsAccount
{
private:
public:
};

//******************************************************************************
// Class certificateOfDeposit
//******************************************************************************

class certificateOfDeposit: public bankAccount
{
private:
public:
};

//******************************************************************************
// Main Function
//******************************************************************************

int main() {
    
    /*testing*/
    serviceChargeChecking myAccount("David Flores", "Service Charge Checking", 12, 1000.25, 10, 10.0, .01);
    myAccount.print();
    
    return 0;
}

