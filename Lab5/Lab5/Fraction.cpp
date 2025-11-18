#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Fraction.h"

int Fraction::InstanceCount = 0;

Fraction* Fraction::Parse(std::string line, std::string seperator) {
    // lamda to check valid characters
    auto valid = [](char x) {
        return (isdigit(x) || x == '-' || x == '.');
        };

    std::vector<int> tokens;
    std::string valid_sub;

    while (line.find(seperator) != std::string::npos) {
        // get substring before seperator
        std::string sub = line.substr(0, line.find(seperator));

        // get valid characters only
        valid_sub = "";
        std::copy_if(sub.begin(), sub.end(), std::back_inserter(valid_sub), valid);
		int x = std::stoi(valid_sub);
        tokens.push_back(x);
        line = line.substr(line.find(seperator) + seperator.size(), std::string::npos);
    }

    // get the last token
    valid_sub = "";
    std::copy_if(line.begin(), line.end(), std::back_inserter(valid_sub), valid);
    int x = std::stoi(valid_sub);
    tokens.push_back(x);
    return new Fraction(tokens[0] , tokens[1]);
}

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

Fraction::~Fraction() {
    m_num = 0, m_den = 1;
    --InstanceCount;
}