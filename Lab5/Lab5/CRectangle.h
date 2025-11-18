#pragma once
#include <string>
#include <vector>
#include "CPoint.h"

class CRectangle {
	private:
		CPoint* m_topLeft;
		CPoint* m_bottomRight;

	public:
		static int InstanceCount;
		static CRectangle* Parse(std::string line, std::string seperator);

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
		//Destructor
		~CRectangle();
};