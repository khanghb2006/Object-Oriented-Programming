#pragma once
#include "CPoint.h"

class CTriangle {
private:
	CPoint m_a;
	CPoint m_b;
	CPoint m_c;
	bool valid(CPoint a , CPoint b, CPoint c);
public:
	CTriangle();
	CTriangle(const CTriangle& t);
	CTriangle(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y);
	CPoint get_A() { return m_a; }
	CPoint get_B() { return m_b; }
	CPoint get_C() { return m_c; }
	bool valid_triangle(CPoint a, CPoint b, CPoint c);
	void set_A(double a_x, double a_y);
	void set_B(double b_x, double b_y);
	void set_C(double c_x, double c_y);
	~CTriangle();
};