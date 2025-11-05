#include <iostream>
#include "Cpoint.h"
#include "CLine.h"

CLine::CLine() {
	// set default line with points (0,0) and (0,1);
	m_start = CPoint(0, 0);
	m_end = CPoint(0, 1);
}

CLine::CLine(const CLine& l) {
	m_start = l.m_start;
	m_end = l.m_end;
}

CLine::CLine(double start_x , double start_y , double end_x , double end_y) {
	CPoint _start(start_x, start_y);
	CPoint _end(end_x, end_y);
	if (!_start.is_overlap(_end)) {
		m_start = _start;
		m_end = _end;
	}
	else {
		//set default line 
		m_start = CPoint(0, 0);
		m_end = CPoint(0, 1);
	}
}

void CLine::set_start(double start_x , double start_y) {
	CPoint new_start(start_x, start_y);	
	if (!new_start.is_overlap(m_end))
		m_start = new_start;
}

void CLine::set_end(double end_x , double end_y) {
	CPoint new_end(end_x, end_y);
	if (!m_start.is_overlap(new_end))
		m_end = new_end;
}

CLine::~CLine() {}