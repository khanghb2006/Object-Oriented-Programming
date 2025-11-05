#include <iostream>
#include "Fraction.h"

Fraction::Fraction() : m_num(0) , m_den(1) {
    // std::cout << m_num << " " << m_den << "\n";
}

Fraction::Fraction (int value) : m_num(value) , m_den(1) {}

Fraction::Fraction (const Fraction & f) : 
    m_num(f.m_num) , m_den(f.m_den) 
{
    // std::cout << m_num << " " << m_den << "\n";
}

Fraction::Fraction (int num , int den) : 
    m_num(num) , m_den(den) 
{
    if (!m_den) throw std::invalid_argument("Devided by zero");
    // std::cout << m_num << " " << m_den << "\n";
}