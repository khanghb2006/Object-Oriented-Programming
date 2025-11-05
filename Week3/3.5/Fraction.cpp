#include <iostream>
#include "Fraction.h"

int Fraction::numFractions = 0;

Fraction::Fraction() {
    m_num = 0;
    m_den = 1;
    ++Fraction::numFractions;
}

Fraction::Fraction (const Fraction &f) {
    m_num = f.m_num;
    m_den = f.m_den;
    ++Fraction::numFractions;
}

Fraction::Fraction (int num , int den) {
    if (!den) 
        throw std::invalid_argument("Divided by zero");
    m_num = num;
    m_den = den;
    ++Fraction::numFractions;
}

Fraction::~Fraction() {
    --Fraction::numFractions;
}

int Fraction::getNumFractions() {
    return numFractions;
}