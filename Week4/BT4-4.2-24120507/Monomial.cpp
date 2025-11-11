#include <iostream>
#include "Monomial.h"

// Constructor
Monomial::Monomial (double coef , int exp) {
    // epx must be non-negative integer
    if (exp < 0) (*this) = Monomial();  // set to default Monomial
    else {
        m_coef = coef;
        m_exp = exp;
    }
}

// Arithmetic operator
Monomial Monomial::operator + (const Monomial &m) {
    if (m_exp != m.m_exp) 
        throw std::invalid_argument("Cannot add monomials with different exponents");
    return Monomial(m_coef + m.m_coef , m_exp);
}

Monomial Monomial::operator * (const Monomial &m) {
    return Monomial ((long double) m_coef * m.m_coef , m_exp + m.m_exp);
}

// Comparision operator
// Compare exponents first then compare coefficients

bool Monomial::operator > (const Monomial &m) {
    if (m_exp != m.m_exp) 
        return m_exp > m.m_exp;
    return m_coef > m.m_coef;
}

bool Monomial::operator < (const Monomial &m) {
    if (m_exp != m.m_exp)
        return m_exp < m.m_exp;
    return m_coef < m.m_coef;
}

bool Monomial::operator == (const Monomial &m) {
    return (m_exp == m.m_exp) && (m_coef == m.m_coef);
}

bool Monomial::operator <= (const Monomial &m) {
    return !(*this > m);
}

bool Monomial::operator >= (const Monomial &m) {
    return !(*this < m);
}

bool Monomial::operator != (const Monomial &m) {
    return (m_exp != m.m_exp) || (m_coef != m.m_coef);
}

// Assignment operator
Monomial& Monomial::operator = (const Monomial &m) {
    *this = m;
    return *this;
}

Monomial& Monomial::operator += (const Monomial &m) {
    if (m_exp != m.m_exp)
        throw std::invalid_argument("Cannot add monomials with different exponents");
    m_coef += m.m_coef;
    return *this;
}

Monomial& Monomial::operator *= (const Monomial &m) {
    m_coef *= m.m_coef;
    m_exp += m.m_exp;
    return *this;
}

// Increment operator (increase exponent by 1)
Monomial& Monomial::operator ++() {
    m_exp++;
    return *this;
}

Monomial Monomial::operator ++ (int x) {
    Monomial prev = *this;
    m_exp++;
    return prev;
}

// Decrement operator (decrease exponent by 1)
Monomial& Monomial::operator --() {
    if (!m_exp)
        throw std::invalid_argument ("Cannot decrement exponent below 0");
    m_exp--;
    return *this;
}

Monomial Monomial::operator -- (int x) {
    if (!m_exp)
        throw std::invalid_argument ("Cannot decrement exponent below 0");
    Monomial prev = *this;
    m_exp--;
    return prev;
}

// Dirived operator
// ax^n -> (a * n) x^(n - 1)
Monomial& Monomial::operator !() {
    if (!m_exp) m_coef = 0;
    else {
        m_coef *= m_exp;
        m_exp--;
    }
    return *this;
}

// Input operator
std::istream& operator >> (std::istream &is , Monomial &m) {
    is >> m.m_coef >> m.m_exp;
    if (m.m_exp < 0) 
        throw std::invalid_argument("Exponent must be a non-negative integer");
    return is;
}

// Output operator
std::ostream& operator << (std::ostream &os , const Monomial &m) {
    os << m.m_coef << " x^ " << m.m_exp;
    return os;
}

Monomial::~Monomial() {
    m_coef = 0;
    m_exp = 0;
}