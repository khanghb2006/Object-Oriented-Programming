#include <iostream>
#include <sstream>
#include <string>
#include "CLine.h"
#include "CPoint.h"

int CLine::InstanceCount = 0;

CLine::CLine() :
    m_start(new CPoint(0, 0)), m_end(new CPoint(0, 1)) {
    InstanceCount++;
}

CLine::CLine(const CLine& other) :
    m_start(new CPoint(*other.m_start)), m_end(new CPoint(*other.m_end)) {
    InstanceCount++;
}

CLine::CLine(CPoint start, CPoint end) {
    if (start.is_overlap(end)) {
        //set to default value
		m_start = new CPoint(0, 0);
        m_end = new CPoint(0, 1);
    }
    else {
        m_start = new CPoint(start);
        m_end = new CPoint(end);
	}
	InstanceCount++;
}

void CLine::set_start(CPoint& start) {
    if (start.is_overlap(*m_end)) return;
    *m_start = start;
}

void CLine::set_end(CPoint& end) {
    if (m_start->is_overlap(end)) return;
    *m_end = end;
}

double CLine::calcLength() {
    return m_start->CalcDist(*m_end);
}

std::string CLine::ToString() const {
    std::stringstream ss;
    ss << "CLine :" << "\n";
    ss << "Start Point" << m_start->ToString();
    ss << "End Point" << m_end->ToString();
    return ss.str();
}

std::istream& operator >> (std::istream& is, CLine& l) {
    std::string buffer;
	double s_x, s_y, e_x, e_y;
    bool ok = false;

    while (!ok) {
        std::cout << "Enter start point and end point coordinates" << "\n";
        std::getline(is, buffer);
		std::stringstream ss(buffer);
        if (ss >> s_x >> s_y >> e_x >> e_y) {
			CPoint s(s_x, s_y);
			CPoint e(e_x, e_y);
            if (!s.is_overlap(e)) {
                l.set_start(s);
                l.set_end(e);
                ok = true;
            }
        }
        if (!ok) std::cout << "Invalid input. Please enter again" << "\n";
    }
    return is;
}

std::ostream& operator << (std::ostream& os, const CLine* l) {
    os << l -> ToString();
    return os;
}

CLine::~CLine() {
    if (m_start) delete m_start, m_start = nullptr;
    if (m_end) delete m_end, m_end = nullptr;
    --InstanceCount;
}