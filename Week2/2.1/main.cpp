#include <iostream>
#include "define.h"

int main() {
    try {
        // Fraction p1 , p2;
        // //Input fraction
        // p1.input();
        // p2.input();

        // //Output fraction
        // std::cout << "Output fraction" << "\n";
        // p1.output();
        // p2.output();

        // // get data of fraction
        // std::cout << "Data of fraction 1" << "\n";
        // std::cout << p1.getNum() << "\n";
        // std::cout << p1.getDenom() << "\n";

        // //set data of fraction
        // std::cout << "Set data of fraction 1" << "\n";
        // p1.setNum(5);
        // p1.setDenom(7);
        // std::cout << p1.getNum() << " " << p1.getDenom() << "\n";

        // // reduce fraction
        // Fraction reduce_p1 = p1.reduce();
        // std::cout << "Reduce fraction 1" << "\n";
        // reduce_p1.output();

        // //inverse fraction
        // Fraction inverse_p1 = p1.inverse();
        // std::cout << "Inverse fraction 1" << "\n";
        // inverse_p1.output();

        // Fraction inverse_p2 = p2.inverse();
        // std:: cout << "Inverse fraction 2" << "\n";
        // inverse_p2.output();

        // // Add two fraction p1 , p2;
        // Fraction sum = p1.add(p2);
        // std::cout << "Sum of two fraction" << "\n";
        // sum.output();

        // //Compare two fraction
        // std::cout << "Compare two fraction" << "\n";
        // int t = p1.compare(p2);
        // std::cout << "Fraction 1 is ";
        // std::cout << ((!t) ? "Equal" : (t < 0) ? "Less" : "Greater") << "\n";
        // std::cout << " than fraction 2" << "\n";
    }
    catch (std:: invalid_argument & e) {
        std::cout << e.what() << "\n";
    }
    return 0;
}