#include "CPoint.h"
#include "CLine.h"


//check if A diffrent from B
bool CLine::is_valid_line(CPoint Start, CPoint End) {
	// the line is valid if Start not overlap with End
	return (Start.is_overlap(End) == false);
}

CLine::CLine() {
	// set to valid line with A(0;0) and B(0;1) so A is different from B
	m_start = CPoint(0, 0);
	m_end = CPoint(0, 1);
}

CLine::CLine(const CLine& l) {
	m_start = l.m_start;
	m_end = l.m_end;
}

CLine::CLine(CPoint Start, CPoint End) {
	if (is_valid_line(Start, End)) {
		m_start = Start;
		m_end = End;
	}
	else {
		// default line
		m_start = CPoint(0, 0);
		m_end = CPoint(0, 1);
	}
}

CPoint CLine::get_start() {
	return m_start;
}

CPoint CLine::get_end() {
	return m_end;
}

void CLine::set_start(CPoint new_start) {
	if (is_valid_line(new_start, m_end))
		m_start = new_start;
}

void CLine::set_end(CPoint new_end) {
	if (is_valid_line(m_start, new_end))
		m_end = new_end;
}

CLine::~CLine() {}