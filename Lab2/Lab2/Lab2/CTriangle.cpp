#include <iostream>
#include "CPoint.h"
#include "CTriangle.h"

CTriangle::CTriangle(CPoint A, CPoint B, CPoint C) {
	if (A.is_triangle(B, C)) {
		m_A = new CPoint(A);
		m_B = new CPoint(B);
		m_C = new CPoint(C);
	}
	else {
		// set default value
		m_A = new CPoint(1, 1);
		m_B = new CPoint(1, 2);
		m_C = new CPoint(4, 2);
	}
}

void CTriangle::set_A(CPoint new_A) {
	if (new_A.is_triangle(*m_B, *m_C)) {
		delete m_A;
		m_A = new CPoint(new_A);
	}
}

void CTriangle::set_B(CPoint new_B) {
	if (new_B.is_triangle(*m_C, *m_C)) {
		delete m_B;
		m_B = new CPoint(new_B);
	}
}

void CTriangle::set_C(CPoint new_C) {
	if (new_C.is_triangle(*m_B, *m_A)) {
		delete m_C;
		m_C = new CPoint(new_C);
	}
}

double CTriangle::Perimeter() {
	double d1 = m_A->calcDist(*m_B);
	double d2 = m_A->calcDist(*m_C);
	double d3 = m_B->calcDist(*m_C);
	return d1 + d2 + d3;
}

double CTriangle::Area() {
	double d1 = m_A->calcDist(*m_B);
	double d2 = m_A->calcDist(*m_C);
	double d3 = m_B->calcDist(*m_C);
	double p = (d1 + d2 + d3) / 2; // Half Perimeter

	// Use Heron Fomular
	return sqrt(p * (p - d1) * (p - d2) * (p - d3));
}