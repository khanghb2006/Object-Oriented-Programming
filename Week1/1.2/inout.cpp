#include<iostream>
#include "inout.h"
#include "def.h"

void InputFraction (Fraction *&arr , int &size) {
    
    std::cout << "Enter the size of array" << "\n";
    std::cin >> size;
    if (size <= 0) throw std::invalid_argument ("The size must be greater than 0");

    arr = new Fraction[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Enter fraction " << i + 1 << "\n";
        std::cin >> arr[i].num >> arr[i].den;
        if(!arr[i].den) 
            throw std::invalid_argument("Divided by zero");
        arr[i].reduce();
    }
}

void OutputFraction (Fraction *arr , int size) {
    std::cout << size << "\n";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i].num << " ";
        if (arr[i].num % arr[i].den != 0)
            std::cout << arr[i].den;
        std::cout << "\n";
    }
}