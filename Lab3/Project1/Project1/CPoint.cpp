#include <iostream>
#include <cmath>
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

double CPoint::calcDist(CPoint& b) {
	double dx = m_x - b.m_x;
	double dy = m_y - b.m_y;
	return sqrt(dx * dx + dy * dy);
}

double CPoint::calcDistance(CPoint& a, CPoint& b) {
	return a.calcDist(b);
}
