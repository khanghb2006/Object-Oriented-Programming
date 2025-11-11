#include <iostream>
#include <algorithm>
#include "define.h"

Fraction Fraction:: reduce () {
    // to reduce a / b -> (a / d) / (b / d) where d is gcd(a , b);
    int d = std::__gcd(m_num , m_den);
    Fraction ans;
    ans.m_num = m_num / d;
    ans.m_den = m_den / d;
    return ans;
}

Fraction Fraction:: inverse () {
    // inverse a/b -> b / a
    if (!this -> m_num) throw std::invalid_argument ("Cannot inverse fraction");
    
    Fraction ans;
    ans.m_num = m_den;
    ans.m_den = m_num;
    return ans;
}

Fraction Fraction:: add (Fraction p) {
    // a/  b + c / d = (a * d + b * c) / b * d
    Fraction sum;
    sum.m_num = (long long) m_num * p.m_den + (long long) m_den * p.m_num;
    sum.m_den = (long long) m_den * p.m_den;
    return sum;
}

int Fraction:: compare (Fraction p) {
    // To compare a / b and c / d
    // + Equal when a * d = b * c
    // + Less when a * d < b * c
    // + Greater when a * d > b * c

    long long t1 = 1LL * m_num * p.m_den;
    long long t2 = 1LL * m_den * p.m_num;

    return (t1 == t2) ? 0 : (t1 < t2) ? -1 : 1;
}