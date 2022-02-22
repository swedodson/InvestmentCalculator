//Author: Clay Dodson
//Date: 06/03/2021
//Description: This program will calculate interest over time by taking the initial investment amount and
//adding the monthly deposit, and computing annual interest over the inputted amount of years. 
//The user is able to adjust the initial amount, monthly deposit amount, annual interest amount, and number of years.
//The user can also see the results with and without deposits which are displayed as static reports.

#pragma once
#ifndef INVESTMENTS_H_
#define INVESTMENTS_H_

//Define the investments class
//This class has the variables t_investment, t_monthDeposit, t_rate, and t_years
//This class has the methods reportNoMonthlyDeposits() and reportWithMonthlyDeposits()
//This class will hold the user input and call methods which will use the user inputs to calculate annual interest and display a static report showing the interest over time.
class Investments {
//Define the public variables of the investments class and include destructor to deallocate memory for new user inputs
public:

    Investments(double t_investment, double t_monthDeposit, double t_rate, int t_years);
    virtual ~Investments();
    void reportNoMonthlyDeposits();
    void reportWithMonthlyDeposits();

//Define the private variables of the investments class. These variables will be inputted by the user.
private:

    double m_initialDeposit;
    double m_monthlyDeposit;
    double m_interestRate;
    int m_numYears;
};

#endif  //INVESTMENTS_H_
