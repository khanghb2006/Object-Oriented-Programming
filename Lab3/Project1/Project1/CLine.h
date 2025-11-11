#pragma once
#include "CPoint.h"

class CLine {
private:
	CPoint *m_start;
	CPoint *m_end;

public:
	static int InstanceCount;

public:
	// Constructors
	CLine();
	CLine(const CLine& other);
	CLine(CPoint start, CPoint end);

public:	
	// Getters and Setters
	CPoint get_start() { return *m_start; }
	CPoint get_end() { return *m_end; }
	void set_start(CPoint& start);
	void set_end(CPoint& end);

public:
	//Methods
	double calcLength();

public:
	// Destructure
	~CLine() {
		delete m_start;
		m_start = nullptr;
		delete m_end;
		m_end = nullptr;
		--InstanceCount;
	}
};