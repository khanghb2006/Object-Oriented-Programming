#pragma once
#include <iostream>

class Fraction {
    private:
        int m_num;
        int m_den;

    public:
        // Constructors
        Fraction() : m_num(0) , m_den(1) {}
        Fraction (int num , int den);
        Fraction (const Fraction &f) :
            m_num(f.m_num) , m_den (f.m_den) {}

    public: 
        // Arithmetic operators
        Fraction operator + (const Fraction & f);
        Fraction operator * (const Fraction & f);

    public:
        // Comparision operators
        bool operator > (const Fraction &f);
        bool operator < (const Fraction &f);
        bool operator == (const Fraction &f);
        bool operator >= (const Fraction &f);
        bool operator <= (const Fraction &f);
        bool operator != (const Fraction &f);

    public:         
        // Assignment operator
        Fraction& operator = (const Fraction &f);
        Fraction& operator += (const Fraction &f);
        Fraction& operator *= (const Fraction &f);

    public:    
        // Increment and Decrement operators
        Fraction& operator ++(); // prefix plus
        Fraction operator ++(int x); // postfix plus
        Fraction& operator --(); // prefix minus
        Fraction operator --(int x); // postfix minus
        
    public:
        // Type-cast operators
        operator float() const; //to float
        operator int() const; //to int

    public:
        // Input operator
        friend std::ostream& operator << (std::ostream &os , const Fraction &f);

        // Output operator
        friend std::istream& operator >> (std::istream &is , Fraction &f);

        // Destructor
        ~Fraction();
};