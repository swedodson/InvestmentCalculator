//Author: Clay Dodson
//Date: 06/03/2021
//Description: This program will calculate interest over time by taking the initial investment amount and
//adding the monthly deposit, and computing annual interest over the inputted amount of years. 
//The user is able to adjust the initial amount, monthly deposit amount, annual interest amount, and number of years.
//The user can also see the results with and without deposits which are displayed as static reports.

#include <iostream>
#include "Investments.h"
using namespace std;

//define the main driver
int main() {

    //initialize while loop to iterate through input prompts
    while (1) {

        //Print heading
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: " << endl;
        cout << "Monthly Deposit: " << endl;
        cout << "Annual Interest: " << endl;
        cout << "Number of years: " << endl;

        //System pauses to prompt user to press enter to start inputting data
        system("read -p 'Press Enter to continue . . .' var");
        cout << endl;

        //Print first part of heading before prompting user for input
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: $";

        //Define local variables 
        double t_investment, t_monthlydeposit, t_interestrate;
        int t_years;

        //Prompt user for input and print heading for next input
        cin >> t_investment;
        cout << "Monthly Deposit: $";
        cin >> t_monthlydeposit;
        cout << "Annual Interest: %";
        cin >> t_interestrate;
        cout << "Number of years: ";
        cin >> t_years;

        //System pauses to prompt user to press enter to start inputting data
        system("read -p 'Press Enter to continue . . .' var");

        //Create savings object using the given inputs
        Investments mysavings = Investments(t_investment, t_monthlydeposit, t_interestrate, t_years);
        cout << endl;

        //Call the method for No Monthly Deposit Report
        mysavings.reportNoMonthlyDeposits();
        cout << endl;

        //Call the method for the Monthly Deposit Report as long as it has monthly deposit at least $1 to avoid exceptions
        if (t_monthlydeposit > 0) {
            mysavings.reportWithMonthlyDeposits();
        }

        //Prompt the user to try another report or exit the program
        cout << endl << "Do you want to try another? (y/n): ";
        string choice;
        cin >> choice;

        //If user does not want to try another report, then end the loop
        if (choice != "y") {
            break;
        }
        cout << endl;
    }
    return 0;
}