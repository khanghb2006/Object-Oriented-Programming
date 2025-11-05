#pragma once

class CPoint {
private:
	double m_x;
	double m_y;
public:
	// Constructor
	CPoint() : m_x(0.0), m_y(0.0) {}
	CPoint(const CPoint& p) : m_x(p.m_x), m_y(p.m_y) {}
	CPoint(double x, double y) : m_x(x), m_y(y) {}

	// Destructure
	~CPoint() {
		m_x = m_y = 0;
	}
	
public:
	// Getters and Setters
	double get_x() const { return m_x; }
	double get_y() const { return m_y; }
	void set_x(double x) { m_x = x; }
	void set_y(double y) { m_y = y; }

public:
	// Methods
	double calcDist(const CPoint& other);
	bool is_rectangle(const CPoint& bottomRight) {
		if (m_x >= bottomRight.m_x) return false;
		if (m_y <= bottomRight.m_y) return false;
		return true;
	}
	bool is_overlap(const CPoint& p) {
		return (m_x == p.m_x && m_y == p.m_y);
	}
	
	bool is_triangle(CPoint B, CPoint C);
};