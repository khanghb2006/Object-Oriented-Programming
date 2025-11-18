#pragma once
#include <iostream>
#include <string>
#include <vector>

class Fraction {
    private:
        int m_num;
        int m_den;

    public:
        static int InstanceCount;
        static Fraction* Parse(std::string line, std::string seperator);

    public:
        // Constructors
        Fraction();
        Fraction(int num, int den);
        Fraction(const Fraction& other);

    public:
        // Getters and Setters
        int get_num() const { return m_num; }
        int get_den() const { return m_den; }
        void set_num(int num);
        void set_den(int den);

    public:
        // Destructor
        ~Fraction();
};