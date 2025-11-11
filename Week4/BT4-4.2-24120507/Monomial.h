#pragma once
#include <iostream>

class Monomial {
    private:
        double m_coef;
        int m_exp;
 
    public:
        // Constructor
        Monomial() : m_coef(1) , m_exp(1) {}
        Monomial (const Monomial &m) :
            m_coef (m.m_coef) , m_exp (m.m_exp) {}
        Monomial (double coef , int exp);

    public:
        // Arithmetic operator
        Monomial operator + (const Monomial &m);
        Monomial operator * (const Monomial &m);

    public:
        // Comparision operator
        // Compare exponents first then compare coefficients
        bool operator > (const Monomial &m);
        bool operator < (const Monomial &m);
        bool operator == (const Monomial &m);
        bool operator <= (const Monomial &m);
        bool operator >= (const Monomial &m);
        bool operator != (const Monomial &m);

    public:
        // Assignment operator
        Monomial& operator = (const Monomial &m);
        Monomial& operator += (const Monomial &m);
        Monomial& operator *= (const Monomial &m);

    public:
        // Increment operator
        Monomial& operator ++(); // prefix plus
        Monomial operator ++ (int x); // postfix plus

        // Decrement operators
        Monomial& operator --(); // prefix minus
        Monomial operator -- (int x); // postfix minus

        // Dirived operator
        Monomial& operator !(); // prefix dirive

    public:
        // Input operator
        friend std::istream& operator >> (std::istream &is , Monomial &m);

        // Output operator
        friend std::ostream& operator << (std::ostream &os , const Monomial &m);

        // Destructor
        ~Monomial();
};

