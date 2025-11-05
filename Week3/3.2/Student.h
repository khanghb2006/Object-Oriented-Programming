#pragma once
#include <string>

class Student{
    private: 
        std::string m_name;
        double m_math;
        double m_literature;
    public:
        Student (std::string name , double math , double literature);
        Student (std::string name);
        Student (const Student &s);
        ~Student ();
};