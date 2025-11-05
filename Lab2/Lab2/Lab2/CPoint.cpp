#include <iostream>
#include "CPoint.h"

double CPoint::calcDist(const CPoint& other) {
	double dx = m_x - other.m_x;
	double dy = m_y - other.m_y;
	return sqrt(dx * dx + dy * dy);
}

bool CPoint::is_triangle(CPoint B, CPoint C) {
	// Use CCW to check valid triangle
	CPoint AB = CPoint(B.get_x() - m_x, B.get_y() - m_y);
	CPoint AC = CPoint(C.get_x() - m_x, C.get_y() - m_y);
	return (long double)AB.get_x() * AC.get_y() !=
		(long double)AB.get_y() * AC.get_x();
}