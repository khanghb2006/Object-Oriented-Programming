#pragma once

class CPoint {
public:
	double m_x;
	double m_y;

public:
	static int InstanceCount;

public:
	//Constructors
	CPoint();
	CPoint(const CPoint& other);
	CPoint(double x, double y);

public: 
	// Getters and Setters
	double get_x() { return m_x;}
	double get_y() { return m_y; }
	void set_x(double x) { m_x = x; }
	void set_y(double y) { m_y = y; }

public:
	// Methods
	bool is_overlap(CPoint& b) {
		return (m_x == b.m_x) && (m_y == b.m_y);
	}
	double calcDist(CPoint& b);
	static double calcDistance(CPoint& a, CPoint& b);

public:
	// Destructor
	~CPoint() {
		m_x = m_y = 0;
		InstanceCount--;
	}
};