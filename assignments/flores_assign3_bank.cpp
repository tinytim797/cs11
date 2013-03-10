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
// Class BankAccount (abstract class)
//******************************************************************************

class BankAccount {
public:
    BankAccount(string fullName = "", string accType = "", int accNum = 0, double balance = 0.0);
    string GetAccHolderName() const;
    string GetAccountType() const;
    int GetAccountNumber() const;
    double GetAccBalance() const;
    void Deposit(double amount);
    void Withdrawl(double amount);
    virtual void Print() const = 0;
private:
    string accHolderName;
    string accountType;
    int accountNumber;
    double accBalance;
};

/*contructor*/
BankAccount::BankAccount(string fullName, string accType, int accNum, double balance) {
    accHolderName = fullName;
    accountType = accType;
    accountNumber = accNum;
    accBalance = balance;
}

string BankAccount::GetAccHolderName() const{
    return accHolderName;
}

string BankAccount::GetAccountType() const{
    return accountType;
}

int BankAccount::GetAccountNumber() const{
    return accountNumber;
}

double BankAccount::GetAccBalance() const{
    return accBalance;
}

void BankAccount::Deposit(double amount) {
    accBalance += amount;
}

void BankAccount::Withdrawl(double amount) {
    if (amount > accBalance) {
        cout << "Insufficent Funds. Account balance: " << accBalance << endl;
    } else {
        accBalance -= amount;
    }
}

//******************************************************************************
// Class CheckingAccount (abstract class)
//******************************************************************************

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(string fullName = "", string accType = "", int accNum = 0, double balance = 0.0, int numChecks = 10);
    int GetChecksAvailable() const;
    /*pure virtual function*/
    virtual void WriteCheck() = 0;
private:
    int numOfChecks;
};

/*constructor*/
CheckingAccount::CheckingAccount(string fullName, string accType, int accNum, double balance, int numChecks)
:BankAccount(fullName, accType, accNum, balance) {
    numOfChecks = numChecks;
}

int CheckingAccount::GetChecksAvailable() const {
    return numOfChecks;
}

//******************************************************************************
// Class ServiceChargeChecking
//******************************************************************************

class ServiceChargeChecking : public CheckingAccount {
public:
    ServiceChargeChecking(string fullName = "", int accNum = 0, double balance = 0.0, int numChecks = 10, double mServCharge = 10.00, string accType = "Service Charge Checking");
    void WriteCheck();
    void Print() const;
private:
    double monthServCharge;
};

/*constructor*/
ServiceChargeChecking::ServiceChargeChecking(string fullName, int accNum, double balance, int numChecks, double mServCharge, string accType)
                      :CheckingAccount(fullName, accType, accNum, balance, numChecks) {
    monthServCharge = mServCharge;
}

void ServiceChargeChecking::WriteCheck() {
    
}

void ServiceChargeChecking::Print() const {
    cout << "Account Number:   " << GetAccountNumber() << endl;
    cout << "Account Type:     " << GetAccountType() << endl;
    cout << "Name:             " << GetAccHolderName() << endl;
    cout << "Balance:          " << GetAccBalance() << endl;
    cout << "Remaining Checks: " << GetChecksAvailable() << endl;
}

//******************************************************************************
// Class NoServiceChargeChecking
//******************************************************************************

class NoServiceChargeChecking : public CheckingAccount {
public:
    NoServiceChargeChecking(string fullName = "", int accNum = 0, double balance = 0.0, int numChecks = 100, double mBalance = 10.0, double iRate = .01, string accType = "No Service Charge Checking");
    void WriteCheck();
    double GetIntRate() const;
    void Print() const;
private:
    double minBalance;
    double intRate;
};

/*constructor*/
NoServiceChargeChecking::NoServiceChargeChecking(string fullName, int accNum, double balance, int numChecks, double mBalance, double iRate, string accType)
                        :CheckingAccount(fullName, accType, accNum, balance, numChecks) {
    minBalance = mBalance;
    intRate = iRate;
}

void NoServiceChargeChecking::WriteCheck() {
    
}

double NoServiceChargeChecking::GetIntRate() const {
    return intRate;
}

void NoServiceChargeChecking::Print() const {
    cout << "Account Number:   " << GetAccountNumber() << endl;
    cout << "Account Type:     " << GetAccountType() << endl;
    cout << "Name:             " << GetAccHolderName() << endl;
    cout << "Balance:          " << GetAccBalance() << endl;
    cout << "Interest Rate:    " << GetIntRate() << endl;
    cout << "Remaining Checks: " << GetChecksAvailable() << endl;
}

//******************************************************************************
// Class HighInterestChecking
//******************************************************************************

class HighInterestChecking : public NoServiceChargeChecking {
public:
    HighInterestChecking(string fullName = "", int accNum = 0, double balance = 0.0, int numChecks = 100, double mBalance = 50.0, double iRate = .05, string accType = "No Service Charge Checking");
    void WriteCheck();
private:
};

/*constructor*/
HighInterestChecking::HighInterestChecking(string fullName, int accNum, double balance, int numChecks, double mBalance, double iRate, string accType) {}

void HighInterestChecking::WriteCheck() {
    
}

//******************************************************************************
// Class SavingsAccount
//******************************************************************************

class SavingsAccount : public BankAccount {
public:
private:
};

//******************************************************************************
// Class HighInterestSavings
//******************************************************************************

class HighInterestSavings : public SavingsAccount {
public:
private:
};

//******************************************************************************
// Class CertificateOfDeposit
//******************************************************************************

class CertificateOfDeposit : public BankAccount {
public:
private:
};

//******************************************************************************
// Main Function
//******************************************************************************

int main() {
    
    /*testing*/
//    ServiceChargeChecking myAccount("David Flores", "Service Charge Checking", 12, 1000.25, 10, 10.0, .01);
//    myAccount.Print();
    
    return 0;
}
