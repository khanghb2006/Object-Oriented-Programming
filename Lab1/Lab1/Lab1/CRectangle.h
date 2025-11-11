#pragma once
#include "Cpoint.h"

class CRectangle {
private:
	CPoint m_topLeft;
	CPoint m_bottomRight;
	bool valid_rectangle(CPoint topLeft, CPoint bottomRight);
public:
	CRectangle();
	CRectangle(const CRectangle& r);
	CRectangle(double topLeft_x, double topLeft_y, double bottomRight_x, double bottomRight_y);
	CPoint get_topLeft() { return m_topLeft; }
	CPoint get_bottomRight() { return m_bottomRight; }
	void set_topLeft(double new_topLeft_x , double new_topLeft_y);
	void set_bottomRight(double new_bottomRight_x, double new_bottomRight_y);
	~CRectangle();
};