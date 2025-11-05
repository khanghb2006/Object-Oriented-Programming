#include <iostream>
#include<algorithm>
#include "define.h"
#include "MathWithFraction.h"

Fraction Inverse (Fraction fraction) {
    //inverse fraction a/b is b/a
    if (!fraction.num) 
        throw std::invalid_argument ("Error: Cannot inverse fraction because numerator equal 0");
    std::swap(fraction.num , fraction.den);

    fraction.reduce();
    return fraction;
}

Fraction Add (Fraction frac1 , Fraction frac2) {
    Fraction sum = Fraction (0 , 0);
    // a/b + c/d = reduce(a * d + b * c , c * d)
    sum.num = frac1.num * frac2.den + frac1.den * frac2.num;
    sum.den = frac1.den * frac2.den;

    sum.reduce();
    return sum;
}

int Compare(Fraction frac1 , Fraction frac2) {
    // compare 2 fraction a/b and c/d we do
    // + tmp1 = a * d and tmp2 = c * b
    // tmp1 > tmp2 -> a/b greater than c / d, otherwise
    long long tmp1 = frac1.num * frac2.den;
    long long tmp2 = frac2.num * frac1.den;
    return (tmp1 == tmp2) ? 0 : (tmp1 < tmp2) ? -1 : 1;
}