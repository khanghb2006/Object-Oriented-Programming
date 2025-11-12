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

void CCircle::set_center(CPoint& new_center) {
    if (m_center) delete m_center, m_center = nullptr;
    m_center = new CPoint(new_center);
}

void CCircle::set_radius(double new_radius) {
    if (new_radius <= 0) return;
    m_radius = new_radius;
}

std::string CCircle::ToString() const {
    std::stringstream ss;
    ss << "CCircle " << "\n";
    ss << "Center: " << m_center->ToString() << "\n";
    ss << "Radius: " << m_radius << "\n";
    return ss.str();
}

std::ostream& operator << (std::ostream& os, const CCircle* c) {
    os << c->ToString();
    return os;
}

std::istream& operator >> (std::istream& is, CCircle& c) {
    std::string buffer;
    double center_x , center_y , radius;

    bool ok = false;

    while (!ok) {
        std::cout << "Enter the center point coordinates and radius" << "\n";
        std::getline(is, buffer);
        std::stringstream ss(buffer);
        if (ss >> center_x >> center_y >> radius) {
            if (radius > 0) {
				CPoint center(center_x, center_y);
                c.set_center(center);
                c.set_radius(radius);
                ok = true;
            }
        }
        if(!ok) std::cout << "Invalid input. Please try again." << "\n";
    }
    return is;
}

CCircle::~CCircle() {
    if (m_center) delete m_center, m_center = nullptr;
    m_radius = 0;
    --InstanceCount;
}