// investment.h (header file)

#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment {
public:
    Investment(double initialInvestment, double monthlyDeposit, double annualInterest, int years);
    void calculateInvestment();
    void displayInvestment();

private:
    double initialInvestment_;
    double monthlyDeposit_;
    double annualInterest_;
    int years_;
    double totalEarnedInterest_;
    double* yearEndBalances_;
    double* yearEndEarnedInterests_;
};

#endif


// investment.cpp (implementation file)

#include "investment.h"
#include <iostream>
#include <iomanip>
#include <limits>

Investment::Investment(double initialInvestment, double monthlyDeposit, double annualInterest, int years)
    : initialInvestment_(initialInvestment), monthlyDeposit_(monthlyDeposit),
    annualInterest_(annualInterest), years_(years), totalEarnedInterest_(0),
    yearEndBalances_(new double[years]), yearEndEarnedInterests_(new double[years])
{
}

void Investment::calculateInvestment() {
    double currentBalance = initialInvestment_;
    double yearlyInterestRate = annualInterest_ / 100;

    for (int year = 1; year <= years_; ++year) {
        double earnedInterest = currentBalance * yearlyInterestRate;
        totalEarnedInterest_ += earnedInterest;

        yearEndBalances_[year - 1] = currentBalance + earnedInterest;
        yearEndEarnedInterests_[year - 1] = earnedInterest;

        currentBalance += monthlyDeposit_;
    }
}

void Investment::displayInvestment() {
    std::cout << "Year\tYear End Balance\tYear End Earned Interest" << std::endl;
    for (int year = 1; year <= years_; ++year) {
        std::cout << year << "\t$" << std::fixed << std::setprecision(2)
            << yearEndBalances_[year - 1] << "\t\t$"
            << yearEndEarnedInterests_[year - 1] << std::endl;
    }
    std::cout << "Total Earned Interest: $" << totalEarnedInterest_ << std::endl;
}


// main.cpp

#include "investment.h"

bool isPositiveNumber(double value) {
    return value > 0;
}

bool isNonNegativeNumber(double value) {
    return value >= 0;
}

bool isInteger(double value) {
    return value == static_cast<int>(value);
}

int main()  {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int years;
}

    // Prompt the user for input values with input validation
    while (true) {
        std::cout << "Initial Investment Amount: $";
        if (std::cin >> initialInvestment && isNonNegativeNumber(initialInvestment)) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std);
    }