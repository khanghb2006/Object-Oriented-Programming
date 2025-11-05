#pragma once
#include<algorithm>

struct Fraction {
    long long num;
    long long den;

    // set the fraction with default value
    Fraction (int num = 0 , int den = 1) : 
        num (num) , den (den) {}

    void reduce() {
        // to reduce fraction we do
        // + d is greatest common divisor of numerator and denominator
        // + reduce fraction a/b is (a / d) / (b / d)

        long long d = std::__gcd(num , den);
        num /= d;
        den /= d;
    }
};