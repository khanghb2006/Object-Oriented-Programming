#include <iostream>
#include "Fraction.h"

int main() {
   try {
        Fraction f1;
        std::cout << f1.getNumFractions() << "\n";
        Fraction f2(3 , 6);
        std::cout << f2.getNumFractions() << "\n";
        Fraction f3(f2);
        std::cout << f3.getNumFractions() << "\n";

   }
   catch (const std::invalid_argument &e) {
        std::cout << e.what() << "\n";
   }
}