#pragma once
#include "CPoint.h"

class CRectangle {
private:
	CPoint* m_topLeft;
	CPoint* m_bottomRight;
public:
	// Constructure
	CRectangle() : m_topLeft(new CPoint(1 , 1)), m_bottomRight(new CPoint(10, 10)) {}
	CRectangle(const CRectangle& r) :
		m_topLeft(new CPoint(*r.m_topLeft)), m_bottomRight(new CPoint(*r.m_bottomRight)) {}
	CRectangle(CPoint topLeft, CPoint bottomRight);

	// Destructor
	~CRectangle() {
		delete m_topLeft;
		delete m_bottomRight;
		m_topLeft = nullptr;
		m_bottomRight = nullptr;
	}
public:
	// Getters and Setters
	CPoint get_topLeft() { return *m_topLeft; }
	CPoint get_bottomRight() { return *m_bottomRight; }
	void set_topLeft(CPoint new_topLeft);
	void set_bottomRight(CPoint new_bottomRight);

public:
	// Methods
	double Perimeter();
	double Area();
};