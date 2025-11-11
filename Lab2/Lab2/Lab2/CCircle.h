#pragma once
#include "CPoint.h"

class CCircle {
public:
	const double PI = 3.14;
private:
	CPoint* m_center;
	double m_radius;
public:
	// Constructor
	CCircle(): m_center(new CPoint(0, 0)), m_radius(1) {}
	CCircle(const CCircle& other) :
		m_center(new CPoint(*other.m_center)), m_radius(other.m_radius) {}
	CCircle(CPoint* center, double radius);

	// Constructure
	~CCircle() {
		delete m_center;
		m_center = nullptr;
		m_radius = 0;
	}

public:
	// Getters and Setters
	CPoint get_center() { return *m_center; }
	double get_radius() { return m_radius;  }
	void set_center(CPoint &new_center);
	void set_radius(double new_radius);

public: 
	double Diameter() { return 2.00 * m_radius; }
	double Perimeter() { return 2.00 * PI * m_radius; }
	double Area() { return PI * m_radius * m_radius; }
};