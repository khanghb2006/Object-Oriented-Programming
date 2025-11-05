#include <iostream>
#include "CPoint.h"
#include "CRectangle.h"

int CRectangle::InstanceCount = 0;

CRectangle::CRectangle() : m_topLeft(new CPoint(0, 1)), m_bottomRight(new CPoint(1, 0)) {
	InstanceCount++;
}

CRectangle::CRectangle(const CRectangle& other) : 
	m_topLeft(new CPoint(*other.m_topLeft)), m_bottomRight(new CPoint(*other.m_bottomRight)) {
		InstanceCount++;
}

CRectangle::CRectangle(CPoint topLeft, CPoint bottomRight) : 
	m_topLeft(new CPoint(topLeft)), m_bottomRight(new CPoint(bottomRight)) {
		InstanceCount++;
}

void CRectangle::set_topLeft(CPoint& topLeft) {
	if (topLeft.is_overlap(*m_bottomRight)) return;
	*m_topLeft = topLeft;
}

void CRectangle::set_bottomRight(CPoint& bottomRight) {
	if (bottomRight.is_overlap(*m_topLeft)) return;
	*m_bottomRight = bottomRight;
}
