#include <iostream>
#include "CRectangle.h"


CRectangle::CRectangle(CPoint topLeft, CPoint bottomRight) {
	if (!topLeft.is_rectangle(bottomRight)) {
		//set to default value
		m_topLeft = new CPoint(1, 1);
		m_bottomRight = new CPoint(10, 10);
	}
	else {
		m_topLeft = new CPoint(topLeft);
		m_bottomRight = new CPoint(bottomRight);
	}
}

void CRectangle::set_topLeft(CPoint new_topLeft) {
	if (new_topLeft.is_rectangle(*m_bottomRight)) {
		delete m_topLeft;
		m_topLeft = new CPoint(new_topLeft);
	}
}

void CRectangle::set_bottomRight(CPoint new_bottomRight) {
	if (m_topLeft->is_rectangle(new_bottomRight)) {
		delete m_bottomRight;
		m_bottomRight = new CPoint(new_bottomRight);
	}
}

double CRectangle::Perimeter() {
	double dh = m_topLeft->get_y() - m_bottomRight->get_y();
	double dl = m_bottomRight->get_x() - m_topLeft->get_x();
	return 2.00 * (dh + dl);
}

double CRectangle::Area() {
	double dh = m_topLeft->get_y() - m_bottomRight->get_y();
	double dl = m_bottomRight->get_x() - m_topLeft->get_x();
	return (long double)dh * dl;
}