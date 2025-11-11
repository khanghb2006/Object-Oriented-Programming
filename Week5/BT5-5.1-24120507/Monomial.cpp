#include <iostream>
#include <sstream>
#include <string>
#include "Monomial.h"

// Operator
bool Monomial::operator < (const Monomial &other) {
    if (m_exp != other.m_exp)
        return m_exp < other.m_exp;
    return m_coef < other.m_coef;
}

bool Monomial::operator > (const Monomial &other) {
    if (m_exp != other.m_exp)
        return m_exp > other.m_exp;
    return m_coef > other.m_coef;
}

bool Monomial::operator <= (const Monomial &other) {
    return *this > other;
}

bool Monomial::operator >= (const Monomial &other) {
    return *this < other;
}

bool Monomial::operator == (const Monomial &other) {
    return (m_exp == other.m_exp && m_coef == other.m_coef);
}

bool Monomial::operator != (const Monomial &other) {
    return (!(*this == other));
}

// Arithmetics operator
Monomial Monomial::operator + (const Monomial &other) {
    if (m_exp != other.m_exp)
        throw std::invalid_argument("Not equal exponents");
    return Monomial(m_coef + other.m_coef , m_exp);
}

Monomial Monomial::operator - (const Monomial &other) {
    if (m_exp != other.m_exp)
        throw std::invalid_argument("Not equal exponents");
    return Monomial(m_coef - other.m_coef , m_exp);
}

Monomial Monomial::operator * (const Monomial &other) {
    return Monomial(m_coef * other.m_coef , m_exp + other.m_exp);
}

// Dirivative and anti-dirivative
Monomial Monomial::operator ! () {
    if (!m_exp) return Monomial(0 , 0);
    return Monomial(m_coef * m_exp , m_exp - 1);
}

Monomial Monomial::operator ~ () {
    return Monomial(m_coef / (m_exp + 1) , m_exp + 1);
}

// Input and output
std::ostream& operator << (std::ostream &os , const Monomial &m) {  
    if (!m.m_coef) return os;
    if (m.m_coef != 1) os << m.m_coef;
    if (!m.m_exp) os << " ";
    else if (m.m_exp == 1) os << "x ";
    else os << "x^(" << m.m_exp << ") ";
    return os;
}

