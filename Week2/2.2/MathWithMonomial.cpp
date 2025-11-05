#include <iostream>
#include "Define.h"

// To calculate a ^ k
// a ^ k = a ^ (k / 2) * a ^ (k / 2) if k is even
// a ^ k = a ^ (k / 2) * a ^ (k / 2) * a if k is odd
long double Pow (double a , int k) {
    if(!k) return 1;
    long double tmp = Pow (a , k >> 1);
    tmp = 1.00 * tmp * tmp;
    if(k & 1) tmp = 1.00 * tmp * a;
    return tmp;
}

double Monomial:: evaluate (double x) {
    return (long double) m_coef * Pow (x , m_exp);
}

Monomial Monomial:: derive () {
    // to derive ax^n -> a * n * x ^(n - 1)
    // if exp = 0 return 0;

    Monomial ans;
    if (!m_exp) ans.m_coef = ans.m_exp = 0;
    else {
        ans.m_coef = m_coef * m_exp;
        ans.m_exp = m_exp - 1;
    }
    return ans;
}

Monomial Monomial:: mul (Monomial p) {
    // To mul two monomials we do : 
    // a1 * x ^ (n1)
    Monomial ans;
    ans.m_coef = (long double) m_coef * p.m_coef;
    ans.m_exp = m_exp + p.m_exp;
    return ans;
}

