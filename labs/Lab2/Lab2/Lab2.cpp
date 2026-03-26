/*
Lab Two
Demetris Lincoln
COSC 1436 - Spring 2026
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

void main()
{
    // First three variables for loan amount, interest, and payment.
    int loanAmount;
    double interestRatePercentage;
    double monthlyPayment;

    // Variables for calulations in the table presented below.
    double balance;
    double interest = 0;
    double newBalance = 0;

    // Final calculations for total interest & total payments. 
    double totalInterest = 0;
    double totalPayments = 0;

    // Intro to the lab
    std::cout << "Lab Two" << std::endl;
    std::cout << "Demetris Lincoln" << std::endl;
    std::cout << "COSC 1436 - Spring 2026" << std::endl;

    std::cout << std::endl;

    // Loan amount prompt
    std::cout << "Please enter your loan amount: ";
    std::cin >> loanAmount;

    // While loop to ensure user inputs the proper value for the loan amount.
    while (loanAmount < 1 || loanAmount > 1000)
    {
        std::cout << "Invalid Input. Enter a value between (1 - 1000): ";
        std::cin >> loanAmount;
    }

    // Prompting user for interest rate.
    std::cout << "Enter Your Interest Rate (%): ";
    std::cin >> interestRatePercentage;

    // While loop to ensure user inputs the proper value for the interest rate. 
    while (interestRatePercentage < 1.0 || interestRatePercentage > 100.0)
    {
        std::cout << "Invalid Input. Enter a value between (1 - 100): ";
        std::cin >> interestRatePercentage;

        std::cout << std::endl;
    }
    // Conversion of standard integer into decimal value.
    interestRatePercentage = (interestRatePercentage / 100.0);

    
    // Promping the user for monthly payment.
    std::cout << "How much are you paying monthly?: ";
    std::cin >> monthlyPayment;

    std::cout << std::endl;

    // While loop to ensure inputs the proper value for monthly payments. 
    while (monthlyPayment < 0.0 || monthlyPayment > loanAmount)
    {
        std::cout << "Invalid Input. Enter your monthly payment (0 - Loan Amount): ";
        std::cin >> monthlyPayment;

        std::cout << std::endl;
    }

    // Table setup displaying the month, balance, payment, interest, and the new balance. 
    std::cout << std::left << std::fixed;
    std::cout << std::setprecision(2);

    // Table headers & line
    std::cout << std::setw(10) << "Month " << std::setw(13) << "Balance " << std::setw(13) << "Payment " << std::setw(13) << "Interest " << std::setw(20) << "New Balance " << std::endl;
    std::cout << std::setfill('-') << std::setw(65) << "" << std::setfill(' ') << std::endl;

    balance = loanAmount;

    // For loop for the 12 months of the year. 
    for (int month = 1; month <= 12; ++month)
    {
        if (month == 1)
        {
            interest = 0;
            newBalance = balance;
        } 
        else
        {
            // Caps the payment at the remaining balance
            if (monthlyPayment > balance)
                monthlyPayment = balance;

            // Subtracting the payment first
            balance = (balance - monthlyPayment);
            if (balance == 0)
            {
                balance = 0;
                interest = 0;
                newBalance = 0;
            }        
            else
            {
                interest = balance * interestRatePercentage;
                newBalance = balance + interest;
            }
        }

        // Displays the rows for the table
        std::cout << std::setw(9) << month
            << " $ " << std::setw(10) << balance
            << " $ " << std::setw(10) << (month == 1 ? 0.0 : monthlyPayment)
            << " $ " << std::setw(10) << interest
            << " $ " << std::setw(10) << newBalance
            << std::endl;

        // Total interest & payment calculations
        totalInterest += interest;
        totalPayments += (month == 1 ? 0.0 : monthlyPayment);
        balance = newBalance;
    }

    // Total interest & payment display for the user 
    std::cout << std::endl;
    std::cout << "Total Payments: $ " << totalPayments << std::endl;
    std::cout << "Total Interest: $ " << totalInterest << std::endl;
}
