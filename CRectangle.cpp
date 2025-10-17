#include "CPoint.h"
#include "CRectangle.h"

bool CRectangle::is_valid_rectangle(CPoint topLeft, CPoint bottomRight) {
	// invalid if topLeft is overlap with bottomRight
	if (topLeft.is_overlap(bottomRight))
		return false;
	
	// invalid if topLeft.m_x > bottomRight.m_x
	if (topLeft.get_x() >= bottomRight.get_x()) 
		return false;

	// invalid if topLeft.m_y <= bottomRight.m_y
	if (topLeft.get_y() <= bottomRight.get_y())
		return false;
	return true;
}

CRectangle::CRectangle() {
	// set to default valid rectangle 
	m_topLeft = CPoint(0 , 1);
	m_bottomRight = CPoint(1 , 0);
}

CRectangle::CRectangle(const CRectangle& r) {
	m_topLeft = r.m_topLeft;
	m_bottomRight = r.m_bottomRight;
}

CRectangle::CRectangle(CPoint topLeft, CPoint bottomRight) {
	if (is_valid_rectangle(topLeft, bottomRight)) {
		m_topLeft = topLeft;
		m_bottomRight = bottomRight;
	}
	else {
		// set default valid rectangle
		m_topLeft = CPoint(0, 1);
		m_bottomRight = CPoint(1, 0);
	}
}

CPoint CRectangle::get_topLeft() {
	return m_topLeft;
}

CPoint CRectangle::get_bottomRight() {
	return m_bottomRight;
}

void CRectangle::set_topLeft(CPoint new_topLeft) {
	if (is_valid_rectangle(new_topLeft, m_bottomRight))
		m_topLeft = new_topLeft;
}

void CRectangle::set_bottomRight(CPoint new_bottomRight) {
	if (is_valid_rectangle(m_topLeft, new_bottomRight))
		m_bottomRight = new_bottomRight;
}

CRectangle::~CRectangle() {}