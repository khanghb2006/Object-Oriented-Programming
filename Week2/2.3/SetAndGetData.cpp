#include <iostream>
#include "Define.h"

// The name of student must not be have special character or number
bool valid_student_name(std::string name) {
    if (!name.size()) return false;
    for (char c : name) 
        if (!isalpha(c) && c != ' ') return false;
    return true;
}

// get the name of student
std::string Student:: getName() {
    return m_name;
}

// set the name of student
void Student:: setName(std::string new_name) {
    if (!valid_student_name(new_name))
        throw std::invalid_argument("Invalid student name");
    m_name = new_name;
}

// get the literature point of student
double Student:: getLit() {
    return m_literature_point;
}   

// set the literature point of student
void Student:: setLit(double new_lit_point) {
    if (new_lit_point < 0 || new_lit_point > 10) 
        throw std::invalid_argument("Invalid literature point");
    m_literature_point = new_lit_point;
}

// get the math point of student
double Student:: getMath() {
    return m_math_point;
}

// set the math point of student
void Student:: setMath(double new_math_point) {
    if (new_math_point < 0 || new_math_point > 10) 
        throw std::invalid_argument("Invalid math point");
    m_math_point = new_math_point;
}