#include <iostream>
#include "CPoint.h"
#include "CCircle.h"

bool CCircle::valid_circle(CPoint center, double radious) {
	return (radious > 0);
}

CCircle::CCircle() {
	// set default with center(0 , 0) and radious = 1
	m_center = new CPoint(0, 0);
	m_radious = 1;
}

CCircle::CCircle(const CCircle& c) : m_center(c.m_center), m_radious(c.m_radious) {}

CCircle::CCircle(double center_x, double center_y, double radious) {
	if (valid_circle(CPoint(center_x, center_y), radious)) {
		m_center = new CPoint(center_x, center_y);
		m_radious = radious;
	}
	else {
		//set default circle
		m_center = new CPoint(0, 0);
		m_radious = 1;
	}
}

void CCircle::set_center(CPoint* value) {
	delete m_center;
	m_center = value;
}

void CCircle::set_radious(double radious) {
	if (radious > 0)
		m_radious = radious;
}

CCircle::~CCircle() {
	if (m_center) delete m_center;
	m_center = NULL;
	m_radious = 0;
}