//John-Paul King, Adam Sowder, Nabeel Janjua

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"

class SavingsAccount : public BankAccount {

    private:
    //if true account is active
    //if false, inactive
    bool status;

    public:
    //invalid account exception
    class InactiveAccount {};
    //default constructor
    SavingsAccount();

    //Other constructor
    SavingsAccount(double, double);

    //withdraw amount
    void withdraw(double);

    //deposit amount
    void deposit(double);

    //Monthly maintenence
    void monthlyProc();
    //minimum account balance before account becomes inactive
    const int ACTIVE_LIMIT = 25;
    //Amount of withdrawals allowed before additional charges
    const int WITHDRAWALS_BEFORE_CHARGE = 4;

};

//Default constructor
SavingsAccount::SavingsAccount() : BankAccount::BankAccount() {
    //because starting balance is 0, account starts inactive
    status = false;
}

//Constructor with arguments
SavingsAccount::SavingsAccount(double a, double i) : BankAccount::BankAccount(a,i) {
    //check balance to detirmine if account is active
    if (BankAccount::balance >= ACTIVE_LIMIT) {
        status = true;
    } else {
        status = false;
    }
}

void SavingsAccount::withdraw(double amount) {
    //if account active
    if (status) {
        //call base function
        BankAccount::withdraw(amount);
    } else {
        throw InactiveAccount();
    }
}

void SavingsAccount::deposit(double amount) {
    BankAccount::deposit(amount);
    //check if above 25
    if (BankAccount::balance >= ACTIVE_LIMIT) {
        //acount active
        status = true;
    }
}

void SavingsAccount::monthlyProc() {
    if (BankAccount::numberOfWithdrawals > WITHDRAWALS_BEFORE_CHARGE) {
        //monthly service charge of 1$ for every withdrawal over 4
        BankAccount::monthlyServiceCharge += (BankAccount::numberOfWithdrawals-WITHDRAWALS_BEFORE_CHARGE);
    }
    BankAccount::monthlyProc();
    //check if account still valid
    if (BankAccount::balance < ACTIVE_LIMIT) {
        status = false;
    }
    
}

#endif // SAVINGSACCOUNT_H