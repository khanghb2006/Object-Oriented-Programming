#pragma once
#include <string>

class Fraction {
private:
    int m_num;
    int m_den;

public:
    static int InstanceCount;

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
    std::string ToString() const;
    friend std::ostream& operator <<(std::ostream& os, Fraction* f);
    friend std::istream& operator >> (std::istream& is, Fraction& f);

public:
    // Destructor
    ~Fraction();
};