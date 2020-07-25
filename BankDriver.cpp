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


// enhanced input functions
        // function for getiting double input from user that handles potential errors
        double inputDouble(string prompt_string){
            string input_string;
            double input_double;
            
            input_label:
            cout << endl << prompt_string;
            getline(cin, input_string);
            try
            {
                input_double = stod(input_string);
            }
            catch(std::invalid_argument){
                cout << endl << "invalid argument: please enter a double value" << endl;
                goto input_label;
            }
            return input_double;
        }

        // function for getiting integer input from user that handles potential errors
        int inputInt(string prompt_string){
            string input_string;
            int input_int;

            input_label:
            cout << endl << prompt_string;
            getline(cin, input_string);
            try
            {
                input_int = stoi(input_string);
            }
            catch(std::invalid_argument){
                cout << endl << "invalid argument: please enter a integer value" << endl;
                goto input_label;
            }
            return input_int;
        }

        // function for inputing a positive double value with a given name - handles input errors and displays messages with name context
        double inputPositiveDouble(string input_name){
            double positive_double;

            input_label:
            positive_double = inputDouble("Enter " + input_name + ": ");
            if (positive_double < 0){
                cout << endl << "Invalid Input: " + input_name + " Must be Greater Than 0.00" << endl;
                goto input_label;
            }
            return positive_double;
        }
        
        // function for inputing a integer value with a max and a min - handles input errors and displays messages with context
        int inputBoundedIntegerOption(int min_option, int max_option){
            int bounded_int;

            input_label:
            bounded_int = inputInt("Enter Option: ");
            if (bounded_int < min_option || bounded_int > max_option){
                cout << endl << "Please Enter an Option Between " << min_option << " and " << max_option << endl;
                goto input_label;
            }
            return bounded_int;
        }


// savings and checkings account creation / modification
        // function that Helps the user create a savings account for testing purposes
        SavingsAccount letsCreateASavingsAccount(){

            // account opening message
            cout << endl << "Lets Create a Savings Account!" << endl;
            
            // get proper starting balance and interest rate
            double start_balance = inputPositiveDouble("Account Starting Balance");
            double interest_rate = inputPositiveDouble("Account Interest Rate");
            
            // return new savings account object
            return SavingsAccount(start_balance, interest_rate);
        }

        // function that Helps the user create a checkings account for testing purposes
        CheckingsAccount letsCreateACheckingsAccount(){
            
            // account opening message
            cout << endl << "Lets Create a Checkings Account!" << endl;
            
            // get proper starting balance and interest rate
            double start_balance = inputPositiveDouble("Account Starting Balance");
            double interest_rate = inputPositiveDouble("Account Interest Rate");
            
            // return new savings account object
            return CheckingsAccount(start_balance, interest_rate);
        }

        // preform monthly updates for both checkings and savings account
        void preformMonthlys(SavingsAccount &test_savings, CheckingsAccount &test_checkings){
            // preform monthly savings updates
            test_savings.monthlyProc();
            // preform monthly checkings updates
            test_checkings.monthlyProc();
        }

        // function for preforming savings deposit
        void preformSavingsDeposit(SavingsAccount &test_savings){
            double deposit_amount = inputPositiveDouble("Deposit Amount");
            test_savings.deposit(deposit_amount);
        }

        // function for preforming savings withdraw
        void preformSavingsWithdraw(SavingsAccount &test_savings){
            double withdraw_amount = inputPositiveDouble("Withdraw Amount");
            test_savings.withdraw(withdraw_amount);

        }

        // function for preforming checkings deposit
        void preformCheckingsDeposit(CheckingsAccount &test_checkings){
            double deposit_amount = inputPositiveDouble("Deposit Amount");
            test_checkings.deposit(deposit_amount);
        }

        // function for preforming checkings withdraw
        void preformCheckingsWithdraw(CheckingsAccount &test_checkings){
            double withdraw_amount = inputPositiveDouble("Withdraw Amount");
            test_checkings.withdraw(withdraw_amount);
        }

//UI Menu display functions
        // function for displaying savings transaction menu
        void displaySavingsTransactionMenu(SavingsAccount s){
            cout << endl << "Savings Account Balance = " << s.getBalance() << endl;
            cout << "Record a New Transaction or Return to the Previous Menu?" << endl;
            cout << "(1) Deposit" << endl;
            cout << "(2) Withdrawl" << endl;
            cout << "(3) Return to Accounts Menu" << endl;   
        }

        // functions for displaying checkings Transaction Menu
        void displayCheckingsTransactionMenu(CheckingsAccount c){
            cout << endl << "Checkings Account Balance = " << c.getBalance() << endl;
            cout << "Record a New Transaction or Return to the Previous Menu?" << endl;
            cout << "(1) Deposit" << endl;
            cout << "(2) Withdrawl" << endl;
            cout << "(3) Return to Accounts Menu" << endl;
        }

        // function for displaying accounts menu
        void displayAccountMenu( SavingsAccount s, CheckingsAccount c){
            cout << endl << "Select an Account for Transactions, Move To Next Month, or Exit" << endl;
            cout << "(1) Savings: " << s.getBalance() << endl;
            cout << "(2) Checkings: " << c.getBalance() << endl;
            cout << "(3) Continue to Next Month" << endl;
            cout << "(4) Exit" << endl;
        }

// UI Menu Selection Functions
        // function for choosing from savings transactions menu
        void chooseFromSavingsTransactionMenu(SavingsAccount &test_savings){
            choice_label:
            displaySavingsTransactionMenu(test_savings);
            int choice = inputBoundedIntegerOption(1, 3);
            switch(choice) {
                case 1:
                    preformSavingsDeposit(test_savings);
                    break; 
                case 2:
                    preformSavingsWithdraw(test_savings);
                    break;
                case 3:
                    return;
                    break;
            }
            goto choice_label; 
        }
        // function for choosing from checkings transactions menu
        void chooseFromCheckingsTransactionMenu(CheckingsAccount &test_checkings){
            choice_label:
            displayCheckingsTransactionMenu(test_checkings);
            int choice = inputBoundedIntegerOption(1, 3);
            switch(choice) {
                case 1:
                    preformCheckingsDeposit(test_checkings);
                    break; 
                case 2:
                    preformCheckingsWithdraw(test_checkings);
                    break;
                case 3:
                    return;
                    break;
            }
            goto choice_label;
        }

        // function for choosing from account menu
        void chooseFromAccountMenu(SavingsAccount &test_savings, CheckingsAccount &test_checkings){
            choice_label:
            displayAccountMenu(test_savings, test_checkings);
            int choice = inputBoundedIntegerOption(1, 4);
            switch(choice) {
                case 1:
                    chooseFromSavingsTransactionMenu(test_savings);
                    break; 
                case 2:
                    chooseFromCheckingsTransactionMenu(test_checkings);
                    break;
                case 3:
                    preformMonthlys(test_savings, test_checkings);
                    break;
                case 4:
                    return;
                    break;
            }
            goto choice_label;
        }

int main(){
    // create a new savings and checkings account
    SavingsAccount test_savings = letsCreateASavingsAccount();
    CheckingsAccount test_checkings = letsCreateACheckingsAccount();  
    // Send User to Main Accounts Menu  
    chooseFromAccountMenu(test_savings, test_checkings);
    return 0;
}