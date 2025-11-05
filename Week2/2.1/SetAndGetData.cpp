#include <iostream>
#include "define.h"

// get numerator of fraction
int Fraction:: getNum () {
    return this -> m_num;
}

// set the value of numerator
void Fraction:: setNum (int new_num) {
    this -> m_num = new_num;
}

// get denominator of fraction
int Fraction:: getDenom() {
    return this -> m_den;
}

// set the value of denominator
void Fraction:: setDenom (int new_den) {
    if(!new_den) throw std::invalid_argument ("Denominator must be diffent 0");
    this -> m_den = new_den;
}