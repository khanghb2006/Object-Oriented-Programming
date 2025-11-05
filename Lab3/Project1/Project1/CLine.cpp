#include <iostream>
#include "CLine.h"
#include "CPoint.h"

int CLine::InstanceCount = 0;

CLine::CLine() : m_start(new CPoint(0 , 0)) , m_end(new CPoint(0 , 1)) {
	InstanceCount++;
}

CLine::CLine(const CLine& other) : m_start(new CPoint(*other.m_start)) , m_end(new CPoint(*other.m_end)) {
	InstanceCount++;
}

CLine::CLine(CPoint start, CPoint end) : m_start(new CPoint(start)) , m_end(new CPoint(end)) {
	InstanceCount++;
}

void CLine::set_start(CPoint& start) {
	if (start.is_overlap(*m_end)) return;
	*m_start = start;
}

void CLine::set_end(CPoint& end) {
	if (m_start->is_overlap(end)) return;
	*m_end = end;
}

double CLine::calcLength() {
	return CPoint::calcDistance(*m_start, *m_end);
}
