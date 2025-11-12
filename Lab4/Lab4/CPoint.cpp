#include <iostream>
#include <cmath>
#include <sstream>
#include "CPoint.h"

int CPoint::InstanceCount = 0;

CPoint::CPoint() : m_x(0), m_y(0) {
    InstanceCount++;
}

CPoint::CPoint(const CPoint& other) : m_x(other.m_x), m_y(other.m_y) {
    InstanceCount++;
}

CPoint::CPoint(double x, double y) : m_x(x), m_y(y) {
    InstanceCount++;
}

double CPoint::CalcDist(const CPoint& b) {
    double dx = m_x - b.m_x;
    double dy = m_y - b.m_y;
    return sqrt(dx * dx + dy * dy);
}

std::string CPoint::ToString() const {
    std::stringstream ss;
    ss << "CPoint (" << m_x << ", " << m_y << ")" << "\n";
    return ss.str();
}

std::istream& operator >> (std::istream& is, CPoint& p) {
    std::string buffer;
    double x, y;
    bool ok = false;
    while (!ok) {
        std::getline(is, buffer);
        std::stringstream ss(buffer);
        if (ss >> x >> y) {
            p.set_x(x);
            p.set_y(y);
            ok = true;
        }
        if (!ok) std::cout << "Invalid input. Please enter again" << "\n";
    }
    return is;
}

std::ostream& operator << (std::ostream& os, const CPoint* p) {
    os << p->ToString();
    return os;
}

CPoint::~CPoint() {
    m_x = 0;
    m_y = 0;
    --InstanceCount;
}