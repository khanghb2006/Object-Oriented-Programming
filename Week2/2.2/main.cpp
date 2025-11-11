#include <iostream>
#include "Define.h"

int main() {
    try {
        // Monomial m1 , m2;
    
        // // Input two monomials
        // m1.input();
        // m2.input();

        // // Output two monomials
        // m1.output();
        // m2.output();

        // // Get cofficient and exponent of monomial
        // std::cout << "The cofficient is ";
        // std::cout << m1.getCoef() << "\n";
        // std::cout << "The exponent is ";
        // std::cout << m1.getExpo() << "\n";

        // // Set cofficient and exponent of monomial
        // m1.setCoef(3);
        // m2.setExpo(5);

        // // Evaluate the monomial with x
        // std::cout << m1.evaluate(3) << "\n";

        // // Derive the monomial
        // Monomial derive_m1 = m1.derive();
        // std::cout << "Derive the monomial" << "\n";
        // derive_m1.output();

        // // Multiplication two monomials
        // Monomial mul = m1.mul(m2);
        // std::cout << "Multiplication two monomials" << "\n";
        // mul.output();
    }
    catch (std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}