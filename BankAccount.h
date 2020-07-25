//John-Paul King, Adam Sowder, Nabeel Janjua

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

//using namespace std;

class BankAccount
{
    public:
        //blank constructor
        BankAccount();
        //Normal constructor w/ balance and interest
        BankAccount(double, double);

        //~BankAccount();

        //deposit money
        void deposit(double amount);

        //withdraw money
        void withdraw(double);

        //calculate and add interest for month
        void calcInt();

        //Monthly account maintanence
        void monthlyProc();

        double getBalance();


    protected:
        //balance of account
        double balance;
        //number of deposits made this month
        int numberOfDeposits;
        //number of withdrawals this month
        int numberOfWithdrawals;
        // yearly interest rate
        double interestRate;
        //monthly charge for account
        double monthlyServiceCharge;
};

//Constructor with balance and interest rate
BankAccount::BankAccount(double b, double i) {
    //Assign interest rate and balance based on input
    balance = b;
    interestRate = i;

    //start these variables at 0
    numberOfDeposits, numberOfWithdrawals, monthlyServiceCharge = 0,0,0;

}

//Blank Constructor
//Set balance and interest rates to 0
BankAccount::BankAccount() {
    BankAccount(0,0);
}

void BankAccount::calcInt() {
    //Calculate interest and add it to balance
    balance += ((interestRate / 12) * balance);
}

//Withdraw an amount of money from an account
void BankAccount::withdraw(double amount) {
    //if negative value
    if (amount < 0) {
       // throw std::invalid_argument("Negative value");
    } else {
        //withdraw amount
        balance -= amount;
        //increase withdrawal counter
        numberOfWithdrawals++;
    }
}

void BankAccount::deposit(double amount) {
    //if negative
    if (amount < 0){
       // throw std::invalid_argument("Negative Value");
    }
    else {
        balance += amount;
        numberOfDeposits++;
    }
    
}

double BankAccount::getBalance(){
    return balance;
}

void BankAccount::monthlyProc() {
    //subtract service fee
    balance -= monthlyServiceCharge; 
    //add interest
    calcInt();
    //reset quantities
    numberOfDeposits, numberOfWithdrawals, monthlyServiceCharge = 0,0,0;

}

#endif // BANKACCOUNT_H
