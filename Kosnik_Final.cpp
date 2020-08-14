// Kelsey Kosnik, CSPB1300 Final Project. ATM Machine, Dec 9th 2019

// allows us to get user input
#include <iostream>
#include <string>

//using the standard namespace
using namespace std;

//declaring starter balances for our accounts
double checking = 1000, savings = 2000;

// user's pin number
int pin;

//creating three pointer variables, one for a savings accout, one for checking, and one for the user's pin
double *s_account_pointer = &savings; 
double *c_account_pointer = &checking;
int *pin_pointer = &pin;

//creating a variable for the users input
double user_prompt;



// function for the account deposit that takes a pointer input and adds the user's input to that pointer
void deposit (double *current_balance)
{
    cout << "Enter deposit amount: $";
    cin >> user_prompt;
    *current_balance = *current_balance + user_prompt;
    return;
}

// function for account withdrawl that takes a pointer input and subtracts the user's input to that pointer
void withdrawal (double *current_balance)
{
    cout << "Enter withdrawal amount: $";
    cin >> user_prompt;
    *current_balance = *current_balance - user_prompt;
    return;
}

// function for account transfer that takes two account pointers, one from and one to, and moves money
// from one account to the next
void transfer(double *account_from, double *account_to)
{
    cout << "Enter transfer amount: $";
    cin >> user_prompt;
    *account_from = *account_from - user_prompt;
    *account_to = *account_to + user_prompt;
    return;
}

// function to change pin that takes the pointer of your current pin, and replaces it with the value of the new one
// checks to ensure that you know your current pin before you can change it and re-prompts if it is entered incorrectly
void pin_change(int *current_pin)
{
    cout << "Please enter your current PIN: ";
    cin >> user_prompt;
    while(*current_pin != user_prompt)
    {
        cout << "Sorry, that is incorrect. Please try again: ";
        cin >> user_prompt;
    }
    cout << "\n";
    cout << "What would you like your new PIN to be: ";
    cin >> *current_pin;
    cout << "\n";
    cout << "Your pin has been changed" << endl << endl;
    return;
}



int main(){
    
    int menuchoice = 0; // initialize the first menuchoice to work with the while loop
    int pin = 0000; // initialize the pin 
    
    // prompt user for their pin
    cout << "Welcome to the Bank of Colorado! Please enter your PIN: ";
    cin >> user_prompt;
    
    // while loop that checks to make sure the user's input matches the PIN in the code. If not, re-prompt the user until it's correct
    while(user_prompt != pin)
    {
        cout << "Sorry, that pin is incorrect. Please try again: ";
        cin >> user_prompt;
    }
    
    cout << "\n";
    
    // starts a while loop that allows us to loop through the menu several times until
    // the user is ready to exit by selecting 6
    while (menuchoice != 6)
    {
        // main menu code that asks for a user's choice
        cout << "Main Menu: " << endl << "1) Deposit" << endl << "2) Withdrawal" << endl;
        cout << "3) Transfer" << endl << "4) Balance Inquiry" << endl << "5) PIN change" << endl << "6) Exit" << endl;
        cout << "Enter your menu selection: ";
        cin >> menuchoice;
        cout << "\n";

        // sets up all the different options the user can select. If the user inputs any other number 
        // than 1 - 6, they will be asked the pick a different number
        switch (menuchoice)
        {
            // If the user chooses deposit, run through the deposit function for either checking or savings
            case 1:
                cout << "Deposit to: " << endl << "1) Checking" << endl << "2) Savings" << endl;
                cout << "Enter account choice: ";
                cin >> menuchoice;
                cout << "\n";
                
                // checks to make sure the user's input is valid
                while (menuchoice > 2)
                {
                    cout << "Please enter in a valid account number: ";
                    cin >> menuchoice;
                }
                cout << "\n";
                
                // if the user picks checking, run deposit function with the checking account and print balance
                if (menuchoice == 1)
                {
                    cout << "Current checking balance: $" << *c_account_pointer << endl;
                    deposit(&checking);
                    cout << "New balance: $" << *c_account_pointer << endl;

                }
                
                // if savings, run through the deposit function with the savings and print balance
                else if (menuchoice == 2)
                {
                    cout << "Current savings balance: $" << *s_account_pointer << endl;
                    deposit(&savings);
                    cout << "New balance: $" << *s_account_pointer << endl;
                }
                cout << "\n";
                break;
            
            // if the user chooses 2, run through the withdrawal function for both checking or savings accounts
            case 2:
                cout << "Withdrawal from: " << endl << "1) Checking" << endl << "2) Savings" << endl;
                cout << "Enter account choice: ";
                cin >> menuchoice;
                cout << "\n";
                
                // checks to make sure the user's input is valid
                while (menuchoice > 2)
                {
                    cout << "Please enter in a valid account number: ";
                    cin >> menuchoice;
                }
                cout << "\n";
                
                // if checking, run through the withdrawal function with the checking account and print balance
                if (menuchoice == 1)
                {
                    cout << "Current checking balance: $" << *c_account_pointer << endl;
                    withdrawal(&checking);
                    cout << "New balance: $" << *c_account_pointer << endl;
                }
                
                // if savings, run through withdrawal function with the savings account and print balance
                else if (menuchoice == 2)
                {
                    cout << "Current savings balance: $" << *s_account_pointer << endl;
                    withdrawal(&savings);
                    cout << "New balance: $" << *s_account_pointer << endl;
                }
                cout << "\n";
                break;
                
            // if the user chooses 3, start the transfer process. This includes choosing which account
            // you'd like to transfer from and what account you'd like to transfer to. Built in safety
            // choice so the user cannot transfer to and from the same account without an error
            case 3:
                cout << "Transfer from:" << endl << "1) Checking" << endl << "2) Savings" << endl;
                cout << "Enter your account selection: ";
                cin >> menuchoice;
                cout << "\n";
                
                // checks to make sure the user's input is valid
                while (menuchoice > 2)
                {
                    cout << "Please enter in a valid account number: ";
                    cin >> menuchoice;
                }
                cout << "\n";
                
                // Option to transfer from checking to savings
                if (menuchoice == 1)
                {
                    cout << "Checking:" << endl << "Current balance: $" << *c_account_pointer << endl << endl;
                    cout << "Transfer to: " << endl << "1) Checking" << endl << "2) Savings" << endl;
                    cout << "Enter your accout selection: ";
                    cin >> menuchoice;
                    
                    // if the user enters in any other number except for the other account, re-prompt user
                    while (menuchoice !=2)
                    {
                        cout << "Please enter the correct account number: ";
                        cin >> menuchoice;
                    }
                    
                    cout << "\n";
                    cout << "Savings:" << endl << "Current balance: $" << *s_account_pointer << endl << endl;
                    transfer(&checking, &savings);
                    cout << "New checking balance: $" << *c_account_pointer << endl;
                    cout << "New savings balance: $" << *s_account_pointer << endl;
                }
                
                // Option to transfer from savings to checking
                else if (menuchoice == 2)
                {
                    cout << "Savings:" << endl << "Current balance: $" << *s_account_pointer << endl << endl;
                    cout << "Transfer to: " << endl << "1) Checking" << endl << "2) Savings" << endl;
                    cout << "Enter your account selection: ";
                    cin >> menuchoice;
                    
                    // if the user enters in any other number except 1 for checking, re-prompt user
                    while (menuchoice !=1)
                    {
                        cout << "Please enter the correct account number: ";
                        cin >> menuchoice;
                    }
                    cout << "\n";
                    cout << "Checking:" << endl << "Current balance: $" << *c_account_pointer << endl << endl;
                    transfer(&savings, &checking);
                    cout << "New checking balance: $" << *c_account_pointer << endl;
                    cout << "New savings balance: $" << *s_account_pointer << endl;
                }
                cout << "\n";
                break;
            
            // Balance inquiry function to get the current balances using pointers
            case 4:
                cout << "Balance of: " << endl << "1) Checking" << endl << "2) Savings" << endl;
                cout << "Enter your account selection: ";
                cin >> menuchoice;
                cout << "\n";
                
                while (menuchoice > 2)
                {
                    cout << "Please enter in a valid account number: ";
                    cin >> menuchoice;
                }
                cout << "\n";
                
                if (menuchoice == 1)
                {
                    cout << "Checking:" << endl << "Current balance: $" << *c_account_pointer << endl;
                }
                
                else if (menuchoice == 2)
                {
                    cout << "Savings: " << endl << "Current balance: $" << *s_account_pointer << endl;
                }
                cout << "\n";
                break;
            
            case 5:
                pin_change(&pin);
                break;
                
            // if the user wishes to exit, give them a nice send off
            case 6:
                cout << "Thank you for choosing Bank of Colorado" << endl;
                cout << "\n";
                break;
            
            // if the user enters in any other number except for 1-5, asks for another choice and will
            // run through the while loop again
            default:
                cout << "Sorry, please enter in a valid choice" << endl;
                cout << "\n";
                break;
         }
    }
    return 0;
}
