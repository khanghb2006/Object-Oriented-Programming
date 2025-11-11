#pragma once
#include "Cpoint.h"

class CCircle {
public: 
	const int PI = 3.14;
private:
	CPoint* m_center;
	double m_radious;
	bool valid_circle(CPoint center, double radiuos);
public:
	// Constructors
	CCircle();
	CCircle(const CCircle& c);
	CCircle(double center_x, double center_y, double radious);
public:
	// Setters and Getters
	CPoint get_center() { return *m_center; }
	double get_radious() { return m_radious; }
	void set_center(CPoint* value);	
	void set_radious(double new_radious);
public: 
	double Diameter() { return 2 * m_radious; }
	double Perimeter() { return 2 * PI * m_radious; }
	double Area() { return PI * m_radious * m_radious; }
	~CCircle();
};