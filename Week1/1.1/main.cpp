#include<iostream>
#include<math.h>
#include<algorithm>

#include "define.h"
#include "inout.h"
#include "MathWithFraction.h"

int main() {
    Fraction fraction_1 , fraction_2;
    try {
        std::cout << "Enter the fraction 1" << "\n";
        Input (fraction_1);

        std::cout << "Fraction 1 after enter" << "\n";
        Output (fraction_1);

        // Reduce Fraction
        std::cout << "Fraction 1 that reduced" << "\n";
        fraction_1.reduce();
        Output(fraction_1);

        //Inverse Fraction
        std::cout << "Inverse Fraction of Fraction 1" << "\n";
        Output (Inverse(fraction_1));

        std::cout << "Enter the fraction 2" << "\n";
        Input (fraction_2);

        std::cout << "Fraction 2 after enter" << "\n";
        Output (fraction_2);

        // Reduce Fraction
        std::cout << "Fraction 2 that reduced" << "\n";
        fraction_2.reduce();
        Output (fraction_2);

        //Reduce Fraction
        std::cout << "Inverse Fraction of Fraction 2" << "\n";
        Output (Inverse(fraction_2));

        // Add Two Fraction
        std::cout << "Sum of 2 Fractions" << "\n";
        Output (Add(fraction_1 , fraction_2));
    }
    catch (std::invalid_argument & e) {
        std::cout << e.what() << "\n";
    }
    return 0;
}

