#pragma once
#include <iostream>
#include<string>

class Monomial {
    private:
        double m_coef;
        int m_exp;
    
    // Big Three Principle
    public: 
        // Constructor
        Monomial() : m_coef(0) , m_exp(0) {}
        Monomial(double coef , int exp): 
            m_coef(coef), m_exp(exp) {}
        Monomial(const Monomial& m) : 
            m_coef(m.m_coef) , m_exp(m.m_exp) {}

        // Assignment Operator
        Monomial& operator = (Monomial m) {
            std::swap(m_coef , m.m_coef);
            std::swap(m_exp , m.m_exp);
            return *this;
        }

        // Destructor
        ~Monomial() {}

    public: 
        // Getters
        double getCoef() const {return m_coef;}
        int getExp() const {return m_exp;}
    public:
        //Comparision operator
        bool operator > (const Monomial &other);
        bool operator < (const Monomial &other);
        bool operator >= (const Monomial &other);
        bool operator <= (const Monomial &other);
        bool operator == (const Monomial &other);
        bool operator != (const Monomial &other);

    public:
        // Arithmetic operator
        Monomial operator + (const Monomial &other);
        Monomial operator - (const Monomial &other);
        Monomial operator * (const Monomial &other);

    public:
        // Dirivative and anti-derivatve
        Monomial operator ! ();
        Monomial operator ~ ();

    public:
        // Input and output
        friend std::ostream& operator << (std::ostream &os , const Monomial &m);
    public:
        // Methods
        bool isZero() {
            return m_coef == 0;
        }
        
        Monomial& negative() {
            m_coef = -m_coef;
            return *this;
        }

        double mul_coef(const Monomial &other) {
            return (long double) m_coef * other.m_coef;
        }
};
