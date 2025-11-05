#pragma once
#include <iostream>
#include "CPoint.h"

class CTriangle {
private:
	CPoint* m_A;
	CPoint* m_B;
	CPoint* m_C;
public:
	// Constructure
	CTriangle() : m_A(new CPoint(1, 1)), m_B(new CPoint(1, 2)), m_C(new CPoint(4, 2)) {}
	CTriangle(const CTriangle& c) :
		m_A(new CPoint(*c.m_A)), m_B(new CPoint(*c.m_B)), m_C(new CPoint(*c.m_C)) {}
	CTriangle(CPoint A, CPoint B, CPoint C);

	// Destructure
	~CTriangle() {
		delete m_A; m_A = NULL;
		delete m_B; m_B = NULL;
		delete m_C; m_C = NULL;
	}

public:
	// Getters and Setters
	CPoint get_A() { return *m_A; }
	CPoint get_B() { return *m_B; }
	CPoint get_C() { return *m_C; }

	void set_A(CPoint new_A);
	void set_B(CPoint new_B);
	void set_C(CPoint new_C);

public:
	// Methods
	double Perimeter();
	double Area();
};