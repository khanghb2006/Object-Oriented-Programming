#include <iostream>
#include "CPoint.h"
#include "CCircle.h"

CCircle::CCircle(CPoint* center, double radius) {
	if (radius < 0) {
		// set to default
		m_center = new CPoint(0, 0);
		m_radius = 1;
	}
	else {
		m_center = new CPoint(*center);
		m_radius = radius;
	}
}

void CCircle::set_center(CPoint &new_center) {
	delete m_center;
	m_center = new CPoint(new_center);
}

void CCircle::set_radius(double new_radius) {
	if (new_radius > 0) m_radius = new_radius;
}