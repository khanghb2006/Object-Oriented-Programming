#include <iostream>
#include <utility>

// include header files
#include "SavingAccount.h"

// Constructor
SavingAccount::SavingAccount() :
    Account() , m_period(0) , m_rate(0) , m_duration(0) {}

SavingAccount::SavingAccount(const SavingAccount &other) :
    Account(other) , m_period(other.m_period) , m_rate(other.m_rate) , m_duration(other.m_duration) {}

SavingAccount::SavingAccount(float balance , int period , float rate) {
    if (balance < 0 || period < 0 || rate < 0)
        throw std::invalid_argument("Balance, period, and rate must be non-negative");
    Account::operator = (Account(balance));
    m_period = period;
    m_rate = rate;
    m_duration = 0;
}

// Assigment operator
SavingAccount& SavingAccount::operator = (SavingAccount other) {
    Account::operator = (other);
    std::swap(m_period , other.m_period);
    std::swap(m_rate , other.m_rate);
    std::swap(m_duration , other.m_duration);
    return *this;
}

// Method
float SavingAccount::CalculateInterest() const {
    //count how many complete periods have passed
    int complete_periods = m_duration / m_period;
    // calculate new rate after compounding for complete periods
    double new_rate = 1;
    for (int i = 0; i < complete_periods; i++) 
        new_rate *= (1 + (m_rate / 100.0) * (m_period / 12.0));
    return Account::getBalance() * (new_rate - 1);
}

void SavingAccount::Deposit(float amount) {
    // first update the m_balance with interest
    Account::Deposit(CalculateInterest());

    // then deposit the new amount
    Account::Deposit(amount);
    m_duration = 0;
}

bool SavingAccount::Withdraw(float amount) {
    // first update the m_balance with interest
    Account::Deposit(CalculateInterest());

    // then withdraw the new amount
    bool result = Account::Withdraw(amount);
    if (result) m_duration = 0;
    return result;
}

// Destructor
SavingAccount::~SavingAccount() {
    m_period = 0;
    m_rate = 0;
    m_duration = 0;
}

