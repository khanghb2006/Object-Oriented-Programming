#pragma once
#include<iostream>
#include<algorithm>

struct Fraction {
    long long num;
    long long den;

    Fraction (int num = 0 , int den = 1) : num(num) , den(den) {}

    void reduce() {
        // to reduce a/b change to (a / d) / (b / d) which d is gcd(a,b)
        if(!num) return;

        long long d = std::__gcd(num , den);
        num /= d;
        den /= d;

        // a/(-b) change to (-a) / b;
        if(den < 0) {
            den = - den;
            num = - num;
        }
    }
};