#pragma once
#include "Cpoint.h"

class CLine {
private:
	CPoint m_start;
	CPoint m_end;
public:
	CLine();
	CLine(const CLine& l);
	CLine(double start_x , double start_y , double end_x , double end_y);
	CPoint get_start() { return m_start; }
	CPoint get_end() { return m_end; }
	void set_start(double start_x , double start_y);
	void set_end(double end_x , double end_y);
	~CLine();
};