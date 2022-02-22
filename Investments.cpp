//Author: Clay Dodson
//Date: 06/03/2021
//Description: This program will calculate interest over time by taking the initial investment amount and
//adding the monthly deposit, and computing annual interest over the inputted amount of years. 
//The user is able to adjust the initial amount, monthly deposit amount, annual interest amount, and number of years.
//The user can also see the results with and without deposits which are displayed as static reports.

#include <iomanip>
#include <iostream>
#include "Investments.h"
using namespace std;

//Define the parameterized constructor 
//This constructor has the parameters t_investment, t_monthDeposit, t_rate, and t_years
//This constructor defines the privat variables to be used by the constructor
Investments::Investments(double t_investment, double t_monthDeposit, double t_rate, int t_years) {
    this->m_initialDeposit = t_investment;
    this->m_monthlyDeposit = t_monthDeposit;
    this->m_interestRate = t_rate;
    this->m_numYears = t_years;
}

//Define the destructor which will deallocate memory for new user inputs
Investments::~Investments() {
}

//This method will print the No Monthly Deposits Report which shows the user's investments with no monthly deposits
//The parameters of this method are reportNoMonthlyDeposits, currentyear, yearendBalance, and interestearned
//This method will print the heading for the report and table. 
//This method will also run a while loop to calculate the interest, add it to the balance, print the results, and increment the year.
void Investments::reportNoMonthlyDeposits() {

    //Print heading for report
    cout << "   Balance and Interest without additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;

    //Print heading for report table
    cout << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(35) << "Year End Earned Interest Rate" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    //Iterate while loop for given years and calculate interest earned
    int currentyear = 1;
    double yearendBalance = this->m_initialDeposit;  
    while (currentyear <= this->m_numYears) {
        //Calculate interest
        double interestearned = yearendBalance * this->m_interestRate / 100;
        //Add it to year end Balance
        yearendBalance += interestearned;
        //Print the results for each year
        cout << right << setw(10) << currentyear << fixed << setprecision(2)
            << setw(20) << yearendBalance
            << setw(35) << interestearned << endl;
        //Increase the year by one
        currentyear++;
    }
}

//This method will print the Monthly Deposits Report which shows the user's investments with monthly deposits
//The parameters of this method are reportWithMonthlyDeposits, month, currentyear, monthendBalance, yearendBalance, monthendBalance, and interestearned.
//This method will print the heading for the report and table. 
//This method will also run a while loop to calculate the interest, add it to the balance, print the results, and increment the year.
void Investments::reportWithMonthlyDeposits() {

    //Print heading
    cout << "   Balance and Interest without additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;

    //Print table heading
    cout << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(35) << "Year End Earned Interest Rate" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    //Iterate for given years and calculate interest earned
    int currentyear = 1;
    double yearendBalance = this->m_initialDeposit;

    while (currentyear <= this->m_numYears) {
        //calulate interest monthly and find compoud interest
        int month = 1;
        double interestearned = 0.0;
        double monthendbalance = yearendBalance;

        while (month <= 12) {
            //Add monthly deposit
            monthendbalance += this->m_monthlyDeposit;
            //Calculate monthly interest, interest rate is for annual. so divide the rate by 12
            double monthlyinterest = monthendbalance * this->m_interestRate / (100 * 12);
            //Add the monthly interest to yearly interest earned
            interestearned += monthlyinterest;
            //Add the interest to month end balance
            monthendbalance += monthlyinterest;
            //Increase the month by 1
            month++;
        }
        //After 12 months
        yearendBalance = monthendbalance;
        //Print the results
        cout << right << setw(10) << currentyear << fixed << setprecision(2)
            << setw(20) << yearendBalance
            << setw(35) << interestearned << endl;
        //Increase the year by one
        currentyear++;
    }
}