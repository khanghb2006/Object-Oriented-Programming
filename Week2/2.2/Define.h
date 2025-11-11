#pragma once

// Monomial is ax^n where a and n are parameter
// The product of powers of variables with non-negative interger components
// https://en.wikipedia.org/wiki/Monomial

class Monomial {
    private:
        double m_coef;
        int m_exp;
    
    public:
        void input();
        void output();
        double getCoef(); // get coefficient of monomial
        void setCoef(double new_coef); // set coefficient of monomial
        int getExpo(); //get exponent of monomial
        void setExpo(int new_expo); // set exponent of monomial
        double evaluate(double x);
        Monomial derive();
        Monomial mul(Monomial p);
    
    ~Monomial() {} // Destructor
};