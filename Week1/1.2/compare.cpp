#include<iostream>
#include "compare.h"
#include "def.h"

bool CompareTwoFraction (Fraction frac1 , Fraction frac2) {
    // if frac1 < frac2 return 0 otherwise 1
    return (frac1.num * frac2.den < frac2.num * frac1.den) ? 0 : 1;
}

bool isIncresing (Fraction frac1 , Fraction frac2) {
    return (CompareTwoFraction (frac1 , frac2) == 0);
}

bool isDecresing (Fraction frac1 , Fraction frac2) {
    return (CompareTwoFraction (frac1 , frac2) == 1);
}