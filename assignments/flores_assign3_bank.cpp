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
    BankAccount(string fullName = "", int accNum = 0, double balance = 0.0, string accType = "");
    
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
BankAccount::BankAccount(string fullName, int accNum, double balance, string accType) {
    accHolderName = fullName;
    accountType = accType;
    accountNumber = accNum;
    accBalance = balance;
}

string BankAccount::GetAccHolderName() const {
    return accHolderName;
}

string BankAccount::GetAccountType() const {
    return accountType;
}

int BankAccount::GetAccountNumber() const {
    return accountNumber;
}

double BankAccount::GetAccBalance() const {
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
    CheckingAccount(string fullName = "", int accNum = 0, double balance = 0.0, int numChecks = 10, string accType = "");
    
    int GetChecksAvailable() const;
    /*pure virtual function*/
    virtual void WriteCheck() = 0;
    
private:
    int numOfChecks;
};

/*constructor*/
CheckingAccount::CheckingAccount(string fullName, int accNum, double balance, int numChecks, string accType)
:BankAccount(fullName, accNum, balance, accType) {
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
                      :CheckingAccount(fullName, accNum, balance, numChecks, accType) {
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
    double minBalanceCheck;
    double intRateCheck;
};

/*constructor*/
NoServiceChargeChecking::NoServiceChargeChecking(string fullName, int accNum, double balance, int numChecks, double mBalance, double iRate, string accType)                   :CheckingAccount(fullName, accNum, balance, numChecks, accType) {
    minBalanceCheck = mBalance;
    intRateCheck = iRate;
}

void NoServiceChargeChecking::WriteCheck() {
    
}

double NoServiceChargeChecking::GetIntRate() const {
    return intRateCheck;
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
    HighInterestChecking(string fullName = "", int accNum = 0, double balance = 0.0, int numChecks = 100, double mBalance = 50.0, double iRate = .05, string accType = "HighInterestChecking");
    
    void WriteCheck();
    void Print() const;
};

/*constructor*/
HighInterestChecking::HighInterestChecking(string fullName, int accNum, double balance, int numChecks, double mBalance, double iRate, string accType)
                     :NoServiceChargeChecking(fullName, accNum, balance, numChecks, mBalance, iRate, accType) {}

void HighInterestChecking::WriteCheck() {}

void HighInterestChecking::Print() const {
    cout << "Account Number:   " << GetAccountNumber() << endl;
    cout << "Account Type:     " << GetAccountType() << endl;
    cout << "Name:             " << GetAccHolderName() << endl;
    cout << "Balance:          " << GetAccBalance() << endl;
    cout << "Interest Rate:    " << GetIntRate() << endl;
    cout << "Remaining Checks: " << GetChecksAvailable() << endl;
}

//******************************************************************************
// Class SavingsAccount
//******************************************************************************

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string fullName = "", int accNum = 0, double balance = 0.0, double iRate = .02, string accType = "SavingsAccount" );
    
    double GetIntRateSave() const;
    void Print() const;
    
private:
    double intRateSave;
};

SavingsAccount::SavingsAccount(string fullName, int accNum, double balance, double iRate, string accType)
               :BankAccount(fullName, accNum, balance, accType) {
    intRateSave = iRate;
}

double SavingsAccount::GetIntRateSave() const {
    return intRateSave;
}

void SavingsAccount::Print() const {
    cout << "Account Number:   " << GetAccountNumber() << endl;
    cout << "Account Type:     " << GetAccountType() << endl;
    cout << "Name:             " << GetAccHolderName() << endl;
    cout << "Balance:          " << GetAccBalance() << endl;
    cout << "Interest Rate:    " << GetIntRateSave() << endl;
}

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
//    HighInterestChecking testingI("David Flores", 1234, 1000.00, 100, 50, .05);
//    testingI.Print();
    
    SavingsAccount testingII("David Flores", 1234, 1000.00);
    testingII.Print();
    
    return 0;
}
