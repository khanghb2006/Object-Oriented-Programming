#pragma once
#include "CPoint.h"

class CRectangle {
private:
	CPoint m_topLeft;
	CPoint m_bottomRight;
	bool is_valid_rectangle(CPoint topLeft, CPoint bottomRight);
public:
	CRectangle();
	CRectangle(const CRectangle& r);
	CRectangle(CPoint topLeft, CPoint bottomRight);
	CPoint get_topLeft();
	CPoint get_bottomRight();
	void set_topLeft(CPoint new_topLeft);
	void set_bottomRight(CPoint new_bottomRight);
	~CRectangle();
};