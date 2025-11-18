#pragma once

// include header files
#include "Account.h"

class SavingAccount : public Account {
    private:
        int m_period; // in months
        float m_rate; // yearly interest rate in percentage
        int m_duration; // from last deposit or withdraw in months
    
    public:
        // Constructor
        SavingAccount();
        SavingAccount(const SavingAccount &other);   
        SavingAccount(float balance , int period , float rate);
    
    public:
        // Assigment operator 
        SavingAccount& operator = (SavingAccount other);

    public:
        // Method
        float CalculateInterest() const;
        void Deposit(float amount);
        bool Withdraw(float amount);
        void IncreaseDuration(int months = 1) { m_duration += months; }
    
    public:
        // Destructor 
        ~SavingAccount();
};