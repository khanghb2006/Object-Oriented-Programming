#pragma once

class CPoint {
private:
	double m_x;
	double m_y;
	bool overlap(CPoint p);
public:
	CPoint();
	CPoint(const CPoint& p);
	CPoint(double _x, double _y);
	double get_x() { return m_x; }
	double get_y() { return m_y; }
	void set_x(double new_x) { m_x = new_x; }
	void set_y(double new_y) { m_y = new_y; }
	double CalcDist(const CPoint& p);
	bool is_overlap(CPoint p) { return overlap(p); }
	~CPoint();
};
