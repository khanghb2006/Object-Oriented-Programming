#include <iostream>
#include "CPoint.h"

CPoint::CPoint() : m_x(0), m_y(0) {}

CPoint::CPoint(const CPoint& p) : m_x(p.m_x), m_y(p.m_y) {}

CPoint::CPoint(double _x, double _y) : m_x(_x), m_y(_y) {}

bool CPoint::overlap(CPoint p) {
	return (m_x == p.m_x) && (m_y == p.m_y);
}

double CPoint::CalcDist(const CPoint& p) {
	double dx = m_x - p.m_x;
	double dy = m_y - p.m_y;
	return sqrt(dx * dx + dy * dy);
}

CPoint::~CPoint() {}
