//John-Paul King, Adam Sowder, Nabeel Janjua

#ifndef CHECKINGSACCOUNT_H
#define CHECKINGSACCOUNT_H
#include "BankAccount.h"

class CheckingsAccount : public BankAccount {

     public:

        CheckingsAccount();

        //Other constructor
        CheckingsAccount(double, double);

        //withdraw amount
        void withdraw(double);

        //Monthly maintenence
        void monthlyProc();

        private:

        //charge if attempted withdrawal makes account go negative
        const int NEGATIVE_CHARGE = 15;
        //monthly charge of account
        const int SERVICE_CHARGE = 5;
        //charge for every withdrawal
        const int WITHDRAWAL_CHARGE = .1;
};

//Default constructor
CheckingsAccount::CheckingsAccount() : BankAccount::BankAccount() {}

//Constructor with arguments
CheckingsAccount::CheckingsAccount(double a, double i) : BankAccount::BankAccount(a,i) {}

void CheckingsAccount::withdraw(double amount) {
    //if balance would go into negative
    if (BankAccount::balance-amount  < 0) {
        //add service charge, don't complete withdrawal
        BankAccount::monthlyServiceCharge += NEGATIVE_CHARGE; 
    } else {
        //withdraw amount
        BankAccount::withdraw(amount);
    }
}

void CheckingsAccount::monthlyProc() {
    //add 5$ charge every month
    BankAccount::monthlyServiceCharge += SERVICE_CHARGE;
    //add .10$ charge for every withdrawal
    BankAccount::monthlyServiceCharge += (BankAccount::numberOfWithdrawals * WITHDRAWAL_CHARGE);
    //Call base class method
    BankAccount::monthlyProc();
}



#endif // CHECKINGSACCOUNT_H