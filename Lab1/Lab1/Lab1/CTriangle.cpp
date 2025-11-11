#include <iostream>
#include "CPoint.h"
#include "CTriangle.h"

bool CTriangle::valid(CPoint a, CPoint b, CPoint c) {
	// Use CCW to check valid rectangle
	CPoint AB(b.get_x() - a.get_x(), b.get_y() - a.get_y());
	CPoint AC(c.get_x() - a.get_x(), c.get_y() - a.get_y());

	return ((AB.get_x() * AC.get_y() - AB.get_y() * AC.get_x()) != 0);
}

bool CTriangle::valid_triangle(CPoint a, CPoint b, CPoint c) {
	return valid(a, b, c);
}

CTriangle::CTriangle() :
	m_a(CPoint(0, 0)), m_b(CPoint(0, 1)), m_c(CPoint(1, 0)) {}

CTriangle::CTriangle(const CTriangle& t) :
	m_a(t.m_a), m_b(t.m_b), m_c(t.m_c) {}

CTriangle::CTriangle(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y) {
	if (valid_triangle(CPoint(a_x, a_y), CPoint(b_x, b_y), CPoint(c_x, c_y))) {
		m_a = CPoint(a_x, a_y);
		m_b = CPoint(b_x, b_y);
		m_c = CPoint(c_x, c_y);
	}
	else {
		//set default triangle
		m_a = CPoint(0, 0);
		m_b = CPoint(0, 1);
		m_c = CPoint(1, 0);
	}
}

void CTriangle::set_A(double a_x, double a_y) {
	if (valid_triangle(CPoint(a_x , a_y) , m_b , m_c))
		m_a = CPoint(a_x, a_y);
}

void CTriangle::set_B(double b_x, double b_y) {
	if (valid_triangle(m_a , CPoint(b_x , b_y) , m_c))
		m_b = CPoint(b_x, b_y);
}

void CTriangle::set_C(double c_x, double c_y) {
	if (valid_triangle(m_a , m_b, CPoint(c_x , c_y)))
		m_c = CPoint(c_x, c_y);
}

CTriangle::~CTriangle() {}