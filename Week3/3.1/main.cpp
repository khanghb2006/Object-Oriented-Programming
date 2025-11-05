#include <iostream>
#include "Fraction.h"

int main () {
    try {
        Fraction *f0 = new Fraction;
        Fraction *f1 = new Fraction (3 , 5);
        Fraction *f2 = new Fraction (*f1);
        
        delete f0;
        delete f1;
        delete f2;
    }
    catch (const std::invalid_argument & e) {
        std::cout << e.what() << "\n";
    }
}