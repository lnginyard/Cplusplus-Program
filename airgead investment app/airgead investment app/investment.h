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

