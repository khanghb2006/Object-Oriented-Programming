#include <iostream>
#include <sstream>
#include <string>
#include "Define.h"

void Array:: input() {
    std::string line;
    std::stringstream ss;

    std::cout << "Enter size of array" << "\n";
    getline(std::cin , line);
    ss.str(line);
    ss.clear();
    if (!(ss >> m_size)) throw std::invalid_argument("Invalid input");
    if (m_size <= 0) throw std::invalid_argument("Size must be greater than 0");

    // allocate memory
    m_arr = (int*) calloc(m_size , sizeof(int));
    if (!m_arr) throw std::bad_alloc();

    std::getline(std::cin , line);
    ss.str(line);   
    ss.clear();
    for (int i = 0; i < m_size; i++) {
        int value;
        if (!(ss >> value)) throw std::invalid_argument("Invalid input");
        m_arr[i] = value;
    }
}

void Array:: output() {
    for (int i = 0; i < m_size; i++)
        std::cout << m_arr[i] << " ";
    std::cout << "\n";
}