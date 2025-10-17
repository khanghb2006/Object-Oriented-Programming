#pragma once

class CPoint {
private:
	double m_x;
	double m_y;
public:
	CPoint();
	CPoint(const CPoint& p);
	CPoint(double x, double y);
	double get_x();
	double get_y();
	void set_x(double new_x);
	void set_y(double new_y);
	bool is_overlap(CPoint other);
	~CPoint();
}; 
