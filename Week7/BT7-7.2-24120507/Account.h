#pragma once
#include <iostream>
#include <utility>

class Account {
    private:
        float m_balance;

    public:
        // Constructor
        Account() : m_balance(0) {}
        Account (const Account &other) : m_balance(other.m_balance) {}
        Account (float balance) : m_balance(balance) {}

    public:
        // Assignment operator
        Account& operator = (Account other) {
            std::swap(m_balance , other.m_balance);
            return *this;
        }

    public:
        // Methods
        float getBalance() const { return m_balance; }

        void Deposit(float amount) {
            if (amount < 0) 
                throw std::invalid_argument("Deposit amount must be non-negative");

            m_balance += amount;
        }

        bool Withdraw(float amount) {
            if (amount < 0)
                throw std::invalid_argument("Withdraw amount must be non-negative");
            
            if (amount > m_balance) return false;
            m_balance -= amount;
            return true;
        }
    
    public: 
        // Destructor
        ~Account() {
            m_balance = 0;
        }
};