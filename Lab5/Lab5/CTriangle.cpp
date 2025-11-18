#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// include header files
#include "CPoint.h"
#include "CTriangle.h"

CTriangle* CTriangle::Parse(std::string line, std::string seperator) {
	// lamda to check valid characters
	auto valid = [](char x) {
		return (isdigit(x) || x == '-' || x == '.');
		};

	std::vector<double> tokens;
	std::string valid_sub;

	while (line.find(seperator) != std::string::npos) {
		// get substring before seperator
		std::string sub = line.substr(0, line.find(seperator));

		// get valid characters only
		valid_sub = "";
		std::copy_if(sub.begin(), sub.end(), std::back_inserter(valid_sub), valid);
		double x = std::stod(valid_sub);
		tokens.push_back(x);
		line = line.substr(line.find(seperator) + seperator.size(), std::string::npos);
	}

	// get the last token
	valid_sub = "";
	std::copy_if(line.begin(), line.end(), std::back_inserter(valid_sub), valid);
	double x = std::stod(valid_sub);
	tokens.push_back(x);
	return new CTriangle(CPoint(tokens[0] , tokens[1]) , CPoint(tokens[2] , tokens[3]) , CPoint(tokens[4] , tokens[5]));
}

CTriangle::CTriangle(CPoint A, CPoint B, CPoint C) {
	if (!A.is_overlap(B) && !B.is_overlap(C) && !A.is_overlap(C)) {
		m_A = new CPoint(A);
		m_B = new CPoint(B);
		m_C = new CPoint(C);
	}
	else {
		// set default value
		m_A = new CPoint(1, 1);
		m_B = new CPoint(1, 2);
		m_C = new CPoint(4, 2);
	}
}

void CTriangle::set_A(CPoint new_A) {
	if (!new_A.is_overlap(*m_B) && !new_A.is_overlap(*m_C)) {
		delete m_A;
		m_A = new CPoint(new_A);
	}
}

void CTriangle::set_B(CPoint new_B) {
	if (!new_B.is_overlap(*m_C) && !new_B.is_overlap(*m_A)) {
		delete m_B;
		m_B = new CPoint(new_B);
	}
}

void CTriangle::set_C(CPoint new_C) {
	if (!new_C.is_overlap(*m_A) && !new_C.is_overlap(*m_B)) {
		delete m_C;
		m_C = new CPoint(new_C);
	}
}

CTriangle::~CTriangle() {
	if (m_A) delete m_A, m_A = nullptr;
	if (m_B) delete m_B, m_B = nullptr;
	if (m_C) delete m_C, m_C = nullptr;
}