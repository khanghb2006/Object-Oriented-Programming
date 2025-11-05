#include <iostream>
#include <string>
#include <sstream>
#include "Define.h"

void Student::input() {
    std::cout << "Enter student name , literature point , math point:" << "\n";    

    std::string line;
    std::getline(std::cin , line);
    std::stringstream ss(line);
    
    char c;
    char prev = ' ';
    while (ss.get(c)) {
        if (!isalpha(c) && c != ' ' && !isdigit(c) && c != '.') 
            throw std::invalid_argument("Invalid input");
        else if (isdigit(c) || c == '.') {
            ss.putback(c);
            if (!(ss >> m_literature_point >> m_math_point)) 
                throw std::invalid_argument("Invalid input");
        }
        else {
            if (!isalpha(c) && c != ' ') 
                throw std::invalid_argument("Invalid student name");
            else {
                if (isspace(c) && isspace(prev)) continue;
                m_name += c;
                prev = c;
            }
        }
    }
    // No name
    if (!m_name.size()) throw std::invalid_argument("Invalid student name");

    //Invalid literature point
    if (m_literature_point < 0 || m_literature_point > 10) 
        throw std::invalid_argument("Invalid literature point");
    
    //Invalid math point
    if (m_math_point < 0 || m_math_point > 10) 
        throw std::invalid_argument("Invalid math point");
}

void Student::output() {
    std::cout << "Student name: " << m_name << "\n";
    std::cout << "Literature point: " << m_literature_point << "\n";
    std::cout << "Math point: " << m_math_point << "\n";
    std::cout << "GPA: " << calculateGPA() << "\n";
    std::cout << "Grade: " << grade() << "\n";
}
