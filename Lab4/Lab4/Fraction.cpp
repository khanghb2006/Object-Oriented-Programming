#include <iostream>
#include <string>
#include <sstream>
#include "Fraction.h"

int Fraction::InstanceCount = 0;

Fraction::Fraction() :
    m_num(0), m_den(1) {
    InstanceCount++;
}

Fraction::Fraction(const Fraction& other) :
    m_num(other.m_num), m_den(other.m_den) {
    InstanceCount++;
}

Fraction::Fraction(int num, int den) {
    if (!den) {
        // set to default value;
        m_num = 0;
        m_den = 1;
    }
    else {
        m_num = num;
        m_den = den;
    }
    InstanceCount++;
}

void Fraction::set_num(int num) {
    m_num = num;
}

void Fraction::set_den(int den) {
    if (!den) return;
    m_den = den;
}

std::string Fraction::ToString() const {
    std::stringstream ss;
    ss << "Fraction: " << m_num << "/" << m_den << "\n";
    return ss.str();
}

std::ostream& operator << (std::ostream& os, Fraction* f) {
    os << f -> ToString();
    return os;
}

std::istream& operator >> (std::istream& is, Fraction& f) {
    std::string buffer;
    std::stringstream ss;
    int num, den;

    bool ok = false;

    while (!ok) {
        std::cout << "Enter numerator and denominator: " << "\n";
        std::getline(is, buffer);
		std::stringstream ss(buffer);
        if (ss >> num >> den)
            if (den) {
                f.set_num(num);
                f.set_den(den);
                ok = true;
            }
        if (!ok) std::cout << "Denominator cannot be zero. Please re-enter." << "\n";
    }
    return is;
}

Fraction::~Fraction() {
    m_num = 0, m_den = 1;
    --InstanceCount;
}