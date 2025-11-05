#include <iostream>
#include <sstream>
#include <string>
#include "define.h"

void Fraction:: input() {

    std::cout << "Please enter the fraction" << "\n";

    std::string line;
    std::getline (std::cin , line);
    std::stringstream ss(line);

    if(ss >> m_num >> m_den) {
        if(!m_den) throw std::invalid_argument ("Divided by zero");
    }
    else throw std::invalid_argument ("Invalid Input");
}

void Fraction:: output() {
    if (!m_num) std::cout << 0 << "\n";
    else if (m_den == 1) std::cout << m_num << "\n";
    else std::cout << m_num << " " << m_den << "\n";
}