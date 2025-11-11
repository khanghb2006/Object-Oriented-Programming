#include <iostream>
#include <string>
#include <sstream>
#include "Define.h"
#include "Calc.h"

void Monomial::input() {
    std::cout << "Input the monomial (coefficient and exponent separated by space): " << "\n";

    std::string line;
    std::getline (std::cin , line);
    std::stringstream ss(line);
    std::string coef , exp;

    // std::cout << "Input the cofficient: ";
    // std::cin >> coef;
    // std::cout << "Input the exponent: ";
    // std::cin >> exp;

    ss >> coef >> exp;

    // calculate if coef and exp like 2*(1 + 1/2)
    m_coef = solve(coef);
    m_exp = solve(exp);

    if(m_exp < 0) throw std::invalid_argument ("Exponent must be a non-negative interger");
}

void Monomial::output() {
    std::cout << "Output the monomial" << "\n";
    
    // a * x^0 = a
    if (!m_exp) {
        std::cout << m_coef << "\n";
        return;
    }

    // 0 * x^n = 0
    if (!m_coef) {
        std::cout << 0 << "\n";
        return;
    }

    // a * x^1 = a*x
    if(m_exp == 1) {
        std::cout << m_coef << "*x" << "\n";
        return;
    }
    
    // a = -1 => -x^n
    if(m_coef == -1) {
        std::cout << "-x ^ " << m_exp << "\n";
        return;
    }

    // a = 1 => x^n
    if(m_coef == 1) {
        std::cout << "x ^ " << m_exp << "\n";
        return;
    }
    std::cout << m_coef << "* x ^ (" << m_exp << ")" << "\n";
}