#include<iostream>
#include "Define.h"

// get the value of coefficient of monomial
double Monomial:: getCoef () {
    return this -> m_coef;
}

// set the value of coefficient of monomial
void Monomial:: setCoef (double new_coef) {
    this -> m_coef = new_coef;
}

// get the value of exponent of monomial
int Monomial:: getExpo () {
    return this -> m_exp;
}

// set the value of exponent
void Monomial:: setExpo (int new_exp) {
    if (!new_exp) throw std::invalid_argument("Exponent must be a non-negative interger");
    this -> m_exp = new_exp;
}



