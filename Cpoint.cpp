#include <iostream>
#include "CPoint.h"

CPoint::CPoint() : m_x(0), m_y(0) {}

CPoint::CPoint(const CPoint& p) :
	m_x(p.m_x), m_y(p.m_y) {}

CPoint::CPoint(double x, double y) :
	m_x(x), m_y(y) {}

double CPoint::get_x() {
	return m_x;
}

double CPoint::get_y() {
	return m_y;
}

void CPoint::set_x(double new_x) {
	m_x = new_x;
}

void CPoint::set_y(double new_y) {
	m_y = new_y;
}

bool CPoint::is_overlap(CPoint other) {
	// if a overlap b return true, otherwise return false;
	if (m_x == other.m_x && m_y == other.m_y)
		return true;
	return false;
}

CPoint::~CPoint() {}