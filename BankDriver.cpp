//John-Paul King, Adam Sowder, Nabeel Janjua

// bank account header file should not need to be included in the driver 
//#include "BankAccount.h"

// Checking account currently unimplemented
#include "CheckingsAccount.h"

// include the savings account header file
#include "SavingsAccount.h"

// include both string and iostream for output / input purposes *UI
#include <iostream>
#include <string>

// our driver will use the standard namespace
using namespace std;




// method that helps the user create a checking account for testing purpposes
CheckingsAccount letsCreateACheckingAccount(){
    double start_balance = 0;
    double interest_rate = 0;
    string lcaca_input_debug = "";
    cout << endl << "Lets Create a Checking Account!" << endl;
    lcaca_input1:
    cout << "enter in the starting balance of your savings account: ";
    getline(cin, lcaca_input_debug);
    try
    {
        start_balance = stod(lcaca_input_debug);
    }
    catch(std::invalid_argument)
    {
        cout << endl << "Please enter an double value" << endl;
        goto lcaca_input1;
    }
    if (start_balance < 0){
        cout << endl << "please enter in a valid starting balance > 0" << endl;
        goto lcaca_input1;
    }

    lcaca_input2:
    cout << "enter in the interest rate of your savings account: ";
    getline(cin, lcaca_input_debug);
    try
    {
        interest_rate = stod(lcaca_input_debug);
    }
    catch(std::invalid_argument)
    {
        cout << endl << "Please enter an double value" << endl;
        goto lcaca_input2;
    }
    if (interest_rate < 0){
        cout << endl << "please enter in a valid interest rate > 0" << endl;
        goto lcaca_input2;
    }   
    return CheckingsAccount(start_balance, interest_rate);
}



// method that Helps the user create a savings account for testing purposes
SavingsAccount letsCreateASavingsAccount(){
    // param: N/A
    // return: SavingsAccount S

    // input variables
    double start_balance = 0;
    double interest_rate = 0;
    string lcaca_input_debug = "";

    // initial message
    cout << endl << "Lets Create a Savings Account!" << endl;
    
    // label for returning to if bad input is given
    lcasa_input1:
    cout << "enter in the starting balance of your checking account: ";
    getline(cin, lcaca_input_debug);
    try
    {
        // attempt to parse a double input from input string
        start_balance = stod(lcaca_input_debug);
    }
    // if a value cannot be parsed then we must handle the exception
    catch(std::invalid_argument)
    {
        cout << endl << "Please enter an double value" << endl;
        goto lcasa_input1;
    }
    if (start_balance < 0){
        cout << endl << "please enter in a valid starting balance > 0" << endl;
        goto lcasa_input1;
    }

    lcasa_input2:
    cout << "enter in the interest rate of your checking account: ";
    getline(cin, lcaca_input_debug);
    try
    {
        interest_rate = stod(lcaca_input_debug);
    }
    catch(std::invalid_argument)
    {
        cout << endl << "Please enter an double value" << endl;
        goto lcasa_input2;
    }
    if (interest_rate < 0){
        cout << endl << "please enter in a valid interest rate > 0" << endl;
        goto lcasa_input2;
    }  
    return SavingsAccount(start_balance, interest_rate);
}


void displayAccountMenu(CheckingsAccount &test_checkings, SavingsAccount &test_savings){
    cout << "select an account to preform a transaction or move onto next month" << endl;
    cout << "(1) Checking: " << test_checkings.getBalance() << endl;
    cout << "(2) Savings: " << test_savings.getBalance() << endl;
    cout << "(3) Continue to Next Month" << endl;
    cout << "(4) Exit" << endl;
       
}

void displayTransactionMenu(){
    cout << "Record a new transaction or return to the previous menu?" << endl;
    cout << "(1) Deposit" << endl;
    cout << "(2) Withdrawl" << endl;
    cout << "(3) Exit" << endl;
       
}

void chooseFromAccountMenu(){
    int transaction_selection = 0;
    string transaction_string = "";
    input_label:
    while (transaction_selection != 3){
        displayAccountMenu();
        getline(cin, transaction_string);
        try
        {
            transaction_selection = stoi(transaction_string);
        }
        catch(std::invalid_argument)
        {
            cout << endl << "Please enter an integer value" << endl;
            goto input_label;
        }

        if (transaction_selection < 1 || transaction_selection > 3)
            cout << endl << "please enter in a valid menu selection" << endl;
    }
}

void chooseFromTransactionMenu(){
int transaction_selection = 0;
    string transaction_string = "";
    input_label:
    while (transaction_selection != 3){
        displayTransactionMenu();
        getline(cin, transaction_string);
        try
        {
            transaction_selection = stoi(transaction_string);
        }
        catch(std::invalid_argument)
        {
            cout << endl << "Please enter an integer value" << endl;
            goto input_label;
        }

        if (transaction_selection < 1 || transaction_selection > 3)
            cout << endl << "please enter in a valid menu selection" << endl;
    }
}


int main(){
    SavingsAccount test_savings = letsCreateASavingsAccount();
    CheckingsAccount test_checkings = letsCreateACheckingAccount();

    return 0;
}