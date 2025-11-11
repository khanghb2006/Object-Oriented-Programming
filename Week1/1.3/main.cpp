#include<iostream>
#include<string>
#include "def.h"
#include "compare.h"
#include "inout.h"

int main() {
    Fraction *arr;
    int size;
    try{
        std::cout << "Enter the array" << "\n";
        Input (arr , size);
        Mixed<Fraction , Fraction , bool> Compare = Increasing<Fraction , Fraction , bool>;
        Sort<Fraction , Fraction , bool> (arr , size , Compare);
        Output (arr , size);
        delete [] arr;
    }
    catch (std::invalid_argument & e) {
        std::cout << e.what() << "\n";
    }
}