#pragma once 
#include "CPoint.h"

class CLine {
private:
	CPoint m_start;
	CPoint m_end;
	bool is_valid_line(CPoint Start, CPoint End);
public:
	CLine();
	CLine(const CLine& l);
	CLine(CPoint start, CPoint end);
	CPoint get_start();
	CPoint get_end();
	void set_start(CPoint new_start);
	void set_end(CPoint new_end);
	~CLine();
};