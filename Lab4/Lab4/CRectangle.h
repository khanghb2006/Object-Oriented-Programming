#pragma once
#include <string>
#include "CPoint.h"

class CRectangle {
private:
	CPoint* m_topLeft;
	CPoint* m_bottomRight;

public:
	static int InstanceCount;

public:
	// Constructors
	CRectangle();
	CRectangle(const CRectangle& other);
	CRectangle(CPoint topLeft, CPoint bottomRight);

public:
	// Getters and Setters
	CPoint get_topLeft() { return *m_topLeft; }
	CPoint get_bottomRight() { return *m_bottomRight; }
	void set_topLeft(CPoint& topLeft);
	void set_bottomRight(CPoint& bottomRight);

public:
	std::string ToString() const;
	friend std::ostream& operator << (std::ostream& os, const CRectangle* r);
	friend std::istream& operator >> (std::istream& is, CRectangle& r);

public:
	//Destructor
	~CRectangle();
};