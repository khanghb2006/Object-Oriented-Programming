#include <iostream>
#include <string>
#include <sstream>
#include "CCircle.h"
#include "CPoint.h"

int CCircle::InstanceCount = 0;

CCircle::CCircle() :
    m_center(new CPoint(0, 0)), m_radius(1) {
    InstanceCount++;
}

CCircle::CCircle(const CCircle& other) :
    m_center(new CPoint(*other.m_center)), m_radius(other.m_radius) {
    InstanceCount++;
}

CCircle::CCircle(CPoint* center, double radius) {
    if (radius <= 0) {
        // set to default constructor
        m_radius = 1;
        m_center = new CPoint(0, 0);
    }
    else {
        m_radius = radius;
        m_center = new CPoint(*center);
    }
    InstanceCount++;
}

CCircle* CCircle::Parse(std::string line, std::string seperator) {
    // lamda to check valid characters
    auto valid = [](char x) {
        return (isdigit(x) || x == '-' || x == '.');
        };

    std::vector<double> tokens;
    std::string valid_sub;

    while (line.find(seperator) != std::string::npos) {
        // get substring before seperator
        std::string sub = line.substr(0, line.find(seperator));

        // get valid characters only
        valid_sub = "";
        std::copy_if(sub.begin(), sub.end(), std::back_inserter(valid_sub), valid);

        float x = std::stod(valid_sub);
        tokens.push_back(x);
        line = line.substr(line.find(seperator) + seperator.size(), std::string::npos);
    }

    // get the last token
    valid_sub = "";
    std::copy_if(line.begin(), line.end(), std::back_inserter(valid_sub), valid);
    float x = std::stof(valid_sub);
    tokens.push_back(x);
    return new CCircle(new CPoint(tokens[0], tokens[1]), tokens[2]);
}

void CCircle::set_center(CPoint& new_center) {
    if (m_center) delete m_center, m_center = nullptr;
    m_center = new CPoint(new_center);
}

void CCircle::set_radius(double new_radius) {
    if (new_radius <= 0) return;
    m_radius = new_radius;
}

CCircle::~CCircle() {
    if (m_center) delete m_center, m_center = nullptr;
    m_radius = 0;
    --InstanceCount;
}