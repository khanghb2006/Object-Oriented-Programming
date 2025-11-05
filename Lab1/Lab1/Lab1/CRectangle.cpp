#include <iostream>
#include "CPoint.h"
#include "CRectangle.h"

bool CRectangle::valid_rectangle(CPoint topLeft, CPoint bottomRight) {
	if (topLeft.is_overlap(bottomRight)) return false;
	if (topLeft.get_x() >= bottomRight.get_x()) return false;
	if (topLeft.get_y() <= bottomRight.get_y()) return false;
	return true;
}

CRectangle::CRectangle() {
	//set default rectangle with topLeft (0,1) and bottomRight (1,0);
	m_topLeft = CPoint(0, 1);
	m_bottomRight = CPoint(1, 0);
}

CRectangle::CRectangle(const CRectangle& r) : 
	m_topLeft(r.m_topLeft) , m_bottomRight(r.m_bottomRight) {}

CRectangle::CRectangle(double topLeft_x, double topLeft_y, double bottomRight_x, double bottomRight_y) {
	if (valid_rectangle(CPoint(topLeft_x, topLeft_y), CPoint(bottomRight_x, bottomRight_y))) {
		m_topLeft = CPoint(topLeft_x, topLeft_y);
		m_bottomRight = CPoint(bottomRight_x, bottomRight_y);
	}
	else {
		// set default rectangle
		m_topLeft = CPoint(0, 1);
		m_bottomRight = CPoint(1, 0);
	}
}

void CRectangle::set_topLeft(double new_topLeft_x, double new_topLeft_y) {
	CPoint new_topLeft(new_topLeft_x, new_topLeft_y);
	if (valid_rectangle(new_topLeft , m_bottomRight))
		m_topLeft = new_topLeft;
}

void CRectangle::set_bottomRight(double new_bottomRight_x, double new_bottomRight_y) {
	CPoint new_bottomRight(new_bottomRight_x, new_bottomRight_y);
	if (valid_rectangle(m_topLeft, new_bottomRight))
		m_bottomRight = new_bottomRight;
}

CRectangle::~CRectangle() {}