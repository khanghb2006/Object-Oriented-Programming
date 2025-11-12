#include <iostream>
#include <string>
#include <sstream>
#include "CPoint.h"
#include "CRectangle.h"

int CRectangle::InstanceCount = 0;

CRectangle::CRectangle() :
    m_topLeft(new CPoint(0, 1)), m_bottomRight(new CPoint(1, 0)) {
    InstanceCount++;
}

CRectangle::CRectangle(const CRectangle& other) :
    m_topLeft(new CPoint(*other.m_topLeft)), m_bottomRight(new CPoint(*other.m_bottomRight)) {
    InstanceCount++;
}

CRectangle::CRectangle(CPoint topLeft, CPoint bottomRight) {
    if (topLeft.is_overlap(bottomRight)) {
        // set to default value
        m_topLeft = new CPoint(0, 1);
        m_bottomRight = new CPoint(1, 0);
    }
    else {
        m_topLeft = new CPoint(topLeft);
        m_bottomRight = new CPoint(bottomRight);
    }
    InstanceCount++;
}

void CRectangle::set_topLeft(CPoint& topLeft) {
    if (topLeft.is_overlap(*m_bottomRight)) return;
    *m_topLeft = topLeft;
}

void CRectangle::set_bottomRight(CPoint& bottomRight) {
    if (bottomRight.is_overlap(*m_topLeft)) return;
    *m_bottomRight = bottomRight;
}

std::string CRectangle::ToString() const {
    std::stringstream ss;
    ss << "CRectangle " << "\n";
    ss << "Top Left: " << m_topLeft->ToString() << "\n";
    ss << "Bottom Right: " << m_bottomRight->ToString() << "\n";
    return ss.str();
}

std::ostream& operator << (std::ostream& os, const CRectangle* r) {
    os << r -> ToString();
    return os;
}

std::istream& operator >> (std::istream& is, CRectangle& r) {
    std::string buffer;
    double tl_x, tl_y, br_x, br_y;

    bool ok = false;
    while (!ok) {
        std::cout << "Enter Top Left and Bottom Right coordinates" << "\n";
        std::getline(is, buffer);
		std::stringstream ss(buffer);
        if (ss >> tl_x >> tl_y >> br_x >> br_y) {
			CPoint topLeft = CPoint(tl_x, tl_y);
			CPoint bottomRight = CPoint(br_x, br_y);
            if (!topLeft.is_overlap(bottomRight)) {
                r.set_topLeft(topLeft);
                r.set_bottomRight(bottomRight);
                ok = true;
            }
        }
        if (!ok) std::cout << "Invalid input. Please try again." << "\n";
    }
    return is;
}

CRectangle::~CRectangle() {
    if (m_topLeft) delete m_topLeft, m_topLeft = nullptr;
    if (m_bottomRight) delete m_bottomRight, m_bottomRight = nullptr;
    --InstanceCount;
}