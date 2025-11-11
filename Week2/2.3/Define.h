#pragma once
#include <string>

class Student {
    private:
        std::string m_name;
        double m_literature_point;
        double m_math_point;
    
    public:
        void input();
        void output();
        std::string getName();
        void setName(std::string new_name);
        double getLit(); // get literature point
        void setLit(double new_lit_point); // update literature point
        double getMath(); // get math point
        void setMath(double new_math_point); // update math point
        double calculateGPA(); // GPA of student
        char grade(); // student grade
    
    ~Student() {} // Destructor
};