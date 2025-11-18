#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include "CPoint.h"

int CPoint::InstanceCount = 0;

CPoint* CPoint::Parse(std::string line, std::string seperator) {
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
    return new CPoint(tokens[0], tokens[1]);
}

//constuctors

CPoint::CPoint() : m_x(0), m_y(0) {
    InstanceCount++;
}

CPoint::CPoint(const CPoint& other) : m_x(other.m_x), m_y(other.m_y) {
    InstanceCount++;
}

CPoint::CPoint(double x, double y) : m_x(x), m_y(y) {
    InstanceCount++;
}

CPoint::~CPoint() {
    m_x = 0;
    m_y = 0;
    --InstanceCount;
}