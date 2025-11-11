#include <iostream>
#include <string>
#include <sstream>
#include "Polynomial.h"
#include "Monomial.h"

int main() {
    try {
        std::cout << "Introduce Polynomial" << "\n";
        std::cout << "The exponents must be non-negative intergers" << "\n";
        std::cout << "Enter polynomial in format <coef1> <exp1> <coef2> <exp2> ... <coefN> <expN>" << "\n";
        std::cout << "Must not have any extra spaces or characters behind it" << "\n";
        std::cout << "-------------------------------------------------------------" << "\n";
        // Polynomial p1 , p2;
        // std::cin >> p1;
        // std::cout << p1 << "\n";
        // std::cin >> p2;
        // std::cout << p2 << "\n";
        // std::cout << "set the coefficient of p1 at degree 2 to 5.5" << "\n";
        // // p1.setCoefAt(2 , 5.5);
        // std::cout << "get the coefficient p1 at degree 2: " << p1.getCoefAt(2) << "\n";
        // std::cout << "get the degree of p2: " << p2.getDegree() << "\n";
        // std::cout << "p1 < p2 : " << (p1 < p2) << "\n";
        // std::cout << "Add: " << (p1 + p2);
        // std::cout << "Minus: " << (p1 - p2);
        // std::cout << "Multiply: " << (p1 * p2);
        // std::cout << "Derivative of first polynomial: " << (!p1);
        // std::cout << "Anti-derivative of first polynomial: " << (~p1);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }
    return 0;
}