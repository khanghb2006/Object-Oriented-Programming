#include<iostream>
#include "define.h"
#include "inout.h"

void Input (Fraction & fraction) {
    std::cout << "Enter numerator and denominator" << "\n";
    std::cin >> fraction.num >> fraction.den;
    if (!fraction.den) 
        throw std::invalid_argument("Error: Divided by zero");
    
    // if fraction is a/(-b) then we change to (-a) / b
    if (fraction.den < 0) {
        fraction.den = - fraction.den;
        fraction.num = - fraction.num;
    }
}

void Output (Fraction fraction) {
    std::cout << fraction.num;
    if(fraction.num % fraction.den == 0)
        std::cout << "\n";
    else std::cout << "/" << fraction.den << "\n";
}