#include <iostream>
#include <math.h>
#include "Fraction.h"

// Constructor with parameters
Fraction::Fraction (int num , int den) {
    if (!den) *this = Fraction();
    else {
        m_num = num;
        m_den = den;
    }
}

// Arithmetic operators
Fraction Fraction::operator + (const Fraction &f) {
    int num = (long long) m_num * f.m_den + (long long) f.m_num * m_den;
    int den = (long long) m_den * f.m_den;
    return Fraction (num , den);
}

Fraction Fraction::operator * (const Fraction &f) {
    return Fraction ((long long) m_num * f.m_num , (long long) m_den * f.m_den);
}

//Comparision operators
bool Fraction::operator > (const Fraction &f) {
    return (long double) m_num / m_den > (long double) f.m_num / f.m_den;
}

bool Fraction::operator < (const Fraction &f) {
    return (long double) m_num / m_den < (long double) f.m_num / f.m_den;
}

bool Fraction::operator == (const Fraction &f) {
    return (long double) m_num / m_den == (long double) f.m_num / f.m_den;
}

bool Fraction::operator >= (const Fraction &f) {
    return !(*this < f);
}

bool Fraction::operator <= (const Fraction &f) {
    return !(*this > f);
}

bool Fraction::operator != (const Fraction &f) {
    return !(*this == f);
}

// Assignment operator
Fraction& Fraction::operator = (const Fraction &f) {
    *this = f;
    return (*this);
}

Fraction& Fraction::operator += (const Fraction &f) {
    m_num = (long long) m_num * f.m_den + (long long) f.m_num * m_den;
    m_den = (long long) m_den * f.m_den;
    // *this = *this + f;
    return (*this);
}

Fraction& Fraction::operator *= (const Fraction &f) {
    m_num = (long long) m_num * f.m_num;
    m_den = (long long) m_den * f.m_den;
    // *this = *this * f;
    return (*this);
}

//Increment add 1 unit
Fraction& Fraction::operator ++() {
    m_num += m_den;
    return (*this);
}

Fraction Fraction::operator ++(int x) {
    Fraction prev(*this);
    m_num += m_den;
    return prev;
}

//Decrement minus 1 unit
Fraction& Fraction::operator --() {
    m_num -= m_den;
    return (*this);
}

Fraction Fraction::operator --(int x) {
    Fraction prev(*this);
    m_num -= m_den;
    return prev;
}

//Type-cast
Fraction::operator float() const {
    return (long double) m_num / m_den;
}

Fraction::operator int() const {
    return round (m_num / m_den);
}

// Input Output operator
std::ostream& operator << (std::ostream &os , const Fraction &f) {
    os << f.m_num << " " << f.m_den << "\n";
    return os;
}

std::istream& operator >> (std::istream &is , Fraction &f) {
    is >> f.m_num >> f.m_den;
    if (!f.m_den) throw std::invalid_argument("Divided by zero");
    return is;
}

// Destructor
Fraction::~Fraction() {} 


    
