#include <iostream>
#include <string>
#include "Student.h"

//Initialize a student with name, math and literature points
Student::Student (std::string name , double math , double literature) :
    m_name(name) , m_math(math) , m_literature(literature) 
    {
        if (m_math < 0 || m_math > 10) 
            throw std::out_of_range ("Invalid math point");
        if (m_literature < 0 || m_literature > 10)
            throw std::out_of_range ("Invalid literature point");
        // std::cout << m_name << " " << m_math << " " << m_literature << "\n";
    }

//Initialize a student with name, math = literature = 0
Student::Student (std::string name) :
    m_name(name) , m_math(0) , m_literature(0) 
{
    // std::cout << m_name << " " << m_math << " " << m_literature << "\n";
}

Student::Student (const Student &s): 
    m_name(s.m_name) , m_math(s.m_math) , m_literature(s.m_literature) 
{
    // std::cout << m_name << " " << m_math << " " << m_literature << "\n";
}

Student::~Student () {}
